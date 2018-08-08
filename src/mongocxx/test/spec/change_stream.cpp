// Copyright 2018-present MongoDB Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <fstream>
#include <iostream>
#include <string>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <bsoncxx/document/value.hpp>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/stdx/string_view.hpp>
#include <bsoncxx/string/to_string.hpp>
#include <bsoncxx/test_util/catch.hh>
#include <mongocxx/change_stream.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/exception/operation_exception.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/test/spec/operation.hh>
#include <mongocxx/test_util/client_helpers.hh>
#include <mongocxx/uri.hpp>

namespace {
using namespace mongocxx;
using namespace bsoncxx;
using namespace bsoncxx::string;
using namespace spec;
using namespace test_util;

class test_ctx {
   public:
    test_ctx(document::view test_specs_view, class client& client) : client(client) {
        db1_name = to_string(test_specs_view["database_name"].get_utf8().value);
        db2_name = to_string(test_specs_view["database2_name"].get_utf8().value);
        coll1_name = to_string(test_specs_view["collection_name"].get_utf8().value);
        coll2_name = to_string(test_specs_view["collection2_name"].get_utf8().value);
        client[db1_name].drop();
        client[db2_name].drop();
        using namespace bsoncxx::builder::basic;
        client[db1_name][coll1_name].insert_one(make_document());
        client[db2_name][coll2_name].insert_one(make_document());
    }

    change_stream make_change_stream(document::view test_view) {
        pipeline pipeline{};
        if (test_view["pipeline"]) {
            pipeline = build_pipeline(test_view["pipeline"].get_array().value);
        }

        auto target = std::string(test_view["target"].get_utf8().value);
        if (target == "collection") {
            return client[db1_name][coll1_name].watch(pipeline);
        } else if (target == "database") {
            return client[db1_name].watch(pipeline);
        } else {
            return client.watch(pipeline);
        }
    }

    void run_operations(document::view test_view) {
        /* run all operations in the test's "operations" field */
        if (test_view["operations"]) {
            auto test_operations = test_view["operations"].get_array().value;
            for (auto&& operation : test_operations) {
                std::string operation_name = to_string(operation["name"].get_utf8().value);
                std::cout << "running operation " << operation_name << std::endl;
                auto dbname = to_string(operation["database"].get_utf8().value);
                auto collname = to_string(operation["collection"].get_utf8().value);
                auto coll = client[dbname][collname];
                get_test_runners()[operation_name](&coll, operation.get_document().value);
            }
        }
    }

   private:
    // TODO: rename to use _
    std::string db1_name;
    std::string db2_name;
    std::string coll1_name;
    std::string coll2_name;
    class client& client;
};

void run_change_stream_tests_in_file(const std::string& test_path, client& global_client) {
    INFO("Test path: " << test_path);
    auto test_specs = test_util::parse_test_file(test_path);
    REQUIRE(test_specs);
    auto test_specs_view = test_specs->view();
    std::string server_version = test_util::get_server_version(global_client);
    test_ctx ctx{test_specs_view, global_client};

    // This follows the sketch laid out in the change stream spec tests readme:
    // https://github.com/mongodb/specifications/tree/master/source/change-streams/tests#spec-test-runner
    for (auto&& test_el : test_specs_view["tests"].get_array().value) {
        auto test_view = test_el.get_document().value;

        INFO("Test case " << to_string(test_view["description"].get_utf8().value));
        if (test_view["description"].get_utf8().value.compare(
                "Change Stream should error when an invalid aggregation stage is passed in") == 0) {
            WARN("Skipping test with invalid pipeline stages. The C++ driver cannot test them.");
            continue;
        }

        if (test_view["minServerVersion"]) {
            auto min_server_version = to_string(test_view["minServerVersion"].get_utf8().value);
            if (test_util::compare_versions(server_version, min_server_version) < 0) {
                return;
            }
        }

        if (test_view["maxServerVersion"]) {
            auto max_server_version = to_string(test_view["maxServerVersion"].get_utf8().value);
            if (test_util::compare_versions(server_version, max_server_version) > 0) {
                return;
            }
        }

        if (test_view["topology"]) {
            auto required_topologies = test_view["topology"].get_array().value;
            auto topology = test_util::get_topology(global_client);
            bool found = false;
            for (auto&& el : required_topologies) {
                if (std::string(el.get_utf8().value) == topology) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                WARN("Skipping - supported topologies are: " + to_json(required_topologies));
                continue;
            }
        }

        // TODO: begin monitoring all APM events.
        change_stream cs = ctx.make_change_stream(test_view);
        ctx.run_operations(test_view);
        std::vector<document::value> changes;

        auto expected_result = test_view["result"].get_document().value;
        bool had_error = false;
        try {
            for (auto&& change : cs) {
                /* store a copy of the event. */
                changes.emplace_back(document::value(change));
            }
        } catch (operation_exception& oe) {
            REQUIRE(expected_result["error"]);
            auto actual_error = oe.raw_server_error();
            REQUIRE(actual_error);
            REQUIRE(matches(actual_error->view(), expected_result["error"].get_document().value));
            had_error = true;
        };

        // TODO: remove
        for (auto&& change : changes) {
            std::cout << to_json(change) << std::endl;
        }

        if (!had_error) {
            REQUIRE(expected_result["success"]);
            for (auto&& expected_change : expected_result["success"].get_array().value) {
                auto expected_change_view = expected_change.get_document().value;
                bool found = false;

                for (auto&& change : changes) {
                    if (matches(change.view(), expected_change_view)) {
                        found = true;
                        break;
                    }
                }

                REQUIRE(found);
            }
        }
    }
}

TEST_CASE("Change stream spec tests", "[change_stream_spec]") {
    instance::current();
    client global_client{uri{}};
    char* change_stream_tests_path = std::getenv("CHANGE_STREAM_TESTS_PATH");
    if (!change_stream_tests_path) {
        FAIL("environment variable CHANGES_STREAM_TESTS_PATH not set");
    }

    std::string path = change_stream_tests_path;
    if (path.back() == '/') {
        path.pop_back();
    }

    std::ifstream test_files{path + "/test_files.txt"};
    REQUIRE(test_files.good());
    std::string test_file;
    while (std::getline(test_files, test_file)) {
        run_change_stream_tests_in_file(path + "/" + test_file, global_client);
    }
}
}  // namespace
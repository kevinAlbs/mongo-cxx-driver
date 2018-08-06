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
#include <bsoncxx/stdx/string_view.hpp>
#include <bsoncxx/string/to_string.hpp>
#include <bsoncxx/test_util/catch.hh>
#include <mongocxx/change_stream.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/test_util/client_helpers.hh>
#include <mongocxx/uri.hpp>

namespace {
using namespace mongocxx;
using namespace bsoncxx;
using namespace bsoncxx::string;

document::value run_insert_one_test(collection* coll, document::view operation) {
    document::view arguments = operation["arguments"].get_document().value;
    document::view document = arguments["document"].get_document().value;
    auto result = builder::basic::document{};
    auto insert_one_result = coll->insert_one(document);
    types::value inserted_id{types::b_null{}};

    if (insert_one_result) {
        inserted_id = insert_one_result->inserted_id();
    }

    using namespace bsoncxx::builder::basic;

    result.append(builder::basic::kvp("result", [inserted_id](builder::basic::sub_document subdoc) {
        subdoc.append(builder::basic::kvp("insertedId", inserted_id));
    }));

    return result.extract();
}

std::map<std::string, std::function<document::value(collection*, document::view)>>
    crud_test_runners = {{"insertOne", run_insert_one_test}};

class test_ctx {
   public:
    test_ctx(bsoncxx::document::view test_specs_view, class client& client) : client(client) {
        db1_name = to_string(test_specs_view["database_name"].get_utf8().value);
        db2_name = to_string(test_specs_view["database2_name"].get_utf8().value);
        coll1_name = to_string(test_specs_view["collection_name"].get_utf8().value);
        coll2_name = to_string(test_specs_view["collection2_name"].get_utf8().value);
        client[db1_name].drop();
        client[db2_name].drop();
        /* create the collections by inserting. */
        options::insert insert_opts;
        write_concern wc;
        wc.majority(std::chrono::milliseconds(30000));
        insert_opts.write_concern(wc);

        using namespace bsoncxx::builder::basic;
        client[db1_name][coll1_name].insert_one(make_document(), insert_opts);
        client[db2_name][coll2_name].insert_one(make_document(), insert_opts);
    }

    pipeline build_pipeline(bsoncxx::array::view pipeline_docs) {
        pipeline pipeline{};

        for (auto&& element : pipeline_docs) {
            bsoncxx::document::view document = element.get_document();

            if (document["$match"]) {
                pipeline.match(document["$match"].get_document().value);
            } else if (document["$out"]) {
                pipeline.out(bsoncxx::string::to_string(document["$out"].get_utf8().value));
            } else if (document["$sort"]) {
                pipeline.sort(document["$sort"].get_document().value);
            } else {
                REQUIRE(false);
            }
        }

        return pipeline;
    }

    change_stream make_change_stream(bsoncxx::document::view test_view) {
        auto target = std::string(test_view["target"].get_utf8().value);

        pipeline pipeline{};

        if (test_view["pipeline"]) {
            pipeline = build_pipeline(test_view["pipeline"].get_array().value);
        }

        if (target == "collection") {
            return client[db1_name][coll1_name].watch(pipeline);
        } else if (target == "database") {
            return client[db1_name].watch(pipeline);
        } else {
            return client.watch(pipeline);
        }
    }

    void run_operations(bsoncxx::document::view test_view) {
        /* run all operations in the test's "operations" field */
        if (test_view["operations"]) {
            auto test_operations = test_view["operations"].get_array().value;
            for (auto&& operation : test_operations) {
                std::string operation_name = to_string(operation["name"].get_utf8().value);
                std::cout << "running operation " << operation_name << std::endl;
                auto dbname = to_string(operation["database"].get_utf8().value);
                auto collname = to_string(operation["collection"].get_utf8().value);
                auto coll = client[dbname][collname];
                if (crud_test_runners.find(operation_name) == crud_test_runners.end()) {
                    std::cout << "unsupported operation" << std::endl;
                }
                crud_test_runners[operation_name](&coll, operation.get_document().value);
            }
        }
    }

    std::string db1_name;
    std::string db2_name;
    std::string coll1_name;
    std::string coll2_name;
    client& client;
};

void run_change_stream_tests_in_file(const std::string& test_path,
                                     mongocxx::client& global_client) {
    INFO("Test path: " << test_path);
    auto test_specs = test_util::parse_test_file(test_path);
    REQUIRE(test_specs);
    auto test_specs_view = test_specs->view();
    std::string server_version = test_util::get_server_version(global_client);
    auto coll = global_client["db"]["collection"];
    auto cursor = coll.find({});
    test_ctx ctx{test_specs_view, global_client};

    // this follows the sketch laid out in the change stream spec tests readme:
    // https://github.com/mongodb/specifications/tree/master/source/change-streams/tests#spec-test-runner
    for (auto&& test_el : test_specs_view["tests"].get_array().value) {
        bsoncxx::document::view test_view = test_el.get_document().value;

        std::cout << " test " << to_string(test_view["description"].get_utf8().value) << std::endl;

        if (test_view["description"].get_utf8().value.compare(
                "Change Stream should error when an invalid aggregation stage is passed in") == 0) {
            WARN("skipping test with invalid pipeline stages. The C++ driver cannot test them.");
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
                WARN("skipping - supported topologies are: " +
                     bsoncxx::to_json(required_topologies));
            }
        }

        // TODO: begin monitoring all APM events.
        change_stream cs = ctx.make_change_stream(test_view);
        ctx.run_operations(test_view);

        std::vector<document::value> events;
        for (auto&& event : cs) {
            /* store a copy of the event. */
            events.push_back(document::value(event));
        }



        for (auto&& event : events) {
            std::cout << bsoncxx::to_json(event) << std::endl;
        }
        // check_expectations ();
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
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

#include <bsoncxx/stdx/optional.hpp>
#include <bsoncxx/stdx/string_view.hpp>
#include <bsoncxx/test_util/catch.hh>
#include <mongocxx/client.hpp>
#include <mongocxx/test_util/client_helpers.hh>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/string/to_string.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/document/value.hpp>
#include <bsoncxx/document/view.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>
#include <mongocxx/change_stream.hpp>

namespace {
using namespace mongocxx;
using namespace bsoncxx;
using namespace bsoncxx::string;
using namespace bsoncxx::builder::basic;

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

change_stream make_change_stream (client& global_client, bsoncxx::document::view test_view) {
    auto target = std::string(test_view["target"].get_utf8().value);

    pipeline pipeline{};

    if (test_view["pipeline"]) {
        // TODO: we can't add an invalid pipeline to our watch helper.
        pipeline = build_pipeline (test_view["pipeline"].get_array().value);
    }

    if (target == "collection") {
        return global_client["database_name"]["collection_name"].watch(pipeline);
    } else if (target == "database") {
        return global_client["database_name"].watch(pipeline);
    } else {
        return global_client.watch(pipeline);
    }
}

void run_change_stream_tests_in_file(const std::string& test_path, mongocxx::client& global_client) {
    INFO("Test path: " << test_path);
    auto test_specs = test_util::parse_test_file(test_path);
    REQUIRE(test_specs);
    auto test_specs_view = test_specs->view();
    std::string server_version = test_util::get_server_version(global_client);



    // this follows the sketch laid out in the change stream spec tests readme:
    // https://github.com/mongodb/specifications/tree/master/source/change-streams/tests#spec-test-runner
    for (auto&& test_el : test_specs_view["tests"].get_array().value) {
        bsoncxx::document::view test_view = test_el.get_document().value;

        if (test_view["description"].get_utf8().value.compare("Change Stream should error when an invalid aggregation stage is passed in") == 0) {
            WARN ("skipping test with invalid pipeline stages. The C++ driver cannot test them.");
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
                WARN ("skipping - topology needed is " + bsoncxx::to_json(required_topologies));
            }
        }

        global_client["database_name"].drop();
        global_client["database2_name"].drop();
        /* create the collections by inserting. */
        global_client["database_name"]["collection_name"].insert_one(make_document());
        global_client["database2_name"]["collection2_name"].insert_one(make_document());

        // TODO: begin monitoring all APM events.
        change_stream cs = make_change_stream (global_client, test_view);
    }


/*
    auto test_spec_view = test_spec->view();

    std::string server_version = test_util::get_server_version(*global_client);

    if (test_spec_view["minServerVersion"]) {
        std::string min_server_version =
            bsoncxx::string::to_string(test_spec_view["minServerVersion"].get_utf8().value);

        if (test_util::compare_versions(server_version, min_server_version) < 0) {
            return;
        }
    }

    if (test_spec_view["maxServerVersion"]) {
        std::string max_server_version =
            bsoncxx::string::to_string(test_spec_view["maxServerVersion"].get_utf8().value);

        if (test_util::compare_versions(server_version, max_server_version) > 0) {
            return;
        }
    }

    if (test_spec_view[""])

    if (!test_util::is_replica_set(global_client)) {
        WARN("skip: change stream spec tests require replica set");
        return;
    }
*/
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
} // namespace
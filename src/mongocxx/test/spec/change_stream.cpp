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
#include <bsoncxx/test_util/catch.hh>
#include <mongocxx/client.hpp>
#include <mongocxx/test_util/client_helpers.hh>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/string/to_string.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/document/value.hpp>
#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/builder/basic/kvp.hpp>

namespace {
using namespace mongocxx;
using namespace bsoncxx;

void run_change_stream_tests_in_file(const std::string& test_path, mongocxx::client* global_client) {
    INFO("Test path: " << test_path);
    auto test_specs = test_util::parse_test_file(test_path);
    REQUIRE(test_specs);
    auto test_specs_view = test_specs->view();


    (void) global_client;
    for (const auto& test_el : test_specs_view["tests"].get_array().value) {
        std::cout << "looking at test for " << bsoncxx::to_json (test_el.get_document().value) << std::endl;
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
        run_change_stream_tests_in_file(path + "/" + test_file, &global_client);
    }
}
} // namespace
// Copyright 2014-present MongoDB Inc.
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

#include <bsoncxx/private/suppress_deprecation_warnings.hh>

MONGOCXX_LIBMONGOC_SYMBOL(apm_callbacks_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(apm_callbacks_new)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_command_name)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_duration)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_error)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_operation_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_reply)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_request_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_failed_get_server_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_command)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_command_name)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_database_name)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_operation_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_request_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_started_get_server_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_command_name)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_duration)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_operation_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_reply)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_request_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_command_succeeded_get_server_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_changed_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_changed_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_changed_get_new_description)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_changed_get_previous_description)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_changed_get_topology_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_closed_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_closed_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_closed_get_topology_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_failed_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_failed_get_duration)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_failed_get_error)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_failed_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_started_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_started_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_succeeded_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_succeeded_get_duration)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_succeeded_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_heartbeat_succeeded_get_reply)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_opening_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_opening_get_host)
MONGOCXX_LIBMONGOC_SYMBOL(apm_server_opening_get_topology_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_command_failed_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_command_started_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_command_succeeded_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_server_changed_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_server_closed_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_server_heartbeat_failed_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_server_heartbeat_started_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_server_heartbeat_succeeded_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_server_opening_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_topology_changed_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_topology_closed_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_set_topology_opening_cb)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_changed_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_changed_get_new_description)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_changed_get_previous_description)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_changed_get_topology_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_closed_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_closed_get_topology_id)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_opening_get_context)
MONGOCXX_LIBMONGOC_SYMBOL(apm_topology_opening_get_topology_id)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_new)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_bypass_auto_encryption)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_extra)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_keyvault_client)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_keyvault_client_pool)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_keyvault_namespace)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_kms_providers)
MONGOCXX_LIBMONGOC_SYMBOL(auto_encryption_opts_set_schema_map)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_execute)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_get_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_insert_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_new)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_remove_many_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_remove_one_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_replace_one_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_set_bypass_document_validation)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_set_client)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_set_client_session)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_set_collection)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_set_database)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_set_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_update_many_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(bulk_operation_update_one_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(change_stream_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(change_stream_error_document)
MONGOCXX_LIBMONGOC_SYMBOL(change_stream_get_resume_token)
MONGOCXX_LIBMONGOC_SYMBOL(change_stream_next)
MONGOCXX_LIBMONGOC_SYMBOL(cleanup)
MONGOCXX_LIBMONGOC_SYMBOL(client_command_simple_with_server_id)
MONGOCXX_LIBMONGOC_SYMBOL(client_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(client_enable_auto_encryption)
MONGOCXX_LIBMONGOC_SYMBOL(client_find_databases_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_collection)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_database)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_database_names_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_uri)
MONGOCXX_LIBMONGOC_SYMBOL(client_get_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(client_new_from_uri)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_enable_auto_encryption)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_new)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_pop)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_push)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_set_apm_callbacks)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_try_pop)
MONGOCXX_LIBMONGOC_SYMBOL(client_reset)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_abort_transaction)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_advance_cluster_time)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_advance_operation_time)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_append)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_commit_transaction)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_get_cluster_time)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_get_lsid)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_get_operation_time)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_get_opts)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_get_server_id)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_in_transaction)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_start_transaction)
MONGOCXX_LIBMONGOC_SYMBOL(client_session_with_transaction)
MONGOCXX_LIBMONGOC_SYMBOL(client_set_apm_callbacks)
MONGOCXX_LIBMONGOC_SYMBOL(client_set_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(client_set_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(client_set_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(client_start_session)
MONGOCXX_LIBMONGOC_SYMBOL(client_watch)
MONGOCXX_LIBMONGOC_SYMBOL(collection_aggregate)
MONGOCXX_LIBMONGOC_SYMBOL(collection_command_simple)
MONGOCXX_LIBMONGOC_SYMBOL(collection_copy)
// Remove these suppressions when CXX-1594 is done.
BSONCXX_SUPPRESS_DEPRECATION_WARNINGS_BEGIN
MONGOCXX_LIBMONGOC_SYMBOL(collection_count_with_opts)
BSONCXX_SUPPRESS_DEPRECATION_WARNINGS_END
MONGOCXX_LIBMONGOC_SYMBOL(collection_count_documents)
MONGOCXX_LIBMONGOC_SYMBOL(collection_create_bulk_operation_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(collection_drop)
MONGOCXX_LIBMONGOC_SYMBOL(collection_drop_index)
MONGOCXX_LIBMONGOC_SYMBOL(collection_drop_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_estimated_document_count)
MONGOCXX_LIBMONGOC_SYMBOL(collection_find_and_modify_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_find_indexes_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_find_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_get_name)
MONGOCXX_LIBMONGOC_SYMBOL(collection_get_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(collection_get_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(collection_get_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(collection_keys_to_index_string)
MONGOCXX_LIBMONGOC_SYMBOL(collection_read_command_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_rename)
MONGOCXX_LIBMONGOC_SYMBOL(collection_rename_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(collection_set_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(collection_set_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(collection_set_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(collection_watch)
MONGOCXX_LIBMONGOC_SYMBOL(collection_write_command_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(cursor_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(cursor_error)
MONGOCXX_LIBMONGOC_SYMBOL(cursor_error_document)
MONGOCXX_LIBMONGOC_SYMBOL(cursor_new_from_command_reply_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(cursor_next)
MONGOCXX_LIBMONGOC_SYMBOL(cursor_set_max_await_time_ms)
MONGOCXX_LIBMONGOC_SYMBOL(database_aggregate)
MONGOCXX_LIBMONGOC_SYMBOL(database_command_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(database_copy)
MONGOCXX_LIBMONGOC_SYMBOL(database_create_collection)
MONGOCXX_LIBMONGOC_SYMBOL(database_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(database_drop)
MONGOCXX_LIBMONGOC_SYMBOL(database_drop_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(database_find_collections_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(database_get_collection_names_with_opts)
MONGOCXX_LIBMONGOC_SYMBOL(database_get_collection)
MONGOCXX_LIBMONGOC_SYMBOL(database_get_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(database_get_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(database_get_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(database_has_collection)
MONGOCXX_LIBMONGOC_SYMBOL(database_set_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(database_set_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(database_set_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(database_watch)
MONGOCXX_LIBMONGOC_SYMBOL(error_has_label)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_append)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_new)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_set_bypass_document_validation)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_set_fields)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_set_flags)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_set_max_time_ms)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_set_sort)
MONGOCXX_LIBMONGOC_SYMBOL(find_and_modify_opts_set_update)
MONGOCXX_LIBMONGOC_SYMBOL(handshake_data_append)
MONGOCXX_LIBMONGOC_SYMBOL(index_opt_geo_init)
MONGOCXX_LIBMONGOC_SYMBOL(index_opt_init)
MONGOCXX_LIBMONGOC_SYMBOL(index_opt_wt_init)
MONGOCXX_LIBMONGOC_SYMBOL(init)
MONGOCXX_LIBMONGOC_SYMBOL(log_set_handler)
MONGOCXX_LIBMONGOC_SYMBOL(read_concern_copy)
MONGOCXX_LIBMONGOC_SYMBOL(read_concern_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(read_concern_get_level)
MONGOCXX_LIBMONGOC_SYMBOL(read_concern_new)
MONGOCXX_LIBMONGOC_SYMBOL(read_concern_set_level)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_copy)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_get_hedge)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_get_max_staleness_seconds)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_get_mode)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_get_tags)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_new)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_set_hedge)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_set_max_staleness_seconds)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_set_mode)
MONGOCXX_LIBMONGOC_SYMBOL(read_prefs_set_tags)
MONGOCXX_LIBMONGOC_SYMBOL(server_description_host)
MONGOCXX_LIBMONGOC_SYMBOL(server_description_id)
MONGOCXX_LIBMONGOC_SYMBOL(server_description_ismaster)
MONGOCXX_LIBMONGOC_SYMBOL(server_description_round_trip_time)
MONGOCXX_LIBMONGOC_SYMBOL(server_description_type)
MONGOCXX_LIBMONGOC_SYMBOL(server_descriptions_destroy_all)
MONGOCXX_LIBMONGOC_SYMBOL(session_opts_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(session_opts_get_causal_consistency)
MONGOCXX_LIBMONGOC_SYMBOL(session_opts_new)
MONGOCXX_LIBMONGOC_SYMBOL(session_opts_set_causal_consistency)
MONGOCXX_LIBMONGOC_SYMBOL(session_opts_set_default_transaction_opts)
MONGOCXX_LIBMONGOC_SYMBOL(topology_description_get_servers)
MONGOCXX_LIBMONGOC_SYMBOL(topology_description_has_readable_server)
MONGOCXX_LIBMONGOC_SYMBOL(topology_description_has_writable_server)
MONGOCXX_LIBMONGOC_SYMBOL(topology_description_type)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_clone)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_new)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_get_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_get_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_get_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_get_max_commit_time_ms)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_set_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_set_read_prefs)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_set_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(transaction_opts_set_max_commit_time_ms)
MONGOCXX_LIBMONGOC_SYMBOL(uri_copy)
MONGOCXX_LIBMONGOC_SYMBOL(uri_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_auth_mechanism)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_auth_source)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_database)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_hosts)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_options)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_password)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_read_concern)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_read_prefs_t)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_replica_set)
BSONCXX_SUPPRESS_DEPRECATION_WARNINGS_BEGIN
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_ssl)
BSONCXX_SUPPRESS_DEPRECATION_WARNINGS_END
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_tls)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_string)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_username)
MONGOCXX_LIBMONGOC_SYMBOL(uri_get_write_concern)
MONGOCXX_LIBMONGOC_SYMBOL(uri_new)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_copy)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_destroy)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_get_journal)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_get_w)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_get_wmajority)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_get_wtag)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_get_wtimeout)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_is_acknowledged)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_journal_is_set)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_new)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_set_journal)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_set_w)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_set_wmajority)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_set_wtag)
MONGOCXX_LIBMONGOC_SYMBOL(write_concern_set_wtimeout)

#if defined(MONGOC_ENABLE_SSL)
MONGOCXX_LIBMONGOC_SYMBOL(client_pool_set_ssl_opts)
MONGOCXX_LIBMONGOC_SYMBOL(client_set_ssl_opts)
#endif

// Copyright 2015 MongoDB Inc.
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

#include <mongocxx/exception/error_code.hpp>

#include <string>

#include <mongocxx/config/private/prelude.hh>

namespace mongocxx {
MONGOCXX_INLINE_NAMESPACE_BEGIN

namespace {

//
// An error_category for codes generated by the client.
//
class error_category final : public std::error_category {
   public:
    const char* name() const noexcept override {
        return "mongocxx";
    }

    std::string message(int code) const noexcept override {
        switch (static_cast<error_code>(code)) {
            case error_code::k_invalid_client_object:
                return "invalid use of default constructed or moved-from mongocxx::client object";
            case error_code::k_invalid_collection_object:
                return "invalid use of default constructed or moved-from mongocxx::collection "
                       "object";
            case error_code::k_invalid_database_object:
                return "invalid use of default constructed or moved-from mongocxx::database object";
            case error_code::k_invalid_parameter:
                return "an invalid or out-of-bounds parameter was provided";
            case error_code::k_ssl_not_supported:
                return "SSL support not available";
            case error_code::k_unknown_read_concern:
                return "invalid attempt to set an unknown read concern level";
            case error_code::k_unknown_write_concern:
                return "invalid attempt to set an unknown write concern level";
            case error_code::k_instance_already_exists:
                return "cannot create more than one mongocxx::instance object";
            case error_code::k_server_response_malformed:
                return "the response from the server was malformed";
            case error_code::k_invalid_uri:
                return "an invalid MongoDB URI was provided";
            default:
                return "unknown mongocxx error";
        }
    }
};

}  // namespace

const std::error_category& MONGOCXX_CALL error_category() {
    static const class error_category category {};
    return category;
}

MONGOCXX_INLINE_NAMESPACE_END
}  // namespace mongocxx

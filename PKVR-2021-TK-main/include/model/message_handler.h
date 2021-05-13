#pragma once

#include <jsoncpp/json/json.h>

namespace alica_agent {

    namespace message {

        class Message_Handler {
            
            public:
                virtual void handle(const Json::Value& message) = 0;
            
            };
    }
}
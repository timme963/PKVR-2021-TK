#pragma once

#include "model/message_handler.h"

namespace alica_agent{

    namespace message {

        class RequestActionHandler : public Message_Handler{

            public:
                static constexpr char *ID = (char*) "request-action";
                void handle(const Json::Value& message);

            private:
        };
    }
}
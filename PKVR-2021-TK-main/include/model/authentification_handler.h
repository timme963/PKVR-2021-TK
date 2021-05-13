#pragma once

#include "model/message_handler.h"


namespace alica_agent {

    namespace message {

        class AuthentificationHandler : public Message_Handler {

            public:
                virtual void handle(const Json::Value& message);
                static constexpr char *ID = (char*) "auth-response";
            private:
        };

    }
}
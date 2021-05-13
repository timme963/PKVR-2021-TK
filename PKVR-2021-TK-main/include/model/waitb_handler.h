#pragma once
#include "model/message_handler.h"

namespace alica_agent{

    namespace message{
        
        class WaitbHandler : public Message_Handler{

            public:
                static constexpr char *ID = (char*) "sim-start";
                virtual void handle(const Json::Value& message);
            private:
        };
    }
}
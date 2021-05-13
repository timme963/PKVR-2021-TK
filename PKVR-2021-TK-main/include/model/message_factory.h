#pragma once

#include <jsoncpp/json/json.h>
#include <iostream>

namespace alica_agent {

    namespace message {

        class Message_Factory {

            public:
                virtual std::string createJson() = 0;

            private:
        };
    }
}
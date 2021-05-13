#pragma once

#include <iostream>
#include "message_factory.h"

namespace alica_agent{

    namespace message {

        class Authentification_Factory : public Message_Factory {
            public:
                static constexpr char *ID = (char*) "auth-request";
                std::string createJson() override;
                void setpw(std::string pw);
                void setid(std::string id);

            private:
                std::string pw;
                std::string id;
        };
    }
}
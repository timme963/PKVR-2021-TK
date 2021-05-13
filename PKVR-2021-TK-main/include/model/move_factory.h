#pragma once

#include "message_factory.h"
#include <iostream>
#include <vector>

namespace alica_agent {

    namespace message {

        class MessageMoveFactory : public Message_Factory {

            public:
                static constexpr char *ID = (char*) "action";
                std::string createJson() override;
                void setid(std::string id);
                void addComand(std::string);
                void clearComand();
                void settype(std::string type);

            private:
                std::string id;
                std::string type;
                std::vector<std::string> comands;
        };
    }
}
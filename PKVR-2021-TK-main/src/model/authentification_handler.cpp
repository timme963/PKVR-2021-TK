#include "authentification_handler.h"
#include "model/worldmodel.h"
#include <iostream>

namespace alica_agent {

    namespace message {

        void AuthentificationHandler::handle(const Json::Value& message){
            
            std::string result;
            result = message["result"].asString();
            model::WorldModel* wm = model::WorldModel::getInstance();
            if (result == "ok"){
                wm->registered = true;
            }
        }

    }
}
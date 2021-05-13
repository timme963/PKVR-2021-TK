#include "model/move_factory.h"

namespace alica_agent{

    namespace message{

        std::string MessageMoveFactory::createJson(){
 //           {\"content\":{\"pw\":\"1\",\"user\":\"agentA1\"},\"type\":\"auth-request\"}\u0004"
            Json::Value jsonRoot;
            Json::Value jsonContent;
            Json::Value& p = jsonContent["p"];
            jsonContent["id"] = this->id;
            jsonContent["type"] = this->type;

            for (std::string comand : this->comands){
                p.append(comand);
            }

            jsonRoot["type"] = ID;
            jsonRoot["content"] = jsonContent;
            Json::FastWriter fastWriter;
            return fastWriter.write(jsonRoot);
        }

        void MessageMoveFactory::setid(std::string id){
            this->id = id;
        }

        void MessageMoveFactory::settype(std::string type){
            this->type = type;
        }

        void MessageMoveFactory::addComand(std::string comand){
            this->comands.push_back(comand);
        }

        void MessageMoveFactory::clearComand(){
            this->comands.clear();
        }
    }
}
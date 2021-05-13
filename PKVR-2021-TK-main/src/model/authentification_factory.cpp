#include "model/authentification_factory.h"

namespace alica_agent{

    namespace message{

        std::string Authentification_Factory::createJson(){
 //           {\"content\":{\"pw\":\"1\",\"user\":\"agentA1\"},\"type\":\"auth-request\"}\u0004"
            Json::Value jsonRoot;
            Json::Value jsonContent;
            jsonContent["pw"] = this->pw;
            jsonContent["user"] = this->id;
            jsonRoot["type"] = ID;
            jsonRoot["content"] = jsonContent;
            Json::FastWriter fastWriter;
            return fastWriter.write(jsonRoot);
        }
        void Authentification_Factory::setpw(std::string pw){
            this->pw = pw;
        }

        void Authentification_Factory::setid(std::string id){
            this->id = id;
        }
    }
}
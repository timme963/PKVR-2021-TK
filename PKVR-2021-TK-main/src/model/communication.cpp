#include "model/communication.h"
#include "model/authentification_factory.h"
#include "model/authentification_handler.h"
#include "model/waitb_handler.h"
#include "model/request_action_handler.h"
#include "model/move_factory.h"

#include <sys/socket.h>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <thread>

namespace alica_agent{

    namespace model{

        Communication::Communication(){
            _messageFactories[message::Authentification_Factory::ID] = new message::Authentification_Factory();
            _messageFactories[message::MessageMoveFactory::ID] = new message::MessageMoveFactory();
            messageHandlers[message::AuthentificationHandler::ID] = new message::AuthentificationHandler();
            messageHandlers[message::WaitbHandler::ID] = new message::WaitbHandler();
            messageHandlers[message::RequestActionHandler::ID] = new message::RequestActionHandler();
        }

        message::Message_Factory* Communication::getMessage_Factory(std::string id){
            return _messageFactories.at(id);

        }

        Communication* Communication::getInstance()
        {
            static Communication* cm;
            if(!cm){
                cm = new Communication();
            }
            return cm;
        }

        void Communication::listen(){
            char buffer[65536];
            std::string message;
            while (1)
            {
                int n = 0;
                do{
                    n = read(this->socketid,buffer,65536);
                    message.append(buffer, n);
                    }
                while(!message.rfind(Communication::EOM) || n <= 0);
                size_t pos = 0;
                while((pos = message.find(EOM, pos)) != std::string::npos) {
                    message.replace(pos, 1, "");
                    pos ++;
                }

                std::cout << "communication: " << n << std::endl;
                std::cout << "communication: " << message << std::endl;
                {
                    std::lock_guard <std::mutex> lock(this->vlock);
                    Communication::messages.push_back(message);
                }
                message.clear();
                this->cv.notify_one();
            }
        }

        void Communication::handle(){
            while (1){
                std::unique_lock<std::mutex> lock(this->m);
                while (messages.empty()){
                    this->cv.wait(lock);
                }
                std::string message;
                {
                    std::lock_guard<std::mutex> lock(this->vlock);
                    message = messages.front();
                    messages.erase(messages.begin());
                }
                std::string type;
                Json::Reader reader;
                Json::Value root;
                reader.parse(message, root);
                type = root["type"].asString();
                message::Message_Handler* handler = messageHandlers[type];
                if (!handler){
                    std::cerr << "communication: Unhandled message type:\t" << type << std::endl;
                    continue;
                }
                std::cerr << "Communication type: " << type << std::endl;
                handler->handle(root["content"]);
                this->callCallbacks();
            }
        }

        bool Communication::sendMessage(std::string message){
            message.append(EOM);
            int n = write(this->socketid,message.c_str(),message.length());
            if (n < 0){
                std::cout << "communication: sendMessage failed" << std::endl;
                return false;
            }
            return true;
        }

        void Communication::connectSocket(const char* ip, int port){
            this->socketid = socket(AF_INET, SOCK_STREAM, 0);
            if (this->socketid < 0){
                std::cout << "ERROR opening socket" << std::endl;
                return;
            }

            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(port);

            if(inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0) { 
                std::cout <<"\nSC: invalid address/ Address not supported \n"; 
                return;
            }

            if (connect(this->socketid, (struct sockaddr*) &serv_addr,sizeof(serv_addr)) < 0){
                std::cout << "ERROR connecting" << std::endl;
                return;
            }

            this->listener = new std::thread(&Communication::listen, this);
            this->handler = new std::thread(&Communication::handle, this);
        }

        void Communication::setCallback(std::string key, std::function<void()> callback){
            if(this->callbacks.find(key) != this->callbacks.end()){
                this->callbacks.at(key)->push_back(callback);
            } else{
                //std::string tempKey = key;
                std::vector<std::function<void()>>* vec = new std::vector<std::function<void()>>();
                vec->push_back(callback);
                this->callbacks.insert(std::make_pair<std::string, std::vector<std::function<void()>>*>(std::move(key), std::move(vec)));
            }
        }

        void Communication::callCallbacks(){
            for(auto entry : this->callbacks){
                for(auto callback : *(entry.second)){
                    callback();
                }
            }
        }
    }
    
}

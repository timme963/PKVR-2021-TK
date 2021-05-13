#pragma once

#include <thread>
#include <unordered_map>
#include <vector>
#include <functional>
#include <mutex>
#include <condition_variable>

namespace alica_agent{

    namespace message {

        class Message_Factory;
        class Message_Handler;
    }

    namespace model{

        class Communication{
            public:
                static constexpr char * EOM  = (char *) "\u0004";
                static Communication* getInstance();
                void connectSocket(const char* ip, int port);
                bool sendMessage(std::string message);
                message::Message_Factory* getMessage_Factory(std::string id);
                void setCallback(std::string key, std::function<void()>);
                void callCallbacks();

            private:
                Communication();
                void listen();
                void handle();
                int socketid;
                std::thread* listener;
                std::thread* handler;
                std::unordered_map<std::string, message::Message_Factory*> _messageFactories;
                std::unordered_map<std::string, message::Message_Handler*> messageHandlers;
                std::vector<std::string> messages;
                std::unordered_map<std::string, std::vector<std::function<void()>>*> callbacks;
                std::mutex m;
                std::mutex vlock;
                std::condition_variable cv;
        };
    }
}


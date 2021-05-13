#include "model/waitb_handler.h"
#include "model/worldmodel.h"
#include <iostream>

namespace alica_agent{

    namespace message{

        void WaitbHandler::handle(const Json::Value& message){

            long time = (long) message["time"].asUInt64();
            std::cout << "WaitHandler: " << time << std::endl;
            
            model::WorldModel* wm = model::WorldModel::getInstance();
            wm->gameconf.time = (long)message["time"].asUInt64();
            Json::Value percept = message["percept"];
            wm->gameconf.vision = percept["vision"].asInt64();
            int visionLen = wm->gameconf.vision*2 + 1;

            wm->terrain.goal = new int*[visionLen];
            wm->terrain.obstacle = new int*[visionLen];

            for (int i = 0; i < visionLen; ++i){
                wm->terrain.goal[i] = new int[visionLen];
                wm->terrain.obstacle[i] = new int[visionLen];

                for (int j = 0; j < visionLen; ++j){
                    wm->terrain.goal[i][j] = -1;
                    wm->terrain.obstacle[i][j] = -1;
                }
            }
        }
    }
}
#include "model/request_action_handler.h"
#include "model/worldmodel.h"
#include <iostream>

namespace alica_agent{

    namespace message{

        void RequestActionHandler::handle(const Json::Value& message){
            model::WorldModel *wm = model::WorldModel::getInstance();
            wm->gameStatus.time = (long)message["time"].asUInt64();
            wm->gameStatus.deadline = (long)message["deadline"].asUInt64();
            wm->gameStatus.step = message["step"].asUInt64();
            const Json::Value& id = message["id"];
            const Json::Value& percept = message["percept"];
            const Json::Value& lastActionType = percept["lastAction"];
            const Json::Value& lastActionResult = percept["lastActionResult"];
            const Json::Value& lastActionParams = percept["lastActionParams"];
            const Json::Value& things = percept["things"];
            const Json::Value& terrain = percept["terrain"];
            const Json::Value& goal = terrain["goal"];
            const Json::Value& obstacle = terrain["obstacle"];
            wm->actionid = id.asString();
            for (int i = 0; i <  wm->gameconf.vision * 2 + 1; i++){
                for (int j = 0; j <  wm->gameconf.vision * 2 + 1; j++){
                    
                    bool inVision = false;
                    if (i <= wm->gameconf.vision && j >= wm->gameconf.vision - i && j <= wm->gameconf.vision + i) {
                        inVision = true;
                    }
                    if (i > wm->gameconf.vision && j >= i - wm->gameconf.vision  && j <= wm->gameconf.vision*2 - (i - wm->gameconf.vision)){
                        inVision = true;
                    }
                    if (inVision){
                        wm->terrain.goal[i][j] = 0;
                        wm->terrain.obstacle[i][j] = 0;
                    } else {
                        wm->terrain.goal[i][j] = -1;
                        wm->terrain.obstacle[i][j] = -1;
                    }

                }
            }

            std::cout << "test" << std::endl;

            for(Json::Value value : goal){
                wm->terrain.goal[value[0].asInt() + wm->gameconf.vision][value[1].asInt() + wm->gameconf.vision] = 1;
            }

            for(Json::Value value : obstacle){
                //std::cout << "ausgabe" << std::endl;
                wm->terrain.obstacle[value[0].asInt() + wm->gameconf.vision][value[1].asInt() + wm->gameconf.vision] = 1;
            }

            wm->things.clear();

            for (Json::Value value : things){
                model::WorldModel::Thing* thing = new model::WorldModel::Thing();
                thing->x = value["x"].asInt();;
                thing->y = value["y"].asInt();;
                thing->details = value["details"].asString();;
                thing->type = value["type"].asString();
                wm->things.push_back(thing);
            }

            wm->actionResult.success = lastActionResult.asString() == "success" ? true : false;
            wm->actionResult.type = lastActionType.asString();
            wm->actionResult.actionParams.clear();
            for (Json::Value value : lastActionParams) {
                wm->actionResult.actionParams.push_back(value.asString());
            }

            /*for (model::WorldModel::Thing* thing : wm->things){
                std::cout << thing->x << "\t" << std::endl;
            }*/

            std::cout << "Goal: " << std::endl;
            for (int i = 0; i <  wm->gameconf.vision * 2 + 1; i++){
                for (int j = 0; j <  wm->gameconf.vision * 2 + 1; j++){
                     std::cout << (wm->terrain.goal[j][i] == -1 ? "_" : std::to_string(wm->terrain.goal[j][i])) << " ";
                }
                std::cout << std::endl;
                
            }
            
            std::cout << "Obstacles: " << std::endl;
            for (int i = 0; i <  wm->gameconf.vision * 2 + 1; i++){
                for (int j = 0; j <  wm->gameconf.vision * 2 + 1; j++){
                    //std::cout << wm->terrain.obstacle[j][i] << std::endl;
                    std::cout << (wm->terrain.obstacle[j][i] == -1 ? "_" : std::to_string(wm->terrain.obstacle[j][i])) << " ";
                }
                std::cout << std::endl;

            }
        }
    }
}
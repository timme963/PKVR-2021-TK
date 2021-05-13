#pragma once
#include <iostream>
#include <vector>
#include "model/world.h"

namespace alica_agent{

    namespace model{

            class WorldModel{

                public:
                    enum State{
                        INIT_STATE, START_STATE, WAIT_STATE, PLAY_STATE, FINISHED_STATE
                    };
                    enum Move{
                        NORTH, EAST, SOUTH, WEST, WAIT
                    };
                    
                    struct Configuration {
                        long time = 0;
                        int vision = 0;
                    };
                    struct GameStatus {
                        long time;
                        long deadline;
                        int step;
                    };
                    struct Terrain {
                        int** goal;
                        int** obstacle;
                    };
                    struct Thing {
                        int x;
                        int y;
                        std::string details;
                        std::string type;
                    };
                    struct ActionResult {
                        bool success;
                        std::string type;
                        std::vector<std::string> actionParams;
                    };
                    static WorldModel* getInstance();
                    std::string nameid;
                    std::string password;
                    std::string actionid;
                    bool registered;
                    State state;
                    Configuration gameconf;
                    GameStatus gameStatus;
                    Terrain terrain;
                    std::vector<Thing*> things;
                    Move movecommand = WAIT;
                    World world;
                    ActionResult actionResult;


                private:
                    WorldModel(): registered(false), state(INIT_STATE){};
                    
                };
    }
}


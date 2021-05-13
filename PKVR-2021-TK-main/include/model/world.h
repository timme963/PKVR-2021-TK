#pragma once

#include <vector>
#include <iostream>
#include "model/FieldContainer.h"

namespace alica_agent{

    namespace model{

        struct Field{

                Field(int x, int y) : posx(x), posy(y){}
            
                Field* up = nullptr;
                Field* down = nullptr;
                Field* left = nullptr;
                Field* right = nullptr;

                //WorldModel::Thing *thing;
                int obstacle = 0;
                int goal = 0;
                int posx = 0;
                int posy = 0;

        };

        class World{

            public:
                World();
                void updateObstacle(int obstacle, int x, int y);
                void updateGoal(int goal, int x, int y);
                //void updateThing(WorldModel::Thing* thing, int x, int y);
                void move(std::string direction);
                void printWorld();
                static bool sortVector(int i, int j);
                Field* getPosition();
                 

            private:
                Field* findField(int x, int y);
                Field* position;
                FieldContainer fields;

        };
    }
}
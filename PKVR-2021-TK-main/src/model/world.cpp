#include "model/world.h"
#include "model/worldmodel.h"
#include <algorithm>

namespace alica_agent{

    namespace model{

        World::World(){
            position = new Field(0, 0);
            fields.push_back(position);
        }

        void World::updateObstacle(int obstacle, int x, int y){
            Field* field = findField(x, y);
            field->obstacle = obstacle;
        }

        void World::updateGoal(int goal, int x, int y){

        }
        /*
        void World::updateThing(WorldModel::Thing* thing, int x, int y){

        }
        */
        void World::move(std::string direction){
                if(direction == "n"){
                    position = position->up;
                }
                if(direction == "e"){
                    position = position->right;
                }
                if(direction == "s"){
                    position = position->down;
                } 
                if (direction == "w"){
                    position = position->left;
                }
        }

        Field* World::getPosition(){
            return this->position;
        }

        Field* World::findField(int x, int y){
            if (x == 0 && y == 0) {
                return position;
            }
  
            Field* actual = position;
            if (x != 0) {
                int direction = x / abs(x);
                for (int i = 0; i < abs(x); i++){
                    if (direction < 0) {
                        Field* next = actual->left;
                        if (!next) {
                            next = new Field(actual->posx -1, actual->posy);
                            fields.push_back(next);
                        }
                        actual->left = next;
                        next->right = actual;
                        actual = next;
                    } 
                    else {
                        Field* next = actual->right;
                        if (!next) {
                            next = new Field(actual->posx +1, actual->posy);
                            fields.push_back(next);
                        }
                        actual->right = next;
                        next->left = actual;
                        actual = next;
                    }
                }
            }
            if (y != 0) {
                int direction = y / abs(y);
                for (int i = 0; i < abs(y); i++){
                    if (direction < 0) {
                        Field* next = actual->up;
                        if (!next) {
                            next = new Field(actual->posx, actual->posy -1);
                            fields.push_back(next);
                        }
                        actual->up = next;
                        next->down = actual;
                        actual = next;
                    } 
                    else {
                        Field* next = actual->down;
                        if (!next) {
                            next = new Field(actual->posx, actual->posy +1);
                            fields.push_back(next);
                        }
                    
                        actual->down = next;
                        next->up = actual;
                        actual = next;
                    }
                }
            }
            return actual;
        };

        bool World::sortVector (int i, int j) { 
            return (i < j);
        }

        void World::printWorld(){
            //std::sort(fields.begin(), fields.end(), sortVector);
            /*int i = 10000;
            for (Field* field : fields) {
                if (field->posy != i) {
                    std::cout << std::endl;
                    i = field->posy;
                }
                std::cout << field->obstacle;
            }*/
            std::vector<int> keys = fields.getKeys();
            std::sort(keys.begin(), keys.end(), World::sortVector);
            std::cout << "position: " << std::endl;
            for (int y : keys) {
               //std::cout << y << std::endl;
                for (int x = fields.getMinX() ; x <= fields.getMaxX(); ++x){
                    Field* field = fields.get(x,y);
                    if(field) {
                        if (field == position) {
                            std::cout << "x" << " ";
                        } else {
                            std::cout << (field->obstacle == -1 ? "_" : std::to_string(field->obstacle)) << " ";
                            //std::cout << field->obstacle << " ";
                            //std::cout << field->posx << "," << field->posy << " ";
                        }
                    }
                    else {
                        std::cout << " " << " ";
                    } 
                }
                std::cout << std::endl;
            }
        }
    }
}
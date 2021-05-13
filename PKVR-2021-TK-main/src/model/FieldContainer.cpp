# include "model/FieldContainer.h"
#include "model/world.h"

namespace alica_agent {

    namespace model {

        bool FieldContainer::push_back(Field* field){
            int posx = field->posx;
            int posy = field->posy;
            std::unordered_map<int, Field*>* yFields = get(posy);

            if(!yFields){
                yFields = new std::unordered_map<int, Field*>();
                fieldMap.insert(std::make_pair(posy, yFields));
                keys.push_back(posy);
            }
            bool notExists = yFields->find(posx) == yFields->end();
            //bool notExists = yFields->insert(std::make_pair(posx, field)).second;
            if(notExists){
                (*yFields)[posx] = field;
                if (posx > maxX) {
                    maxX = posx;
                }
                if (posx < minX) {
                    minX = posx;
                }
                fields.push_back(field);
                return true;
            }
            return false;
        }

        Field* FieldContainer::at(int pos){
            return fields.at(pos);
        }

        Field* FieldContainer::get(int x, int y){
            std::unordered_map<int, Field*>* tmp = get(y);
            if (!tmp) {
                return nullptr;
            }
            auto entry = tmp->find(x);
            if (entry != tmp->end()) {
                return entry->second;
            }
            return nullptr;
        }

        std::unordered_map<int, Field*>* FieldContainer::get(int y){
            auto entry = fieldMap.find(y);
            if (entry != fieldMap.end()) {
                return entry->second;
            }
            return nullptr;
        }

        int FieldContainer::size(){
            return fields.size();
        }

        std::vector<int> FieldContainer::getKeys() {
            return keys;
        }

        int FieldContainer::getMinX(){
            return minX;
        }
        
        int FieldContainer::getMaxX(){
            return maxX;
        }
    }
}
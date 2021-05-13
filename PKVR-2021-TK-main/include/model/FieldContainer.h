#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace alica_agent {

    namespace model {

        struct Field;

        class FieldContainer {

        public:
            bool push_back(Field*);
            Field* at(int pos);
            Field* get(int x, int y);
            std::unordered_map<int, Field*>* get(int y);
            int size();
            std::vector<int> getKeys();
            int getMinX();
            int getMaxX();

        private:
            std::vector<Field*> fields;
            std::unordered_map<int, std::unordered_map<int, Field*>*> fieldMap;
            std::vector<int> keys;
            int maxX = 0;
            int minX = 0;
        };
    }
}


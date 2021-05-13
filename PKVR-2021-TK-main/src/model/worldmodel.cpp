#include "model/worldmodel.h"

namespace alica_agent{

    namespace model{

        WorldModel* WorldModel::getInstance()
        {
            static WorldModel* wm;
            if(!wm){
                wm = new WorldModel();
                }
            return wm;
        }
        
    }
}

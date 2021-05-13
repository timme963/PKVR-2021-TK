#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1611833222383) ENABLED START*/
//Add additional includes here
namespace alica_agent{

    namespace model{

        class WorldModel;

    }
}
/*PROTECTED REGION END*/

namespace alica
{
    class analysisObstacles : public DomainBehaviour
    {
        public:
            analysisObstacles();
            virtual ~analysisObstacles();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1611833222383) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1611833222383) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1611833222383) ENABLED START*/
            //Add additional private methods here
            alica_agent::model::WorldModel* wm;
        /*PROTECTED REGION END*/
    };
} /* namespace alica */

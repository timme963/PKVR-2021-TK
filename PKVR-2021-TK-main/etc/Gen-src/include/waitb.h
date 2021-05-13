#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1610020212179) ENABLED START*/
//Add additional includes here
#include <condition_variable>
#include <mutex>

namespace alica_agent{

    namespace model{

        class Communication;
        class WorldModel;
    }
}
/*PROTECTED REGION END*/

namespace alica
{
    class waitb : public DomainBehaviour
    {
        public:
            waitb();
            virtual ~waitb();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1610020212179) ENABLED START*/
            //Add additional protected methods here
            void onMessage();
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1610020212179) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1610020212179) ENABLED START*/
            //Add additional private methods here
            bool _wait = false;
            alica_agent::model::WorldModel *wm;
            alica_agent::model::Communication *cm;
            std::condition_variable cv;
            std::mutex m;
        /*PROTECTED REGION END*/
    };
} /* namespace alica */

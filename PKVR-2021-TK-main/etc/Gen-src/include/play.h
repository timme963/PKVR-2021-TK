#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1606987675564) ENABLED START*/
//Add additional includes here
namespace alica_agent{
    namespace model{
        class Communication;
        class WorldModel;
    }
}
/*PROTECTED REGION END*/

namespace alica
{
    class play : public DomainBehaviour
    {
        public:
            play();
            virtual ~play();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1606987675564) ENABLED START*/
            //Add additional protected methods here
            void onMessage();
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1606987675564) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1606987675564) ENABLED START*/
            //Add additional private methods here
            alica_agent::model::Communication *cm;
            alica_agent::model::WorldModel *wm;
            std::condition_variable cv;
            std::mutex m;
            bool _wait = false;
        /*PROTECTED REGION END*/
    };
} /* namespace alica */

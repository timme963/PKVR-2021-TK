#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1611825595992) ENABLED START*/
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
    class move : public DomainBehaviour
    {
        public:
            move();
            virtual ~move();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1611825595992) ENABLED START*/
            //Add additional protected methods here
            void onMessage();
            std::string getCommand(const std::string str);
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1611825595992) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1611825595992) ENABLED START*/
            //Add additional private methods here
            alica_agent::model::Communication *cm;
            alica_agent::model::WorldModel *wm;
            std::condition_variable cv;
            std::mutex m;
            bool _wait = false;
            const Variable* planContext;
        /*PROTECTED REGION END*/
    };
} /* namespace alica */

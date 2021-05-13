#pragma once

#include "DomainBehaviour.h"
/*PROTECTED REGION ID(inc1606386510762) ENABLED START*/
//Add additional includes here
#include <mutex>
#include <condition_variable>


namespace alica_agent{

    namespace model{
        
        class Communication;
        class WorldModel;
    }
    namespace message{

        class Authentification_Factory;
    }
}
/*PROTECTED REGION END*/

namespace alica
{
    class init : public DomainBehaviour
    {
        public:
            init();
            virtual ~init();
            virtual void run(void* msg);
            /*PROTECTED REGION ID(pub1606386510762) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        protected:
            virtual void initialiseParameters();
            /*PROTECTED REGION ID(pro1606386510762) ENABLED START*/
            //Add additional protected methods here
            /*PROTECTED REGION END*/
        private:
        /*PROTECTED REGION ID(prv1606386510762) ENABLED START*/
            //Add additional private methods here
            alica_agent::model::Communication *cm;
            alica_agent::model::WorldModel *wm;
            std::mutex m;
            std::condition_variable cv;
            alica_agent::message::Authentification_Factory* auth_factory;
            void onMessage();
            int retries = 3;
        /*PROTECTED REGION END*/
    };
} /* namespace alica */

#include "waitb.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1610020212179) ENABLED START*/
    //Add additional includes here
    #include "model/communication.h"
    #include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    /*PROTECTED REGION ID(staticVars1610020212179) ENABLED START*/
    //initialise static variables here
    /*PROTECTED REGION END*/

    waitb::waitb() : DomainBehaviour("waitb")
    {
        /*PROTECTED REGION ID(con1610020212179) ENABLED START*/
        //Add additional options here
        wm = alica_agent::model::WorldModel::getInstance();
        cm = alica_agent::model::Communication::getInstance();
        /*PROTECTED REGION END*/

    }
    waitb::~waitb()
    {
        /*PROTECTED REGION ID(dcon1610020212179) ENABLED START*/
        //Add additional options here
        /*PROTECTED REGION END*/

    }
    void waitb::run(void* msg)
    {
        /*PROTECTED REGION ID(run1610020212179) ENABLED START*/
        //Add additional options here
        std::cout << "run" << std::endl;
        if (_wait){
            return;
        }
        if (wm->gameconf.time == 0){

            std::function<void()> callback = std::bind(&waitb::onMessage, &(*this));
            cm->setCallback("sim-start", callback);
            std::unique_lock <std::mutex> lock(this->m);
            while(!_wait){
                this->cv.wait(lock);
            }
        }
        std::cout << "wait successful" << std::endl;
        wm->state = alica_agent::model::WorldModel::PLAY_STATE;
        _wait = true;
        /*PROTECTED REGION END*/

    }
    void waitb::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1610020212179) ENABLED START*/
        //Add additional options here







        /*PROTECTED REGION END*/

    }
    /*PROTECTED REGION ID(methods1610020212179) ENABLED START*/
        //Add additional options here
        void waitb::onMessage(){
            if (wm->gameconf.time > 0){
                _wait = true;
                this->cv.notify_one();
            }
        }
    /*PROTECTED REGION END*/

} /* namespace alica */

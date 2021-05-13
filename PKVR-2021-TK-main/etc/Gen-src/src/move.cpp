#include "move.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1611825595992) ENABLED START*/
    //Add additional includes here
    #include "model/move_factory.h"
    #include "model/communication.h"
    #include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    /*PROTECTED REGION ID(staticVars1611825595992) ENABLED START*/
    //initialise static variables here
    /*PROTECTED REGION END*/

    move::move() : DomainBehaviour("move")
    {
        /*PROTECTED REGION ID(con1611825595992) ENABLED START*/
        //Add additional options here
        wm = alica_agent::model::WorldModel::getInstance();
        cm = alica_agent::model::Communication::getInstance();
        /*PROTECTED REGION END*/

    }
    move::~move()
    {
        /*PROTECTED REGION ID(dcon1611825595992) ENABLED START*/
        //Add additional options here
        /*PROTECTED REGION END*/

    }
    void move::run(void* msg)
    {
        /*PROTECTED REGION ID(run1611825595992) ENABLED START*/
        //Add additional options here
        _wait = false;
        
        //const State* stateName = runningPlan->getActiveState();
        //const std::string stateName = runningPlan->getActiveState()->getName();
        //std::cout << "State: " << stateName << std::endl;
        //if(stateName){
        //    std::cout << "State: " << stateName->getName() << std::endl;
        //}
        alica_agent::message::Message_Factory* factory = cm->getMessage_Factory(alica_agent::message::MessageMoveFactory::ID);
        if (!factory){
            return;
        }
        alica_agent::message::MessageMoveFactory* move_factory = static_cast <alica_agent::message::MessageMoveFactory*> (factory);

        const RunningPlan* runningPlan = this->getPlanContext().getRunningPlan().get();
        const std::string command = runningPlan->getParent()->getActiveState()->getName();

        move_factory->setid(wm->actionid);
        move_factory->settype("move");
        move_factory->addComand(getCommand(command));
        
        std::string message = move_factory->createJson();
        std::function<void()> callback = std::bind(&move::onMessage, &(*this));
        cm->setCallback("request-action", callback);
        std::unique_lock <std::mutex> lock(this->m);
        cm->sendMessage(message);
        move_factory->clearComand();
        
        while(!_wait){
            this->cv.wait(lock);
        }
        if(wm->actionResult.type == "move" && wm->actionResult.success && wm->actionResult.actionParams.size() > 0) {
            wm->world.move(wm->actionResult.actionParams[0]);
        }
        /*PROTECTED REGION END*/

    }
    void move::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1611825595992) ENABLED START*/
        //Add additional options here


        /*PROTECTED REGION END*/

    }
    /*PROTECTED REGION ID(methods1611825595992) ENABLED START*/
        //Add additional options here
        void move::onMessage(){
            if (wm->gameconf.time > 0){
                _wait = true;
                this->cv.notify_one();
            }
        }

        std::string move::getCommand(const std::string str){
            if(str == "southState") return "s";
            else if(str == "northState") return "n";
            else if(str == "westState") return "w";
            else if(str == "eastState") return "e";
            return "_";
        }
    /*PROTECTED REGION END*/

} /* namespace alica */

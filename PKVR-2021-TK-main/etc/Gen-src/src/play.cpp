#include "play.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1606987675564) ENABLED START*/
    //Add additional includes here
    #include "model/move_factory.h"
    #include "model/communication.h"
    #include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    /*PROTECTED REGION ID(staticVars1606987675564) ENABLED START*/
    //initialise static variables here
    /*PROTECTED REGION END*/

    play::play() : DomainBehaviour("play")
    {
        /*PROTECTED REGION ID(con1606987675564) ENABLED START*/
        //Add additional options here
        wm = alica_agent::model::WorldModel::getInstance();
        cm = alica_agent::model::Communication::getInstance();
        /*PROTECTED REGION END*/

    }
    play::~play()
    {
        /*PROTECTED REGION ID(dcon1606987675564) ENABLED START*/
        //Add additional options here
        /*PROTECTED REGION END*/

    }
    void play::run(void* msg)
    {
        /*PROTECTED REGION ID(run1606987675564) ENABLED START*/
        //Add additional options here
        _wait = false;

        if(wm->movecommand == alica_agent::model::WorldModel::Move::NORTH){
            return;
        }

        std::cout << "test play.cpp" << std::endl;
        wm->movecommand = alica_agent::model::WorldModel::Move::NORTH;
        //move_factory->settype("move");
        //move_factory->setid(wm->actionid);
        //move_factory->addComand("e");
        //move_factory->addComand("n");
        //std::string message = move_factory->createJson();
            //std::function<void()> callback = std::bind(&init::onMessage, &(*this));
            //cm->setCallback("auth-response", callback);
        //std::function<void()> callback = std::bind(&play::onMessage, &(*this));
        //cm->setCallback("request-action", callback);
        //std::unique_lock <std::mutex> lock(this->m);
        //cm->sendMessage(message);
        
        //while(!_wait){
        //    this->cv.wait(lock);
        //}
        /*PROTECTED REGION END*/

    }
    void play::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1606987675564) ENABLED START*/
        //Add additional options here






















        /*PROTECTED REGION END*/

    }
    /*PROTECTED REGION ID(methods1606987675564) ENABLED START*/
        //Add additional options here
        //void play::onMessage(){
        //    if (wm->gameconf.time > 0){
        //        _wait = true;
        //        this->cv.notify_one();
        //    }
        //}
    /*PROTECTED REGION END*/

} /* namespace alica */

#include "init.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1606386510762) ENABLED START*/
    //Add additional includes here
    #include "model/authentification_factory.h"
    #include "model/worldmodel.h"
    #include "model/communication.h"
/*PROTECTED REGION END*/

namespace alica
{
    /*PROTECTED REGION ID(staticVars1606386510762) ENABLED START*/
    //initialise static variables here
    static std::string CLASS_TAG = "Init";
    /*PROTECTED REGION END*/

    init::init() : DomainBehaviour("init")
    {
        /*PROTECTED REGION ID(con1606386510762) ENABLED START*/
        wm = alica_agent::model::WorldModel::getInstance();
        wm->nameid = this->getEngine()->getRobotName();
        wm->password = "1";
        cm = alica_agent::model::Communication::getInstance();

        /*PROTECTED REGION END*/

    }
    init::~init()
    {
        /*PROTECTED REGION ID(dcon1606386510762) ENABLED START*/
        //Add additional options here
        /*PROTECTED REGION END*/

    }
    void init::run(void* msg)
    {
        /*PROTECTED REGION ID(run1606386510762) ENABLED START*/
        
        if (!wm->state == alica_agent::model::WorldModel::INIT_STATE){
            return;
        }
        std::cout << "Init run läuft" << std::endl;
        cm->connectSocket("127.0.0.1", 12300);
        alica_agent::message::Message_Factory* factory = cm->getMessage_Factory(alica_agent::message::Authentification_Factory::ID);
        if (!factory){
            return;
        }
        auth_factory = static_cast <alica_agent::message::Authentification_Factory*> (factory);
        auth_factory->setpw(wm->password);
        auth_factory->setid(wm->nameid);
        std::string message = auth_factory->createJson();
        std::function<void()> callback = std::bind(&init::onMessage, &(*this));
        cm->setCallback("auth-response", callback);
        cm->sendMessage(message);
        std::unique_lock <std::mutex> lock(this->m);
        
        while (!wm->registered){
            this->cv.wait(lock);
        }
        std::cout << "Init: " << wm->nameid << " " << wm->password << std::endl; 

        wm->state = alica_agent::model::WorldModel::START_STATE;
        
        /*PROTECTED REGION END*/

    }
    void init::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1606386510762) ENABLED START*/
        //Add additional options here























        /*PROTECTED REGION END*/

    }
    /*PROTECTED REGION ID(methods1606386510762) ENABLED START*/
        //Add additional options here
    void init::onMessage(){
        if(wm->registered){
            this->cv.notify_one();
        }
        else if (retries > 0) {
            cm->sendMessage(auth_factory->createJson());
            retries--;
        }
        else {
            std::cerr << "Couldn't authenticate." << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    /*PROTECTED REGION END*/

} /* namespace alica */

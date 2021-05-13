#include "alica_agent.h"
#include <engine/AlicaEngine.h>
#include <essentials/IDManager.h>
#include <thread>

#include <BehaviourCreator.h>
#include <ConditionCreator.h>
#include <UtilityFunctionCreator.h>
#include <ConstraintCreator.h>

#include <alica_capnzero_proxy/Communication.h>
#include <model/worldmodel.h>

namespace alica_agent
{
    Alica_Agent::Alica_Agent(std::string rolesetname, std::string masterplan, std::string rolesetdir)
    {
        
        engine = new alica::AlicaEngine(new essentials::IDManager(), rolesetname, masterplan, false);
        bc = new alica::BehaviourCreator();
        cc = new alica::ConditionCreator();
        uc = new alica::UtilityFunctionCreator();
        crc = new alica::ConstraintCreator();

        model::WorldModel* wm = model::WorldModel::getInstance();

        engine->setAlicaClock(new alica::AlicaClock());
        engine->setCommunicator(new alica_capnzero_proxy::Communication(this->engine));

        std::cout << "test" << std::endl;
        
        if (!engine->init(bc, cc, uc, crc)) {
            std::cerr << "Base: Unable to initialize the Alica Engine successful!" << std::endl;
        }

    }

    Alica_Agent::~Alica_Agent(){}

    void Alica_Agent::start(){
        this->engine->start();
    }
}

void printUsage() {
    std::cout << "Usage: ./pkvr_agent -m \"Masterplan\" [-rd \"RoleSetDirectory\"] [-rset \"RoleSet\"]" << std::endl;
}

int main(int argumentc, char** argv)
{
    if (argumentc < 2) {
        printUsage();
        return 0;
    }

    std::cout << "Parsing command line parameters:" << std::endl;

    std::string masterplan = "";
    std::string rolesetdir = ".";
    std::string roleset = "";

    for (int i = 1; i < argumentc; i++) {
        if (std::string(argv[i]) == "-m" || std::string(argv[i]) == "-masterplan") {
            masterplan = argv[i + 1];
            i++;
        }

        if (std::string(argv[i]) == "-rd" || std::string(argv[i]) == "-rolesetdir") {
            rolesetdir = argv[i + 1];
            i++;
        }
        if (std::string(argv[i]) == "-r" || std::string(argv[i]) == "-roleset") {
            roleset = argv[i + 1];
            i++;
        }
    }

    alica_agent::Alica_Agent* agent = new alica_agent::Alica_Agent(roleset, masterplan, rolesetdir);
    agent->start();
    while(true){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    return 0;
}
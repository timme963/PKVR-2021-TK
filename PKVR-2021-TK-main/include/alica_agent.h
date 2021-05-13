#pragma once
#include <iostream>

namespace alica
{
    class AlicaEngine;
    class BehaviourCreator;
    class ConditionCreator;
    class UtilityFunctionCreator;
    class ConstraintCreator;
   
}

namespace alica_agent
{
    class Alica_Agent
    {
        public:
            Alica_Agent(std::string rolesetname, std::string masterplan, std::string rolesetdir);
                virtual ~Alica_Agent();
                void start();
        private:
            alica::AlicaEngine* engine;
            alica::BehaviourCreator* bc;
            alica::ConditionCreator* cc;
            alica::UtilityFunctionCreator* uc;
            alica::ConstraintCreator* crc;
    };
}
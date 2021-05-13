#pragma once

#include "DomainCondition.h"
#include <engine/BasicUtilityFunction.h>
#include <engine/UtilityFunction.h>
#include <engine/DefaultUtilityFunction.h>
/*PROTECTED REGION ID(incl1611825052624) ENABLED START*/
//Add additional includes here
#include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    /*PROTECTED REGION ID(meth1611825052624) ENABLED START*/
    //Add additional options here
    class MoveUtility{
        public:
            static bool evaluateMove(alica_agent::model::WorldModel::Move move);
    };
    /*PROTECTED REGION END*/
    class UtilityFunction1611825052624 : public BasicUtilityFunction
    {
        std::shared_ptr<UtilityFunction> getUtilityFunction(Plan* plan);
    };
    class PreCondition1611825298622 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825300188 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825301669 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825303063 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825460491 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825453928 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825450624 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
    class PreCondition1611825442338 : public DomainCondition
    {
        bool evaluate(std::shared_ptr<RunningPlan> rp);
    };
} /* namespace alica */

#include "UtilityFunctionCreator.h"
#include "main1606386348567.h"
#include "Game1606987272334.h"
#include "PlayPlan1611235901799.h"
#include "Motion1611825052624.h"
#include "DataAnalysis1611832940311.h"
#include <iostream>

namespace alica
{

    UtilityFunctionCreator::~UtilityFunctionCreator()
    {
    }

    UtilityFunctionCreator::UtilityFunctionCreator()
    {
    }


    std::shared_ptr<BasicUtilityFunction> UtilityFunctionCreator::createUtility(long utilityfunctionConfId)
    {
        switch(utilityfunctionConfId)
        {
            case 1606386348567:
                return std::make_shared<UtilityFunction1606386348567>();
                break;
            case 1606987272334:
                return std::make_shared<UtilityFunction1606987272334>();
                break;
            case 1611235901799:
                return std::make_shared<UtilityFunction1611235901799>();
                break;
            case 1611825052624:
                return std::make_shared<UtilityFunction1611825052624>();
                break;
            case 1611832940311:
                return std::make_shared<UtilityFunction1611832940311>();
                break;
            default:
            std::cerr << "UtilityFunctionCreator: Unknown utility requested: " << utilityfunctionConfId << std::endl;
            throw new std::exception();
            break;
        }
    }


}

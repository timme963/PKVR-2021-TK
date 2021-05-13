#include "ConditionCreator.h"
#include "main1606386348567.h"
#include "Game1606987272334.h"
#include "PlayPlan1611235901799.h"
#include "Motion1611825052624.h"
#include "DataAnalysis1611832940311.h"
#include "init1606386510762.h"
#include "play1606987675564.h"
#include "waitb1610020212179.h"
#include "move1611825595992.h"
#include "analysisObstacles1611833222383.h"

namespace alica
{

    ConditionCreator::ConditionCreator()
    {
    }
    ConditionCreator::~ConditionCreator()
    {
    }

    std::shared_ptr<BasicCondition> ConditionCreator::createConditions(long conditionConfId)
    {
        switch (conditionConfId)
        {
            case 1610020227160:
            return std::make_shared<PreCondition1610020227160>();
                break;
            case 1610020232701:
            return std::make_shared<PreCondition1610020232701>();
                break;
            case 1610639305524:
            return std::make_shared<PreCondition1610639305524>();
                break;
            case 1611825298622:
            return std::make_shared<PreCondition1611825298622>();
                break;
            case 1611825300188:
            return std::make_shared<PreCondition1611825300188>();
                break;
            case 1611825301669:
            return std::make_shared<PreCondition1611825301669>();
                break;
            case 1611825303063:
            return std::make_shared<PreCondition1611825303063>();
                break;
            case 1611825442338:
            return std::make_shared<PreCondition1611825442338>();
                break;
            case 1611825450624:
            return std::make_shared<PreCondition1611825450624>();
                break;
            case 1611825453928:
            return std::make_shared<PreCondition1611825453928>();
                break;
            case 1611825460491:
            return std::make_shared<PreCondition1611825460491>();
                break;
            default:
            std::cerr << "ConditionCreator: Unknown condition id requested: " << conditionConfId << std::endl;
            throw new std::exception();
            break;
        }
    }
}

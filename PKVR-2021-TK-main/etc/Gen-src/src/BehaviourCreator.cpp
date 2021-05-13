#include "BehaviourCreator.h"
#include "engine/BasicBehaviour.h"
#include "init.h"
#include "play.h"
#include "waitb.h"
#include "move.h"
#include "analysisObstacles.h"

namespace alica
{

    BehaviourCreator::BehaviourCreator()
    {
    }

    BehaviourCreator::~BehaviourCreator()
    {
    }

    std::shared_ptr<BasicBehaviour> BehaviourCreator::createBehaviour(long behaviourId)
    {
        switch(behaviourId)
        {
            case 1606386510762:
            return std::make_shared<init>();
            break;
            case 1606987675564:
            return std::make_shared<play>();
            break;
            case 1610020212179:
            return std::make_shared<waitb>();
            break;
            case 1611825595992:
            return std::make_shared<move>();
            break;
            case 1611833222383:
            return std::make_shared<analysisObstacles>();
            break;
            default:
            std::cerr << "BehaviourCreator: Unknown behaviour requested: " << behaviourId << std::endl;
            throw new std::exception();
            break;
        }
    }
}

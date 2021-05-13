#include "ConstraintCreator.h"

#include "constraints/main1606386348567Constraints.h"
#include "constraints/Game1606987272334Constraints.h"
#include "constraints/PlayPlan1611235901799Constraints.h"
#include "constraints/Motion1611825052624Constraints.h"
#include "constraints/DataAnalysis1611832940311Constraints.h"
#include "constraints/init1606386510762Constraints.h"
#include "constraints/play1606987675564Constraints.h"
#include "constraints/waitb1610020212179Constraints.h"
#include "constraints/move1611825595992Constraints.h"
#include "constraints/analysisObstacles1611833222383Constraints.h"

#include <iostream>

namespace alica
{

    ConstraintCreator::ConstraintCreator()
    {
    }

    ConstraintCreator::~ConstraintCreator()
    {
    }


    std::shared_ptr<BasicConstraint> ConstraintCreator::createConstraint(long constraintConfId)
    {
        switch(constraintConfId)
        {
            default:
            std::cerr << "ConstraintCreator: Unknown constraint requested: " << constraintConfId << std::endl;
            throw new std::exception();
            break;
        }
    }


}

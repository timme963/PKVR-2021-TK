#include "PlayPlan1611235901799.h"
/*PROTECTED REGION ID(eph1611235901799) ENABLED START*/
//Add additional options here
/*PROTECTED REGION END*/

namespace alica
{
    //Plan:PlayPlan
/** 
* Task: playentry  -> EntryPoint-ID: 1611824049184
 */
std::shared_ptr<UtilityFunction> UtilityFunction1611235901799::getUtilityFunction(Plan* plan)
{
   /*PROTECTED REGION ID(1611235901799) ENABLED START*/
   std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
   return defaultFunction;
    /*PROTECTED REGION END*/
}
}

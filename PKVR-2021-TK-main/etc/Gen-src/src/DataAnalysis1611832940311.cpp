#include "DataAnalysis1611832940311.h"
/*PROTECTED REGION ID(eph1611832940311) ENABLED START*/
//Add additional options here
/*PROTECTED REGION END*/

namespace alica
{
    //Plan:DataAnalysis
/** 
* Task: dataAnalysisEntry  -> EntryPoint-ID: 1611832986529
 */
std::shared_ptr<UtilityFunction> UtilityFunction1611832940311::getUtilityFunction(Plan* plan)
{
   /*PROTECTED REGION ID(1611832940311) ENABLED START*/
   std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
   return defaultFunction;
    /*PROTECTED REGION END*/
}
}

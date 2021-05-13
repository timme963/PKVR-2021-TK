#include "main1606386348567.h"
/*PROTECTED REGION ID(eph1606386348567) ENABLED START*/
//Add additional options here
#include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    //Plan:main
/** 
* Task: Start  -> EntryPoint-ID: 1606386400553
 */
std::shared_ptr<UtilityFunction> UtilityFunction1606386348567::getUtilityFunction(Plan* plan)
{
   /*PROTECTED REGION ID(1606386348567) ENABLED START*/
   std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
   return defaultFunction;
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1610639305524, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - init (1606386510762)
*
* Tasks in plan: 
*   - Start (1606386392812) (Entrypoint: 1606386400553)
*
* States in plan: 
*   - init (1606386414665)
*   - Start (1610639290819)
*
* Variables of preconditon:
*/
bool PreCondition1610639305524::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1610639305523) ENABLED START*/
            //std::cout << "The PreCondition 1610639305524 in Transition FrominitToStart is not implement yet!" << std::endl;
            alica_agent::model::WorldModel *wm = alica_agent::model::WorldModel::getInstance();
            if (wm->state == alica_agent::model::WorldModel::START_STATE){
                return true;
            }
            return false;
        
    /*PROTECTED REGION END*/
}
}

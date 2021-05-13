#include "Game1606987272334.h"
/*PROTECTED REGION ID(eph1606987272334) ENABLED START*/
//Add additional options here
#include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    //Plan:Game
/** 
* Task: Agent1  -> EntryPoint-ID: 1606988165164
* Task: Agent2  -> EntryPoint-ID: 1606988172203
 */
std::shared_ptr<UtilityFunction> UtilityFunction1606987272334::getUtilityFunction(Plan* plan)
{
   /*PROTECTED REGION ID(1606987272334) ENABLED START*/
   std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
   return defaultFunction;
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1610020227160, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - waitb (1610020212179)
*
* Tasks in plan: 
*   - Agent1 (1606987511335) (Entrypoint: 1606988165164)*   - Agent2 (1606987530363) (Entrypoint: 1606988172203)
*
* States in plan: 
*   - state2 (1606988174382)
*   - state1 (1606988175203)
*   - StartAgentA2 (1610020107554)
*   - StartAgentA1 (1610020109172)
*
* Variables of preconditon:
*/
bool PreCondition1610020227160::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1610020227157) ENABLED START*/
            alica_agent::model::WorldModel *wm = alica_agent::model::WorldModel::getInstance();
            if (wm->state == alica_agent::model::WorldModel::PLAY_STATE){
                return true;
            }
            return false;
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1610020232701, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - waitb (1610020212179)
*
* Tasks in plan: 
*   - Agent1 (1606987511335) (Entrypoint: 1606988165164)*   - Agent2 (1606987530363) (Entrypoint: 1606988172203)
*
* States in plan: 
*   - state2 (1606988174382)
*   - state1 (1606988175203)
*   - StartAgentA2 (1610020107554)
*   - StartAgentA1 (1610020109172)
*
* Variables of preconditon:
*/
bool PreCondition1610020232701::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1610020232699) ENABLED START*/
            //std::cout << "The PreCondition 1610020232701 in Transition Fromstate2ToStartAgentA1 is not implement yet!" << std::endl;
            alica_agent::model::WorldModel *wm = alica_agent::model::WorldModel::getInstance();
            if (wm->state == alica_agent::model::WorldModel::PLAY_STATE){
                return true;
            }
            return false;
    /*PROTECTED REGION END*/
}
}

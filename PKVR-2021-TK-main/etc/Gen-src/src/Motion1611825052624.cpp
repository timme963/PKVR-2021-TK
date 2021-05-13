#include "Motion1611825052624.h"
/*PROTECTED REGION ID(eph1611825052624) ENABLED START*/
//Add additional options here
#include "model/worldmodel.h"

namespace alica{
    bool MoveUtility::evaluateMove(alica_agent::model::WorldModel::Move move){
        alica_agent::model::WorldModel *wm = alica_agent::model::WorldModel::getInstance();
        if(wm->movecommand == move){
            return true;
        }
        return false;
    }
}
/*PROTECTED REGION END*/

namespace alica
{
    //Plan:Motion
/** 
* Task: motionEntry  -> EntryPoint-ID: 1611825099004
 */
std::shared_ptr<UtilityFunction> UtilityFunction1611825052624::getUtilityFunction(Plan* plan)
{
   /*PROTECTED REGION ID(1611825052624) ENABLED START*/
   std::shared_ptr<UtilityFunction> defaultFunction = std::make_shared<DefaultUtilityFunction>(plan);
   return defaultFunction;
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825298622, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825298622::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825298621) ENABLED START*/
        //std::cout << "The PreCondition 1611825298622 in Transition FromwaitStateToDefault Name is not implement yet!" << std::endl;
        //return false;
        return MoveUtility::evaluateMove(alica_agent::model::WorldModel::EAST);
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825300188, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825300188::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825300186) ENABLED START*/
        //std::cout << "The PreCondition 1611825300188 in Transition FromwaitStateToDefault Name is not implement yet!" << std::endl;
        //return false;
        return MoveUtility::evaluateMove(alica_agent::model::WorldModel::WEST);
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825301669, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825301669::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825301668) ENABLED START*/
        //std::cout << "The PreCondition 1611825301669 in Transition FromwaitStateToDefault Name is not implement yet!" << std::endl;
        //return false;
        return MoveUtility::evaluateMove(alica_agent::model::WorldModel::SOUTH);
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825303063, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825303063::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825303062) ENABLED START*/
        return MoveUtility::evaluateMove(alica_agent::model::WorldModel::NORTH);
        //alica_agent::model::WorldModel *wm = alica_agent::model::WorldModel::getInstance();
        //std::cout << "The PreCondition 1611825303063 in Transition FromwaitStateToDefault Name is not implement yet!" << std::endl;
        //if(wm->movecommand == alica_agent::model::WorldModel::NORTH){
    
        //}
        //return false;
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825460491, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - move (1611825595992)
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825460491::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825460489) ENABLED START*/
        //std::cout << "The PreCondition 1611825460491 in Transition FromeastStateTowaitState is not implement yet!" << std::endl;
        //return false;
        return !MoveUtility::evaluateMove(alica_agent::model::WorldModel::EAST);
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825453928, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - move (1611825595992)
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825453928::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825453927) ENABLED START*/
        //std::cout << "The PreCondition 1611825453928 in Transition FromwestStateTowaitState is not implement yet!" << std::endl;
        //return false;
        return !MoveUtility::evaluateMove(alica_agent::model::WorldModel::WEST);
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825450624, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - move (1611825595992)
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825450624::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825450623) ENABLED START*/
        //std::cout << "The PreCondition 1611825450624 in Transition FromsouthStateTowaitState is not implement yet!" << std::endl;
        //return false;
        return !MoveUtility::evaluateMove(alica_agent::model::WorldModel::SOUTH);
    /*PROTECTED REGION END*/
}
/**
* Outgoing transition:
*   - Name: 1611825442338, ConditionString: , Comment: MISSING_COMMENT
*
* Abstract plans in current state: 
*   - move (1611825595992)
*
* Tasks in plan: 
*   - motionEntry (1611825096453) (Entrypoint: 1611825099004)
*
* States in plan: 
*   - waitState (1611825103063)
*   - eastState (1611825289775)
*   - westState (1611825290960)
*   - southState (1611825291982)
*   - northState (1611825293816)
*
* Variables of preconditon:
*/
bool PreCondition1611825442338::evaluate(std::shared_ptr<RunningPlan> rp)
 {
    /*PROTECTED REGION ID(1611825442336) ENABLED START*/
        //std::cout << "The PreCondition 1611825442338 in Transition FromnorthStateTowaitState is not implement yet!" << std::endl;
        //return false;
        return !MoveUtility::evaluateMove(alica_agent::model::WorldModel::NORTH);
    /*PROTECTED REGION END*/
}
}

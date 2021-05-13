{
  "id" : 1606987272334,
  "name" : "Game",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1606988165164,
    "name" : "1606988165164",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 1,
    "task" : "taskRepo.tsk#1606987511335",
    "state" : 1606988175203,
    "plan" : 1606987272334
  }, {
    "id" : 1606988172203,
    "name" : "1606988172203",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 1,
    "task" : "taskRepo.tsk#1606987530363",
    "state" : 1606988174382,
    "plan" : 1606987272334
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1606988174382,
    "name" : "state2",
    "comment" : "",
    "entryPoint" : 1606988172203,
    "parentPlan" : 1606987272334,
    "abstractPlans" : [ "waitb.beh#1610020212179" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1610020227157 ],
    "inTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1606988175203,
    "name" : "state1",
    "comment" : "",
    "entryPoint" : 1606988165164,
    "parentPlan" : 1606987272334,
    "abstractPlans" : [ "waitb.beh#1610020212179" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1610020232699 ],
    "inTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1610020107554,
    "name" : "StartAgentA2",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1606987272334,
    "abstractPlans" : [ "play.beh#1606987675564", "Motion.pml#1611825052624", "DataAnalysis.pml#1611832940311" ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1610020227157 ]
  }, {
    "type" : "State",
    "id" : 1610020109172,
    "name" : "StartAgentA1",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1606987272334,
    "abstractPlans" : [ "play.beh#1606987675564", "Motion.pml#1611825052624", "DataAnalysis.pml#1611832940311" ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1610020232699 ]
  } ],
  "transitions" : [ {
    "id" : 1610020227157,
    "name" : "Fromstate2ToStartAgentA2",
    "comment" : "MISSING_COMMENT",
    "inState" : 1606988174382,
    "outState" : 1610020107554,
    "preCondition" : {
      "id" : 1610020227160,
      "name" : "1610020227160",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1610020232699,
    "name" : "Fromstate1ToStartAgentA1",
    "comment" : "MISSING_COMMENT",
    "inState" : 1606988175203,
    "outState" : 1610020109172,
    "preCondition" : {
      "id" : 1610020232701,
      "name" : "1610020232701",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}
{
  "id" : 1606386348567,
  "name" : "main",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1606386400553,
    "name" : "1606386400553",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 2147483647,
    "task" : "taskRepo.tsk#1606386392812",
    "state" : 1606386414665,
    "plan" : 1606386348567
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1606386414665,
    "name" : "init",
    "comment" : "",
    "entryPoint" : 1606386400553,
    "parentPlan" : 1606386348567,
    "abstractPlans" : [ "init.beh#1606386510762" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1610639305523 ],
    "inTransitions" : [ ]
  }, {
    "type" : "State",
    "id" : 1610639290819,
    "name" : "Start",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1606386348567,
    "abstractPlans" : [ "Game.pml#1606987272334" ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ 1610639305523 ]
  } ],
  "transitions" : [ {
    "id" : 1610639305523,
    "name" : "FrominitToStart",
    "comment" : "MISSING_COMMENT",
    "inState" : 1606386414665,
    "outState" : 1610639290819,
    "preCondition" : {
      "id" : 1610639305524,
      "name" : "1610639305524",
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
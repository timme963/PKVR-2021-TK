{
  "id" : 1611235901799,
  "name" : "PlayPlan",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1611824049184,
    "name" : "1611824049184",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 2147483647,
    "task" : "taskRepo.tsk#1611228803796",
    "state" : 1611235950465,
    "plan" : 1611235901799
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1611235950465,
    "name" : "Default Name",
    "comment" : "",
    "entryPoint" : 1611824049184,
    "parentPlan" : 1611235901799,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ ]
  } ],
  "transitions" : [ ],
  "synchronisations" : [ ]
}
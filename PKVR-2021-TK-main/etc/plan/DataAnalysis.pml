{
  "id" : 1611832940311,
  "name" : "DataAnalysis",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1611832986529,
    "name" : "1611832986529",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 2147483647,
    "task" : "taskRepo.tsk#1611832984305",
    "state" : 1611833062246,
    "plan" : 1611832940311
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1611833062246,
    "name" : "visionAnalysis",
    "comment" : "",
    "entryPoint" : 1611832986529,
    "parentPlan" : 1611832940311,
    "abstractPlans" : [ "analysisObstacles.beh#1611833222383" ],
    "variableBindings" : [ ],
    "outTransitions" : [ ],
    "inTransitions" : [ ]
  } ],
  "transitions" : [ ],
  "synchronisations" : [ ]
}
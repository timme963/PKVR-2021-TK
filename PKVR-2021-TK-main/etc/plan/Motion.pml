{
  "id" : 1611825052624,
  "name" : "Motion",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1611825099004,
    "name" : "1611825099004",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 2147483647,
    "task" : "taskRepo.tsk#1611825096453",
    "state" : 1611825103063,
    "plan" : 1611825052624
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1611825103063,
    "name" : "waitState",
    "comment" : "",
    "entryPoint" : 1611825099004,
    "parentPlan" : 1611825052624,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1611825298621, 1611825300186, 1611825301668, 1611825303062 ],
    "inTransitions" : [ 1611825442336, 1611825450623, 1611825453927, 1611825460489 ]
  }, {
    "type" : "State",
    "id" : 1611825289775,
    "name" : "eastState",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1611825052624,
    "abstractPlans" : [ "move.beh#1611825595992" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1611825460489 ],
    "inTransitions" : [ 1611825298621 ]
  }, {
    "type" : "State",
    "id" : 1611825290960,
    "name" : "westState",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1611825052624,
    "abstractPlans" : [ "move.beh#1611825595992" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1611825453927 ],
    "inTransitions" : [ 1611825300186 ]
  }, {
    "type" : "State",
    "id" : 1611825291982,
    "name" : "southState",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1611825052624,
    "abstractPlans" : [ "move.beh#1611825595992" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1611825450623 ],
    "inTransitions" : [ 1611825301668 ]
  }, {
    "type" : "State",
    "id" : 1611825293816,
    "name" : "northState",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1611825052624,
    "abstractPlans" : [ "move.beh#1611825595992" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1611825442336 ],
    "inTransitions" : [ 1611825303062 ]
  } ],
  "transitions" : [ {
    "id" : 1611825298621,
    "name" : "FromwaitStateToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825103063,
    "outState" : 1611825289775,
    "preCondition" : {
      "id" : 1611825298622,
      "name" : "1611825298622",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825300186,
    "name" : "FromwaitStateToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825103063,
    "outState" : 1611825290960,
    "preCondition" : {
      "id" : 1611825300188,
      "name" : "1611825300188",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825301668,
    "name" : "FromwaitStateToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825103063,
    "outState" : 1611825291982,
    "preCondition" : {
      "id" : 1611825301669,
      "name" : "1611825301669",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825303062,
    "name" : "FromwaitStateToDefault Name",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825103063,
    "outState" : 1611825293816,
    "preCondition" : {
      "id" : 1611825303063,
      "name" : "1611825303063",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825442336,
    "name" : "FromnorthStateTowaitState",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825293816,
    "outState" : 1611825103063,
    "preCondition" : {
      "id" : 1611825442338,
      "name" : "1611825442338",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825450623,
    "name" : "FromsouthStateTowaitState",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825291982,
    "outState" : 1611825103063,
    "preCondition" : {
      "id" : 1611825450624,
      "name" : "1611825450624",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825453927,
    "name" : "FromwestStateTowaitState",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825290960,
    "outState" : 1611825103063,
    "preCondition" : {
      "id" : 1611825453928,
      "name" : "1611825453928",
      "comment" : "",
      "enabled" : true,
      "conditionString" : null,
      "pluginName" : "DefaultPlugin",
      "variables" : [ ],
      "quantifiers" : [ ]
    },
    "synchronisation" : null
  }, {
    "id" : 1611825460489,
    "name" : "FromeastStateTowaitState",
    "comment" : "MISSING_COMMENT",
    "inState" : 1611825289775,
    "outState" : 1611825103063,
    "preCondition" : {
      "id" : 1611825460491,
      "name" : "1611825460491",
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
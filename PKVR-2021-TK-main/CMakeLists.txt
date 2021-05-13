cmake_minimum_required(VERSION 3.0.2)
project(alica_agent)

add_compile_options(-std=c++14)

set(CMAKE_BUILD_TYPE Debug)

find_package(
	catkin REQUIRED
	alica_engine
	alica_capnzero_proxy
	capnzero
	system_config
	id_capnzero
)

find_package(
	jsoncpp REQUIRED
)

find_package(
	PkgConfig REQUIRED
)

pkg_check_modules(JSONCPP jsoncpp)


catkin_package(
	INCLUDE_DIRS include
#  LIBRARIES 123
	CATKIN_DEPENDS
	alica_engine
	alica_capnzero_proxy
	capnzero
	system_config
	id_capnzero
#  DEPENDS system_lib
)

###########
## Build ##
###########

file(GLOB_RECURSE SOURCES "etc/Gen-src/src/*.cpp")
file(GLOB_RECURSE MODEL_SRC "src/model/*.cpp")


include_directories(
	include
	include/model
	etc/Gen-src/include
	${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} 
src/alica_agent.cpp

${SOURCES}
${MODEL_SRC}

)

target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
   pthread
   clingo
   ${JSONCPP_LIBRARIES}
)

link_libraries(
	${JSONCPP_LIBRARIES}

)

target_compile_definitions(${PROJECT_NAME} PUBLIC ZMQ_BUILD_DRAFT_API=1)

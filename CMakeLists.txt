cmake_minimum_required(VERSION 2.8.3)
project(pizza_owl_cpp)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
  roscpp
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES pizza_owl_cpp
#  CATKIN_DEPENDS roscpp
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare a C++ library
# add_library(pizza_owl_cpp
#   src/${PROJECT_NAME}/pizza_owl_cpp.cpp
# )

## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# add_dependencies(pizza_owl_cpp ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
# add_executable(pizza_owl_cpp_node src/pizza_owl_cpp_node.cpp)

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(pizza_owl_cpp_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(pizza_owl_cpp_node
#   ${catkin_LIBRARIES}
# )

#############
## Testing ##
#############

set(TEST_SRCS
  test/main.cpp
  test/${PROJECT_NAME}/property_restriction.cpp)

catkin_add_gtest(${PROJECT_NAME}-test ${TEST_SRCS})

if(TARGET ${PROJECT_NAME}-test)
  target_link_libraries(${PROJECT_NAME}-test ${catkin_LIBRARIES})
endif()

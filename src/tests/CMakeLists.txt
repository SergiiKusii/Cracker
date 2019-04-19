cmake_minimum_required(VERSION 2.8)

SET(PROJECT_CRACER_TEST CrackerTest)

project(${PROJECT_CRACER_TEST})

add_executable(${PROJECT_CRACER_TEST} CrackerTest.cpp)
target_link_libraries(${PROJECT_CRACER_TEST} ${Boost_LIBRARIES} Render CrackerLib)
add_test(NAME ${PROJECT_CRACER_TEST} COMMAND ${PROJECT_CRACER_TEST})

SET(PROJECT_UNHESHER_TEST UnhesherTest)
add_executable(UnhesherTest UnhesherTest.cpp)
target_link_libraries(${PROJECT_UNHESHER_TEST} ${Boost_LIBRARIES} Unhesher)
add_test(NAME ${PROJECT_UNHESHER_TEST} COMMAND ${PROJECT_UNHESHER_TEST})

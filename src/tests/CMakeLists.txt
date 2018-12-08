cmake_minimum_required(VERSION 2.8)

SET(PROJECT_CRACER_TEST CrackerTest)

project(${PROJECT_CRACER_TEST})

set(TEST_SOURCE CrackerTest.cpp )
add_executable(${PROJECT_CRACER_TEST} ${TEST_SOURCE})
target_link_libraries(${PROJECT_CRACER_TEST} ${Boost_LIBRARIES} "/usr/local/lib/libboost_unit_test_framework.a")

target_link_libraries(${PROJECT_CRACER_TEST} Shadow)
target_link_libraries(${PROJECT_CRACER_TEST} Unhesher)
target_link_libraries(${PROJECT_CRACER_TEST} Render)
target_link_libraries(${PROJECT_CRACER_TEST} CrackerLib)

add_test(NAME ${PROJECT_CRACER_TEST} COMMAND ${PROJECT_CRACER_TEST})
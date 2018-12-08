cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SOURCE_DIR}/cmake")
# set(CMAKE_INCLUDE_PATH "${CMAKE_INCLUDE_PATH} ${SOURCE_DIR}/shadow ${SOURCE_DIR}/unhesher")

set(MY_CXX_FLAGS  " -DBOOST_ERROR_CODE_HEADER_ONLY")
set(MY_EXE_LINKER_FLAGS  "-pthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MY_EXE_LINKER_FLAGS}")

#set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

include(cmake/version.cmake)

include_directories(${SOURCE_DIR}/common)
include_directories(${SOURCE_DIR}/shadow)
include_directories(${SOURCE_DIR}/unhesher)
include_directories(${SOURCE_DIR}/render)

add_subdirectory(shadow)
add_subdirectory(unhesher)
add_subdirectory(render)

set (MAIN_SOURCES
    main.cpp
    )

set (PRIVATE_CLASSES
    Cracker
    )

set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_executable (${PROJECT} ${MAIN_SOURCES} ${SOURCES})

target_link_libraries(${PROJECT} Shadow)
target_link_libraries(${PROJECT} Unhesher)
target_link_libraries(${PROJECT} Render)

include(cmake/third_party.cmake)

set_target_properties(${PROJECT} PROPERTIES VERSION "${${PROJECT}_VERSION}" SOVERSION "0")

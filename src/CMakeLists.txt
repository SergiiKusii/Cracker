cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 14)

OPTION(WITH_DEBUG_MODE "Build with debug mode" ON)

set (PROJECT Cracker)
project(${PROJECT})

set(ROOT_DIR "${CMAKE_SOURCE_DIR}/..")
set (BINARY_DIR  ${ROOT_DIR}/bin)
set (SOURCE_DIR ${ROOT_DIR}/src)
set (CMAKE_INCLUDE_PATH ${SOURCE_DIR})
# set (CMAKE_LIBRARY_PATH ${${PROJECT}_LIB_DIR})
set (EXECUTABLE_OUTPUT_PATH ${BINARY_DIR})
set (CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set (ERR_NO_UNIX "Cannot build on non Unix systems")

if ( WITH_DEBUG_MODE )
     ADD_DEFINITIONS( -D_DEBUG_MODE=1)
     set (CMAKE_BUILD_TYPE Debug)
endif()

if ( CMAKE_COMPILER_IS_GNUCXX )
    # set(MY_CXX_FLAGS  "-Wall -std=c++0x -fmessage-length=0 -v -L/usr/local/lib -L/usr/lib")
    # set(CMAKE_CXX_FLAGS "-O0 ${MY_CXX_FLAGS}")

    #set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
    #set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
else ()
    message (FATAL_ERROR ${ERR_NO_UNIX})
endif ()

include(cmake/version.cmake)

set (MAIN_SOURCES
    Cracker.cpp
    )

set (PRIVATE_CLASSES
    ShadowFile
    ShadowRow
    Cryper
    )

set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_executable (${PROJECT} ${MAIN_SOURCES} ${SOURCES})

include(cmake/third_party.cmake)

set_target_properties(${PROJECT} PROPERTIES VERSION "${${PROJECT}_VERSION}" SOVERSION "0")

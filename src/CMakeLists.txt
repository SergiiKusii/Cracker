cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

OPTION(WITH_DEBUG_MODE "Build with debug mode" ON)

set (PROJECT Cracker)
# project(Cracker)
set ("${PROJECT}_BINARY_DIR"  bin)
set ("${PROJECT}_SOURCE_DIR" src)
set (CMAKE_INCLUDE_PATH ${${PROJECT}_SOURCE_DIR})
# set (CMAKE_LIBRARY_PATH ${${PROJECT}_LIB_DIR})
set (EXECUTABLE_OUTPUT_PATH ${${PROJECT}_BINARY_DIR})
set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_BUILD_TYPE Debug)

set (ERR_NO_UNIX "Cannot build on non Unix systems")

if ( WITH_DEBUG_MODE )
     ADD_DEFINITIONS( -D_DEBUG_MODE=1)
endif()

if ( CMAKE_COMPILER_IS_GNUCXX )
    # set(MY_CXX_FLAGS  "-Wall -std=c++0x -fmessage-length=0 -v -L/usr/local/lib -L/usr/lib")
    # set(CMAKE_CXX_FLAGS "-O0 ${MY_CXX_FLAGS}")

    #set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-reorder-blocks -fno-schedule-insns -fno-inline")
    #set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
else ()
    message (FATAL_ERROR ${ERR_NO_UNIX})
endif ()

set ("${PROJECT}_VERSION_MAJ" 0)
set ("${PROJECT}_VERSION_MIN" 1)
set ("${PROJECT}_VERSION_A" 1)
set ("${PROJECT}_VERSION_B" 1)
set ("${PROJECT}_VERSION" ${${PROJECT}_VERSION_MAJ}0${${PROJECT}_VERSION_MIN}0${${PROJECT}_VERSION_A}0${${PROJECT}_VERSION_B})

message(STATUS ${${PROJECT}_VERSION})

set (TARGETS "")

set (HEADERS "")

set (MAIN_SOURCES
    Cracker.cpp
    )

set (PRIVATE_CLASSES
    ShadowFile
    ShadowRow
    Logger
    )

SET (HEADERS_ONLY)

set (PUBLIC_CLASSES)

set (ADDITIONAL_LIBRARIES)

set (PUBLIC_HEADERS)
set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
    LIST (APPEND HEADERS ${class}.h)
endforeach ()

# foreach (class ${HEADERS_ONLY})
#     LIST (APPEND HEADERS ${class}.h)
# endforeach ()
    
# foreach (class ${PUBLIC_CLASSES})
#     LIST (APPEND SOURCES ${class}.cpp)
#     LIST (APPEND HEADERS ../include/${PROJECT}/${class}.hpp)
#     LIST (APPEND PUBLIC_HEADERS ../include/${PROJECT}/${class}.hpp)
# endforeach ()

add_executable (${PROJECT} ${MAIN_SOURCES} ${SOURCES})

# target_link_libraries (${PROJECT} ${ADDITIONAL_LIBRARIES})

set_target_properties(${PROJECT} PROPERTIES VERSION "${${PROJECT}_VERSION}" SOVERSION "0")

# INSTALL (
#     TARGETS
#     ${PROJECT}
#     DESTINATION
#     lib${LIB_SUFFIX}
# )

# INSTALL (
#     FILES
#     ${PUBLIC_HEADERS}
#     DESTINATION
#     include/${PROJECT}
# )

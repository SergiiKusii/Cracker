cmake_minimum_required(VERSION 2.8)

set (PROJECT Cracker)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 14)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif ()

set(ROOT_DIR "${CMAKE_SOURCE_DIR}")
set(BINARY_DIR  ${ROOT_DIR}/bin/${CMAKE_BUILD_TYPE})
set(LIB_DIR "${ROOT_DIR}/lib/${CMAKE_BUILD_TYPE}")
set(SOURCE_DIR ${ROOT_DIR}/src)

set(CMAKE_INCLUDE_PATH ${SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LIB_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LIB_DIR}")
# set (CMAKE_LIBRARY_PATH ${${PROJECT}_LIB_DIR})
set (EXECUTABLE_OUTPUT_PATH ${BINARY_DIR})
set (CMAKE_VERBOSE_MAKEFILE ON)

set (ERR_NO_UNIX "Cannot build on non Unix systems")
if (NOT CMAKE_COMPILER_IS_GNUCXX )
    message (FATAL_ERROR ${ERR_NO_UNIX})
endif ()

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)


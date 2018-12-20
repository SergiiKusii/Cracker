#crypto++
# find_package(CryptoPP REQUIRED)

#plog
set(PLOG_INCLUDE_DIRS ${SOURCE_DIR}/plog/include)
message(STATUS ${PLOG_INCLUDE_DIRS})
include_directories(${PLOG_INCLUDE_DIRS})

#boost 1.66 required
# set(BOOST_ROOT "/home/sergii/mnt/DEXT4/packages/boost_1_66_0/" CACHE PATH "Boost library path" )
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.66 REQUIRED COMPONENTS unit_test_framework program_options)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
else()
    message(FATAL_ERROR "Boost is not found")
endif()

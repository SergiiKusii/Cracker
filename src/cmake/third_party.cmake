#crypto++
find_package(CryptoPP REQUIRED)

#plog
set(PLOG_INCLUDE_DIRS ${SOURCE_DIR}/plog/include)
message(STATUS ${PLOG_INCLUDE_DIRS})
include_directories(${PLOG_INCLUDE_DIRS})


#boost 1.66 required
# include(FindBoost)
# set(Boost_USE_STATIC_LIBS ON)
# find_package(Boost 1.66 REQUIRED COMPONENTS system filesystem thread program_options iostreams)
# find_package(Boost REQUIRED) 
# if(Boost_FOUND)
#     include_directories(${Boost_INCLUDE_DIRS}) 
#     target_link_libraries(${PROJECT} ${Boost_LIBRARIES})
# else()
#     message(FATAL_ERROR "Boost is not found")
# endif()
#crypto++
find_package(CryptoPP REQUIRED)
target_link_libraries(${PROJECT} cryptopp)

#plog
set(PLOG_INCLUDE_DIRS ${SOURCE_DIR}/plog/include)
message(STATUS ${PLOG_INCLUDE_DIRS})
target_include_directories(${PROJECT}
    PUBLIC ${PLOG_INCLUDE_DIRS}
    )


#boost 1.66 required
# find_package(Boost REQUIRED) 
# if(Boost_FOUND)
#     include_directories(${Boost_INCLUDE_DIRS}) 
#     target_link_libraries(${PROJECT} ${Boost_LIBRARIES})
# else()
#     message(FATAL_ERROR "Boost is not found")
# endif()
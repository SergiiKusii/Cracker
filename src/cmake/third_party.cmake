find_package(CryptoPP REQUIRED)
target_link_libraries(${PROJECT} cryptopp)

set(PLOG_INCLUDE_DIRS ${SOURCE_DIR}/plog/include)
message(STATUS ${PLOG_INCLUDE_DIRS})
target_include_directories(${PROJECT}
    PUBLIC ${PLOG_INCLUDE_DIRS}
    )
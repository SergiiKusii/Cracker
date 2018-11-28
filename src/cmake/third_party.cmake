find_package(CryptoPP REQUIRED)
target_link_libraries(${PROJECT} cryptopp)

set(PLOG_INCLUDE_DIRS ${${PROJECT}_SOURCE_DIR}/plog/include)
target_include_directories(${PROJECT}
    PUBLIC ${PLOG_INCLUDE_DIRS}
    )
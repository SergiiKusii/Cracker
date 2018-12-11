cmake_minimum_required(VERSION 2.8)

set (PROJECT_CRACKER CrackerLib)
project(${PROJECT_CRACKER})

set (PRIVATE_CLASSES
    Cracker
    )

set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_library (${PROJECT_CRACKER} STATIC ${SOURCES})

target_link_libraries(${PROJECT_CRACKER} Unhesher)
target_link_libraries(${PROJECT_CRACKER} Render)
target_link_libraries(${PROJECT_CRACKER} ${Boost_LIBRARIES})
cmake_minimum_required(VERSION 2.8)

set (PROJECT_UNHESHER Unhesher)
project(${PROJECT_UNHESHER})

set (PRIVATE_CLASSES
    UnhesherBase
    UnhesherNative
    UnhesherFabrica
    )

set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_library (${PROJECT_UNHESHER} STATIC ${SOURCES})

target_link_libraries(${PROJECT_UNHESHER} crypt)
# target_link_libraries(${PROJECT_UNHESHER} cryptopp)


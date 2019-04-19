cmake_minimum_required(VERSION 2.8)

set (PROJECT_SHADOW Shadow)
project(${PROJECT_SHADOW})

set (PRIVATE_CLASSES
    ShadowFile
    ShadowRow
    )

set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_library (${PROJECT_SHADOW} STATIC ${SOURCES})

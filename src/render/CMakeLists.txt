cmake_minimum_required(VERSION 2.8)

set (PROJECT_RENDER Render)
project(${PROJECT_RENDER})

set (PRIVATE_CLASSES
    ConsoleRender
    ProgressBar
    )

set (SOURCES)

foreach (class ${PRIVATE_CLASSES})
    LIST (APPEND SOURCES ${class}.cpp)
endforeach ()

add_library (${PROJECT_RENDER} STATIC ${SOURCES})
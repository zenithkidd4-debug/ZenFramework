cmake_minimum_required(VERSION 3.20)

project(
    ZenFramework
    VERSION 1.0.0
    DESCRIPTION "Modern C++ Framework"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(zenframework
    src/Logger.cpp
    src/Timer.cpp
    src/FileSystem.cpp
)

target_include_directories(zenframework
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(logger_example
    examples/logger_example.cpp
)
add_executable(timer_example
    examples/timer_example.cpp
)
add_executable(filesystem_example
    examples/filesystem_example.cpp
)

target_link_libraries(filesystem_example
    PRIVATE
        zenframework
)
target_link_libraries(timer_example
    PRIVATE
        zenframework
)
target_link_libraries(logger_example
    PRIVATE
        zenframework)

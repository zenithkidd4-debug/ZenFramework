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
)

target_include_directories(zenframework
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(logger_example
    examples/logger_example.cpp
)

target_link_libraries(logger_example
    PRIVATE
        zenframework)

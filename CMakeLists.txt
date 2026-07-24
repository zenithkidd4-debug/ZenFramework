cmake_minimum_required(VERSION 3.16)

project(ZenFramework VERSION 1.0.0 LANGUAGES CXX)

# ==========================================
# C++ Standard
# ==========================================

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ==========================================
# Dependencies
# ==========================================

find_package(nlohmann_json CONFIG REQUIRED)
find_package(SQLite3 REQUIRED)
find_package(CURL REQUIRED)

# ==========================================
# ZenFramework Library
# ==========================================

add_library(zenframework
    src/Application.cpp
    src/Config.cpp
    src/Database.cpp
    src/EventDispatcher.cpp
    src/FileSystem.cpp
    src/HttpClient.cpp
    src/Logger.cpp
    src/String.cpp
    src/ThreadPool.cpp
    src/Timer.cpp
)

target_include_directories(zenframework
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(zenframework
    PUBLIC
        nlohmann_json::nlohmann_json
        SQLite::SQLite3
        CURL::libcurl
)

# ==========================================
# Examples
# ==========================================

add_executable(application_example
    examples/application_example.cpp
)
target_link_libraries(application_example PRIVATE zenframework)

add_executable(config_example
    examples/config_example.cpp
)
target_link_libraries(config_example PRIVATE zenframework)

add_executable(database_example
    examples/database_example.cpp
)
target_link_libraries(database_example PRIVATE zenframework)

add_executable(event_example
    examples/event_example.cpp
)
target_link_libraries(event_example PRIVATE zenframework)

add_executable(filesystem_example
    examples/filesystem_example.cpp
)
target_link_libraries(filesystem_example PRIVATE zenframework)

add_executable(http_example
    examples/http_example.cpp
)
target_link_libraries(http_example PRIVATE zenframework)

add_executable(logger_example
    examples/logger_example.cpp
)
target_link_libraries(logger_example PRIVATE zenframework)

add_executable(string_example
    examples/string_example.cpp
)
target_link_libraries(string_example PRIVATE zenframework)

add_executable(threadpool_example
    examples/threadpool_example.cpp
)
target_link_libraries(threadpool_example PRIVATE zenframework)

add_executable(timer_example
    examples/timer_example.cpp
)
target_link_libraries(timer_example PRIVATE zenframework)

# ==========================================
# Optional Testing
# ==========================================

enable_testing()

# Uncomment when tests are added
# add_subdirectory(tests)

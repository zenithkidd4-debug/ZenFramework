# ZenFramework

A modern, lightweight, modular C++20 framework for building high-performance applications.

## Features

- Application Framework
- Logger
- Timer
- FileSystem
- String Utilities
- JSON Configuration
- SQLite Database
- HTTP Client (libcurl)
- ThreadPool
- Event System

## Requirements

- C++20
- CMake 3.16+
- vcpkg
- libcurl
- SQLite3
- nlohmann-json

## Build

```bash
git clone https://github.com/zenithkidd4-debug/ZenFramework.git
cd ZenFramework

mkdir build
cd build

cmake .. \
  -DCMAKE_TOOLCHAIN_FILE=<vcpkg>/scripts/buildsystems/vcpkg.cmake \
  -DVCPKG_TARGET_TRIPLET=arm-linux

cmake --build .
```

## Examples

Logger

```cpp
zen::Logger::info("Hello ZenFramework!");
```

Timer

```cpp
zen::Timer timer;
timer.start();
```

HTTP Client

```cpp
zen::HttpClient client;
std::string body = client.get("https://httpbin.org/get");
```

Event System

```cpp
zen::EventDispatcher dispatcher;

dispatcher.subscribe("Start", [](const zen::Event&)
{
    std::cout << "Started!" << std::endl;
});

dispatcher.emit(zen::Event("Start"));
```

ThreadPool

```cpp
zen::ThreadPool pool(4);

pool.enqueue([]()
{
    std::cout << "Running task..." << std::endl;
});
```

## Project Structure

```
ZenFramework/
├── include/
├── src/
├── examples/
├── tests/
├── docs/
├── third_party/
└── CMakeLists.txt
```

## Roadmap

- ✅ v1.0 Core Framework
- 🔜 TCP Networking
- 🔜 HTTP Server
- 🔜 Plugin System
- 🔜 CLI Framework
- 🔜 Testing Framework
- 🔜 Benchmark Suite

## License

MIT License

## Author

Asavela Thwani

GitHub:
https://github.com/zenithkidd4-debug

#include <sstream>
#include <zen/Logger.hpp>

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

namespace {

std::string currentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm* tm = std::localtime(&t);

    std::ostringstream oss;
    oss << std::put_time(tm, "%H:%M:%S");

    return oss.str();
}

}

namespace zen {

void Logger::log(const std::string& level,
                 const std::string& color,
                 const std::string& message)
{
    std::cout
        << color
        << "[" << currentTime() << "] "
        << "[" << level << "] "
        << message
        << "\033[0m"
        << std::endl;
}

void Logger::info(const std::string& message)
{
    log("INFO", "\033[32m", message);
}

void Logger::warn(const std::string& message)
{
    log("WARN", "\033[33m", message);
}

void Logger::error(const std::string& message)
{
    log("ERROR", "\033[31m", message);
}

}

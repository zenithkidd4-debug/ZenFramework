#pragma once

#include <string>

namespace zen {

class Logger {
public:
    static void info(const std::string& message);
    static void warn(const std::string& message);
    static void error(const std::string& message);

private:
    static void log(const std::string& level,
                    const std::string& color,
                    const std::string& message);
};

} // namespace zen

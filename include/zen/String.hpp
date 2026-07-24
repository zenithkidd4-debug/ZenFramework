#pragma once

#include <string>
#include <vector>

namespace zen {

class String {
public:
    static std::string toUpper(const std::string& str);
    static std::string toLower(const std::string& str);
    static std::string trim(const std::string& str);

    static std::vector<std::string> split(
        const std::string& str,
        char delimiter);

    static std::string replaceAll(
        std::string str,
        const std::string& from,
        const std::string& to);
};

} // namespace zen

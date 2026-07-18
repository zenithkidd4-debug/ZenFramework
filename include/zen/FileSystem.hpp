#pragma once

#include <string>
#include <vector>

namespace zen {

class FileSystem {
public:
    // Check if a file or directory exists
    static bool exists(const std::string& path);

    // Create a directory (including parent directories)
    static bool createDirectory(const std::string& path);

    // Remove a file or directory
    static bool remove(const std::string& path);

    // List all files in a directory
    static std::vector<std::string> listFiles(const std::string& path);

    // Write text to a file
    static bool writeTextFile(const std::string& path,
                              const std::string& text);

    // Read text from a file
    static std::string readTextFile(const std::string& path);
};

} // namespace zen

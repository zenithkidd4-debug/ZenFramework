#include <zen/FileSystem.hpp>

#include <filesystem>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

namespace zen {

bool FileSystem::exists(const std::string& path) {
    return fs::exists(path);
}

bool FileSystem::createDirectory(const std::string& path) {
    return fs::create_directories(path);
}

bool FileSystem::remove(const std::string& path) {
    return fs::remove_all(path) > 0;
}

std::vector<std::string> FileSystem::listFiles(const std::string& path) {
    std::vector<std::string> files;

    if (!fs::exists(path))
        return files;

    for (const auto& entry : fs::directory_iterator(path)) {
        files.push_back(entry.path().filename().string());
    }

    return files;
}

bool FileSystem::writeTextFile(const std::string& path,
                               const std::string& text) {
    std::ofstream file(path);

    if (!file)
        return false;

    file << text;
    return true;
}

std::string FileSystem::readTextFile(const std::string& path) {
    std::ifstream file(path);

    if (!file)
        return "";

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

} // namespace zen

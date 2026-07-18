#include <zen/FileSystem.hpp>

#include <iostream>

int main() {
    // Create a directory
    zen::FileSystem::createDirectory("data");

    // Write a text file
    if (zen::FileSystem::writeTextFile(
            "data/test.txt",
            "Welcome to ZenFramework!")) {
        std::cout << "File written successfully.\n";
    }

    // Read the file
    std::cout << "\nFile contents:\n";
    std::cout << zen::FileSystem::readTextFile("data/test.txt") << '\n';

    // List files
    std::cout << "\nFiles in data directory:\n";

    auto files = zen::FileSystem::listFiles("data");

    for (const auto& file : files) {
        std::cout << " - " << file << '\n';
    }

    return 0;
}

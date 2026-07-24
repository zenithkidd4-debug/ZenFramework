#include <zen/String.hpp>

#include <iostream>

int main() {
    std::string text = "   Hello World   ";

    std::cout << "Original: [" << text << "]\n";
    std::cout << "Trimmed : [" << zen::String::trim(text) << "]\n";

    std::cout << "\nUpper: "
              << zen::String::toUpper("Hello World") << '\n';

    std::cout << "Lower: "
              << zen::String::toLower("Hello World") << '\n';

    std::cout << "\nReplace:\n";
    std::cout << zen::String::replaceAll(
        "Welcome to ZenFramework",
        "ZenFramework",
        "C++"
    ) << '\n';

    std::cout << "\nSplit:\n";

    auto words = zen::String::split("One,Two,Three,Four", ',');

    for (const auto& word : words) {
        std::cout << word << '\n';
    }

    return 0;
}

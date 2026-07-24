#include <zen/Config.hpp>

#include <iostream>

int main() {
    zen::Config config("config.json");

    config.set("name", "ZenFramework");
    config.set("version", "0.5.0");
    config.set("debug", true);
    config.set("max_users", 100);

    if (config.save()) {
        std::cout << "Configuration saved successfully.\n";
    }

    zen::Config loaded("config.json");

    if (loaded.load()) {
        std::cout << "\nConfiguration loaded:\n";
        std::cout << "Name: " << loaded.getString("name") << '\n';
        std::cout << "Version: " << loaded.getString("version") << '\n';
        std::cout << "Debug: "
                  << std::boolalpha
                  << loaded.getBool("debug") << '\n';
        std::cout << "Max Users: "
                  << loaded.getInt("max_users") << '\n';
    }

    return 0;
}

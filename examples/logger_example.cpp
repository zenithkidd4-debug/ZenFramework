#include <zen/Logger.hpp>

int main()
{
    zen::Logger::info("Welcome to ZenFramework!");
    zen::Logger::warn("This is a warning.");
    zen::Logger::error("Something went wrong.");

    return 0;
}

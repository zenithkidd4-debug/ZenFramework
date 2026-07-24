#include <zen/EventDispatcher.hpp>

#include <iostream>

int main()
{
    zen::EventDispatcher dispatcher;

    dispatcher.subscribe("ApplicationStart",
        [](const zen::Event& event)
        {
            std::cout << "Received Event: "
                      << event.name()
                      << std::endl;
        });

    dispatcher.subscribe("ApplicationStart",
        [](const zen::Event&)
        {
            std::cout << "Initializing modules..."
                      << std::endl;
        });

    dispatcher.subscribe("ApplicationExit",
        [](const zen::Event&)
        {
            std::cout << "Shutting down..."
                      << std::endl;
        });

    dispatcher.emit(zen::Event("ApplicationStart"));

    std::cout << std::endl;

    dispatcher.emit(zen::Event("ApplicationExit"));

    return 0;
}

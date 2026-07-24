#include <zen/Application.hpp>

#include <iostream>

class MyApplication : public zen::Application
{
public:
    void initialize() override
    {
        std::cout << "ZenFramework v1.0" << std::endl;
        std::cout << "Initializing application..." << std::endl;
    }

    void update() override
    {
        std::cout << "Application is running..." << std::endl;
    }

    void shutdown() override
    {
        std::cout << "Shutting down application..." << std::endl;
    }
};

int main()
{
    MyApplication app;
    app.run();

    return 0;
}

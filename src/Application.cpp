#include <zen/Application.hpp>

namespace zen {

void Application::initialize()
{
    // Default implementation
}

void Application::update()
{
    // Default implementation
}

void Application::shutdown()
{
    // Default implementation
}

void Application::run()
{
    initialize();
    update();
    shutdown();
}

} // namespace zen

#pragma once

namespace zen {

class Application {
public:
    virtual ~Application() = default;

    virtual void initialize();
    virtual void update();
    virtual void shutdown();

    void run();
};

} // namespace zen

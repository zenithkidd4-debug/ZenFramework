#include <zen/Timer.hpp>

#include <iostream>
#include <thread>

int main() {
    zen::Timer timer;

    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    std::cout << "Milliseconds: "
              << timer.elapsedMilliseconds()
              << '\n';

    std::cout << "Seconds: "
              << timer.elapsedSeconds()
              << '\n';

    return 0;
}

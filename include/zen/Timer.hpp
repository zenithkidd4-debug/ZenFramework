#pragma once

#include <chrono>

namespace zen {

class Timer {
public:
    Timer();

    void reset();

    double elapsedMilliseconds() const;
    double elapsedSeconds() const;

private:
    std::chrono::high_resolution_clock::time_point m_start;
};

} // namespace zen

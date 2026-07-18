#include <zen/Timer.hpp>

namespace zen {

Timer::Timer() {
    reset();
}

void Timer::reset() {
    m_start = std::chrono::high_resolution_clock::now();
}

double Timer::elapsedMilliseconds() const {
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double, std::milli>(
        end - m_start
    ).count();
}

double Timer::elapsedSeconds() const {
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration<double>(
        end - m_start
    ).count();
}

} // namespace zen

#include "Timer.h"

#include <chrono>

namespace shl {
    uint64_t Timer::millis()
    {
        uint64_t ms = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
        return ms;
    }

    uint64_t Timer::micros()
    {
        uint64_t us = std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
        return us;
    }

    uint64_t Timer::nanos()
    {
        uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch())
            .count();
        return ns;
    }
}
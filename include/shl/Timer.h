#pragma once

#include <stdint.h>

namespace shl {
    class Timer {
    private:
        uint64_t time;
    public:
        Timer()
        {
            time = nanos();
        }
        static uint64_t millis();

        // Get time stamp in microseconds.
        static uint64_t micros();

        // Get time stamp in nanoseconds.
        static uint64_t nanos();

        void reset()
        {
            time = nanos();
        }
        uint64_t currentNanos()
        {
            uint64_t current = nanos();
            return current - time;
        }
        double currentMicros()
        {
            uint64_t current = nanos();
            return (current - time) / (double)1.0E3;
        }
        double currentMillis()
        {
            uint64_t current = nanos();
            return (current - time) / (double)1.0E6;
        }
        double currentSeconds()
        {
            uint64_t current = nanos();
            return (current - time) / (double)1.0E9;
        }
        uint64_t ellapsedNanos()
        {
            uint64_t current = nanos();
            uint64_t ellapsed = current - time;
            time = current;
            return ellapsed;
        }
        double ellapsedMicros()
        {
            return (double)ellapsedNanos() / (double)1.0E3;
        }
        double ellapsedMillis()
        {
            return (double)ellapsedNanos() / (double)1.0E6;
        }
        double ellapsedSeconds()
        {
            return (double)ellapsedNanos() / (double)1.0E9;
        }
    };
}


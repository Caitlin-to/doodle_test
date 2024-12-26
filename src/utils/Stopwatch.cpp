//
// Created by Caitlin To on 18/11/2024.
//

#include "Stopwatch.h"

Stopwatch& Stopwatch::getInstance() {
    static Stopwatch instance;
    return instance;
}

void Stopwatch::start() {
    // gets the current time
    startTime = std::chrono::high_resolution_clock ::now();
}

float Stopwatch::getElapsedTime() {
    auto now = std::chrono::high_resolution_clock::now();
    // time between start and now
    std::chrono::duration<float> duration = now - startTime;
    return duration.count(); // elapsed time in seconds
}

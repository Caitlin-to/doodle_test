//
// Created by Caitlin To on 18/11/2024.
//

#ifndef DOODLEJUMP_STOPWATCH_H
#define DOODLEJUMP_STOPWATCH_H

#include <chrono>

class Stopwatch {

public:
    // only one
    static Stopwatch& getInstance();
    void start();
    float getElapsedTime();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;

};


#endif //DOODLEJUMP_STOPWATCH_H

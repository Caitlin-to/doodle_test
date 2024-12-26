//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_SCORETRACKER_H
#define DOODLEJUMP_SCORETRACKER_H

#include <chrono>
#include <iostream>

class ScoreTracker {
public:
    ScoreTracker();
    void increment(int amount);
    void reset();
    int getScore() const;
    void displayScore() const;

private:
    int score;
};

#endif //DOODLEJUMP_SCORETRACKER_H

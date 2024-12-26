//
// Created by Caitlin To on 18/12/2024.
//

#include "ScoreTracker.h"

ScoreTracker::ScoreTracker()
        : score(0){}

void ScoreTracker::increment(int amount) {
    score += amount;
}

void ScoreTracker::reset() {
    score = 0;
}

int ScoreTracker::getScore() const {
    return score;
}

void ScoreTracker::displayScore() const {
    std::cout << "Current Score: " << score << std::endl;
}
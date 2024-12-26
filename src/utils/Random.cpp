//
// Created by Caitlin To on 20/11/2024.
//

#include "Random.h"

// random engine and seed
std::random_device rd;
std::mt19937 gen(rd());

int Random::getInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

float Random::getFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(gen);
}

bool Random::getBool() {
    std::uniform_int_distribution dist(0, 1);
    return dist(gen);
}
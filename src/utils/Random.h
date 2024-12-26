//
// Created by Caitlin To on 20/11/2024.
//

#ifndef DOODLEJUMP_RANDOM_H
#define DOODLEJUMP_RANDOM_H

#include <iostream>
#include <cstdlib>
#include <random>

class Random {

public:
    static int getInt(int min, int max);
    static float getFloat(float min, float max);
    static bool getBool();

};


#endif //DOODLEJUMP_RANDOM_H

//
// Created by Caitlin To on 25/12/2024.
//

#ifndef DOODLEJUMP_JETPACK_H
#define DOODLEJUMP_JETPACK_H


#include "Settings.h"

class Jetpack {
public:
    Jetpack();
    float getJetpackForce() const;
private:
    float jetpackForce;
};

#endif //DOODLEJUMP_JETPACK_H

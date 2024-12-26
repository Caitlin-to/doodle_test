//
// Created by Caitlin To on 25/12/2024.
//

#ifndef DOODLEJUMP_SPRING_H
#define DOODLEJUMP_SPRING_H

#include "Settings.h"

class Spring {
public:
    Spring();
    float getSpringForce() const;
private:
    float springForce;
};


#endif //DOODLEJUMP_SPRING_H

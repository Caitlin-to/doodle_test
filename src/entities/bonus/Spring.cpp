//
// Created by Caitlin To on 25/12/2024.
//

#include "Spring.h"

Spring::Spring(){
    springForce = -20.0f / settings::resolutionHeight;
}

float Spring::getSpringForce() const {
    return springForce;
}
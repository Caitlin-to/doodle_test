//
// Created by Caitlin To on 25/12/2024.
//

#include "Jetpack.h"
// jetpack is secretly a rocket

Jetpack::Jetpack() {
    jetpackForce = -35.0f / settings::resolutionHeight;
}

float Jetpack::getJetpackForce() const {
    return jetpackForce;
}
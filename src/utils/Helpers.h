//
// Created by Caitlin To on 03/12/2024.
//

#ifndef DOODLEJUMP_HELPERS_H
#define DOODLEJUMP_HELPERS_H

#include <vector>
#include <array>
#include "../world/World.h"
#include "SFML/Graphics.hpp"
#include "../Settings.h"
#pragma once

namespace CoordinateUtils {
    sf::Vector2f normalizedToWindow(std::array<float, 2> pos);
}


#endif //DOODLEJUMP_HELPERS_H

//
// Created by Caitlin To on 03/12/2024.
//

#include "Helpers.h"

#include <iostream>
namespace CoordinateUtils {


    sf::Vector2f normalizedToWindow(std::array<float, 2> pos) {
        float windowX = (pos[0] != 0) ? settings::resolutionWidth * pos[0] : 0;
        float windowY = (pos[1] != 0) ? settings::resolutionHeight * pos[1] : 0;
        // std::cout << windowX << ',' << windowY << std::endl;
        return sf::Vector2f(windowX, windowY);
    }
}
//
// Created by Caitlin To on 18/12/2024.
//

#include "HorizontalTile.h"

HorizontalTile::HorizontalTile(const std::array<float, 2>& position)
        : Tile(position, {36, 93, 237}) {} // blue



void HorizontalTile::update(float deltaTime) {
    std::array<float, 2> currentPosition = getPosition();
    float movement = velocity * deltaTime;

    if (movingRight) {
        currentPosition[0] += movement;
        if (currentPosition[0] >= movementBounds[1]) { // reverse direction when hitting the right bound
            movingRight = false;
        }
    } else {
        currentPosition[0] -= movement;
        if (currentPosition[0] <= movementBounds[0]) { // reverse direction when hitting the left bound
            movingRight = true;
        }
    }

    setPosition(currentPosition);
}
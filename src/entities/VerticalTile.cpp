//
// Created by Caitlin To on 18/12/2024.
//

#include "VerticalTile.h"


VerticalTile::VerticalTile(const std::array<float, 2>& position, float minY, float maxY)
        : Tile(position, {255, 255, 0}), minY(minY), maxY(maxY), initialY(position[1]) {}  // Store the initial Y position

void VerticalTile::update(float deltaTime) {
    std::array<float, 2> currentPosition = getPosition();
    float movement = velocity * deltaTime;  // Movement per frame

    // Move the tile up or down based on the direction, relative to the initial Y position
    if (movingUp) {
        currentPosition[1] += movement;
        if (currentPosition[1] >= initialY + maxY) {  // Reverse direction if it reaches the upper bound
            movingUp = false;
        }
    } else {
        currentPosition[1] -= movement;
        if (currentPosition[1] <= initialY - minY) {  // Reverse direction if it reaches the lower bound
            movingUp = true;
        }
    }

    setPosition(currentPosition);  // Update the tile's position
}
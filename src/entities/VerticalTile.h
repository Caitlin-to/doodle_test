//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_VERTICALTILE_H
#define DOODLEJUMP_VERTICALTILE_H

#include "Tile.h"
#include "../utils/Random.h"

class VerticalTile : public Tile {
public:
    VerticalTile(const std::array<float, 2>& position, float minY, float maxY);  // Constructor with min/max Y
    void update(float deltaTime) override;

private:
    bool movingUp = Random::getBool();
    float velocity = 0.15f;  // Speed of movement (adjust as needed)
    float minY;             // Minimum Y position (lower bound relative to spawn)
    float maxY;             // Maximum Y position (upper bound relative to spawn)
    float initialY;         // The initial Y position when the tile is created
};



#endif //DOODLEJUMP_VERTICALTILE_H

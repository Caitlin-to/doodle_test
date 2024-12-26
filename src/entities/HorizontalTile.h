//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_HORIZONTALTILE_H
#define DOODLEJUMP_HORIZONTALTILE_H


#include "Tile.h"
#include "../view/TileView.h"
#include "../utils/Random.h"

class HorizontalTile : public Tile {
public:
    HorizontalTile(const std::array<float, 2>& position);

    void update(float deltaTime) override;

private:
    TileView tileView;
    float velocity = 0.25f;

    float halftile = tileView.getSpriteWidth() / settings::resolutionWidth / 2.0f;

    float movementBounds[2] = {0 + halftile, 1 - halftile};

    bool movingRight = Random::getBool();
};


#endif //DOODLEJUMP_HORIZONTALTILE_H

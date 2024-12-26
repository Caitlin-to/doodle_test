//
// Created by Caitlin To on 18/12/2024.
//

#include "TemporaryTile.h"


TemporaryTile::TemporaryTile(const std::array<float, 2>& position)
        : Tile(position, {255, 255, 255}), active(true) {}

void TemporaryTile::update(float deltaTime) {
    if (!active) {
    }
}

void TemporaryTile::onCollision() {
    active = false;
}

bool TemporaryTile::isActive() const {
    return active;
}

void TemporaryTile::setInactive() {
    active = false;
}
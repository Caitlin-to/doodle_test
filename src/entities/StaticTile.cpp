//
// Created by Caitlin To on 18/12/2024.
//

#include "StaticTile.h"

StaticTile::StaticTile(const std::array<float, 2>& position)
        : Tile(position, {66, 237, 36}) {} // green

void StaticTile::update(float deltaTime) {
}
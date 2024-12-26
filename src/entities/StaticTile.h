//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_STATICTILE_H
#define DOODLEJUMP_STATICTILE_H


#include "Tile.h"

class StaticTile : public Tile {
public:
    StaticTile(const std::array<float, 2>& position);
    void update(float deltaTime) override;
};


#endif //DOODLEJUMP_STATICTILE_H

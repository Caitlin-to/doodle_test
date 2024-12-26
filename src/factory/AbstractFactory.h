//
// Created by Caitlin To on 10/12/2024.
//

#ifndef DOODLEJUMP_ABSTRACTFACTORY_H
#define DOODLEJUMP_ABSTRACTFACTORY_H

#include <memory>
#include "../entities/Tile.h"

class AbstractFactory {
public:
    virtual Tile* createTile(const std::array<float, 2>& position) = 0; // Abstract method for creating a tile
    virtual ~AbstractFactory() = default;
};


#endif //DOODLEJUMP_ABSTRACTFACTORY_H

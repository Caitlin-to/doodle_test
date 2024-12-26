//
// Created by Caitlin To on 10/12/2024.
//

#ifndef DOODLEJUMP_CONCRETEFACTORY_H
#define DOODLEJUMP_CONCRETEFACTORY_H

#include "AbstractFactory.h"
#include "../entities/Tile.h"
#include "../entities/StaticTile.h"
#include "../entities/HorizontalTile.h"
#include "../entities/VerticalTile.h"
#include "../entities/TemporaryTile.h"
#include "../entities/Player.h"


class ConcreteFactory : public AbstractFactory {
public:
    Tile* createTile(const std::array<float, 2>& position) override;

    Tile* createTile(const std::array<float, 2>& position, const std::string& type); // type based creation
};


#endif //DOODLEJUMP_CONCRETEFACTORY_H

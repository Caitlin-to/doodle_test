//
// Created by Caitlin To on 10/12/2024.
//

#include "ConcreteFactory.h"

Tile* ConcreteFactory::createTile(const std::array<float, 2>& position) {
    return new StaticTile(position);
}

Tile* ConcreteFactory::createTile(const std::array<float, 2>& position, const std::string& type) {
    if (type == "horizontal") {
        return new HorizontalTile(position);
    } else if (type == "vertical") {
        float minY = 0.2f;
        float maxY = 0.22f;
        return new VerticalTile(position, minY, maxY);
    } else if (type == "temporary") {
        return new TemporaryTile(position);
    } else {
        return new StaticTile(position); // default to static tile
    }
}
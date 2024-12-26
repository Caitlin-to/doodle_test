//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_TEMPORARYTILE_H
#define DOODLEJUMP_TEMPORARYTILE_H

#include "Tile.h"


class TemporaryTile : public Tile {
public:
    TemporaryTile(const std::array<float, 2>& position);

    void update(float deltaTime) override;
    void onCollision() override;

    bool isActive() const override;
    void setInactive() override;

private:
    bool active;
};


#endif //DOODLEJUMP_TEMPORARYTILE_H

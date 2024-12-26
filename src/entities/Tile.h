//
// Created by Caitlin To on 21/11/2024.
//

#ifndef DOODLEJUMP_TILE_H
#define DOODLEJUMP_TILE_H

#include "array"
#include "tuple"
#include "memory"
#include "bonus/Spring.h"
#include "bonus/Jetpack.h"

class Tile {
public:
    Tile(const std::array<float, 2>& position, const std::tuple<int, int, int>& color = {0, 255, 0});
    virtual ~Tile() = default;

    virtual void update(float deltaTime) = 0;


    virtual void onCollision() {}


    virtual bool isActive() const;
    virtual void setInactive();


    void setPosition(const std::array<float, 2>& pos);
    void setX(float newX);
    void setY(float newY);
    std::array<float, 2> getPosition() const;
    std::tuple<int, int, int> getColor() const;


    void attachSpring(std::unique_ptr<Spring> s);
    bool hasSpring() const;
    Spring* getSpring() const; // Returns the attached spring if any

    void attachJetpack(std::unique_ptr<Jetpack> j);
    bool hasJetpack() const;
    Jetpack* getJetpack() const;


private:
    std::array<float, 2> position;
    std::tuple<int, int, int> color;
    std::unique_ptr<Spring> spring; /// ptr to string, nullptr if no string
    std::unique_ptr<Jetpack> jetpack; // idem
};




#endif //DOODLEJUMP_TILE_H

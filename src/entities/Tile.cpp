//
// Created by Caitlin To on 21/11/2024.
//

#include "Tile.h"

Tile::Tile(const std::array<float, 2>& position, const std::tuple<int, int, int>& color)
        : position(position), color(color) {}

void Tile::setPosition(const std::array<float, 2>& pos) {
    position = pos;
}

void Tile::setX(float newX) {
    position[0] = newX;
}

void Tile::setY(float newY) {
    position[1] = newY;
}

std::array<float, 2> Tile::getPosition() const {
    return position;
}

std::tuple<int, int, int> Tile::getColor() const {
    return color;
}


void Tile::attachSpring(std::unique_ptr<Spring> s) {
    spring = std::move(s);
}

bool Tile::hasSpring() const {
    return spring != nullptr;
}

Spring* Tile::getSpring() const {
    return spring.get();
}

void Tile::attachJetpack(std::unique_ptr<Jetpack> j) {
    jetpack = std::move(j);
}

bool Tile::hasJetpack() const {
    return jetpack != nullptr;
}

Jetpack* Tile::getJetpack() const {
    return jetpack.get();
}

bool Tile::isActive() const {
    return true;
}

void Tile::setInactive() {
}

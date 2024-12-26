//
// Created by Caitlin To on 11/12/2024.
//

#ifndef DOODLEJUMP_TILEVIEW_H
#define DOODLEJUMP_TILEVIEW_H

#include "SFML/Graphics.hpp"
#include "iostream"
#include "bonusView/SpringView.h"
#include "bonusView/JetpackView.h"

class TileView {
public:
    TileView();
    void loadTexture();
    void draw(sf::RenderWindow& window, const sf::Vector2f& position, bool hasSpring, bool hasJetpack, const std::tuple<int, int, int>& color);
    float getSpriteWidth() const;
    float getSpriteHeight() const;

private:
    sf::Sprite tileSprite;
    sf::Texture tileTexture;
    void setCenterOrigin();
    float spriteWidth;
    float spriteHeight;

    SpringView springView;
    JetpackView jetpackView;
};


#endif //DOODLEJUMP_TILEVIEW_H

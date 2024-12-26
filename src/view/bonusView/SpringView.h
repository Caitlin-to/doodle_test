//
// Created by Caitlin To on 25/12/2024.
//

#ifndef DOODLEJUMP_SPRINGVIEW_H
#define DOODLEJUMP_SPRINGVIEW_H

#include "SFML/Graphics.hpp"
#include "iostream"

class SpringView {
public:
    SpringView();
    void loadTexture();
    void draw(sf::RenderWindow& window, const sf::Vector2f& position);
    float getSpriteWidth() const;
    float getSpriteHeight() const;

private:
    sf::Sprite springSprite;
    sf::Texture springTexture;
    void setCenterOrigin();
    float spriteWidth;
    float spriteHeight;
};


#endif //DOODLEJUMP_SPRINGVIEW_H

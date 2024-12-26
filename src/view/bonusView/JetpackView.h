//
// Created by Caitlin To on 25/12/2024.
//

#ifndef DOODLEJUMP_JETPACKVIEW_H
#define DOODLEJUMP_JETPACKVIEW_H


#include "SFML/Graphics.hpp"
#include "iostream"

class JetpackView {
public:
    JetpackView();
    void loadTexture();
    void draw(sf::RenderWindow& window, const sf::Vector2f& position);
    float getSpriteWidth() const;
    float getSpriteHeight() const;

private:
    sf::Sprite jetpackSprite;
    sf::Texture jetpackTexture;
    void setCenterOrigin();
    float spriteWidth;
    float spriteHeight;
};


#endif //DOODLEJUMP_JETPACKVIEW_H

//
// Created by Caitlin To on 19/11/2024.
//

#ifndef DOODLEJUMP_PLAYERVIEW_H
#define DOODLEJUMP_PLAYERVIEW_H

#include <SFML/Graphics.hpp>
#include "../entities/Player.h"


class PlayerView {

public:
    PlayerView();
    void loadTexture(State state);
    void draw(sf::RenderWindow& window, const sf::Vector2f& position);
    float getSpriteWidth() const;
    float getSpriteHeight() const;

private:
    sf::Sprite playerSprite;
    sf::Texture playerTexture;
    State previousDirection;
    void setCenterOrigin();
    float spriteWidth;
    float spriteHeight;
};


#endif //DOODLEJUMP_PLAYERVIEW_H

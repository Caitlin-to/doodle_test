//
// Created by Caitlin To on 25/12/2024.
//

#include "SpringView.h"
//
// Created by Caitlin To on 11/12/2024.
//

SpringView::SpringView() {
    loadTexture();
    setCenterOrigin();
}

void SpringView::loadTexture() {
    std::string textureFile = "assets/images/aloneshoes.png";

    if (!springTexture.loadFromFile(textureFile)) {
        std::cerr << "Error loading tile texture!" << std::endl;
        return;
    }

    springSprite.setTexture(springTexture);
    spriteWidth = springSprite.getGlobalBounds().width;
    spriteHeight = springSprite.getGlobalBounds().height;
}


void SpringView::setCenterOrigin() {
    sf::FloatRect bounds = springSprite.getGlobalBounds();
    springSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void SpringView::draw(sf::RenderWindow& window, const sf::Vector2f& position) {
    springSprite.setPosition(position);
    window.draw(springSprite);
}

float SpringView::getSpriteWidth() const {
    return spriteWidth;
}

float SpringView::getSpriteHeight() const {
    return spriteHeight;
}
//
// Created by Caitlin To on 25/12/2024.
//

#include "JetpackView.h"

JetpackView::JetpackView() {
    loadTexture();
    setCenterOrigin();
}

void JetpackView::loadTexture() {
    std::string textureFile = "assets/images/singlejetpack.png";

    if (!jetpackTexture.loadFromFile(textureFile)) {
        std::cerr << "Error loading tile texture!" << std::endl;
        return;
    }

    jetpackSprite.setTexture(jetpackTexture);
    spriteWidth = jetpackSprite.getGlobalBounds().width;
    spriteHeight = jetpackSprite.getGlobalBounds().height;
}


void JetpackView::setCenterOrigin() {
    sf::FloatRect bounds = jetpackSprite.getGlobalBounds();
    jetpackSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void JetpackView::draw(sf::RenderWindow& window, const sf::Vector2f& position) {
    jetpackSprite.setPosition(position);
    window.draw(jetpackSprite);
}

float JetpackView::getSpriteWidth() const {
    return spriteWidth;
}

float JetpackView::getSpriteHeight() const {
    return spriteHeight;
}
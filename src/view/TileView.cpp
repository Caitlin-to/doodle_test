//
// Created by Caitlin To on 11/12/2024.
//

#include "TileView.h"

TileView::TileView() {
    loadTexture();
    setCenterOrigin();
}

void TileView::loadTexture() {
    std::string textureFile = "assets/images/goodtile.png";

    if (!tileTexture.loadFromFile(textureFile)) {
        std::cerr << "Error loading tile texture!" << std::endl;
    }

    tileSprite.setTexture(tileTexture);
    spriteWidth = tileSprite.getGlobalBounds().width;
    spriteHeight = tileSprite.getGlobalBounds().height;
}

void TileView::setCenterOrigin() {
    sf::FloatRect bounds = tileSprite.getGlobalBounds();
    tileSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void TileView::draw(sf::RenderWindow& window, const sf::Vector2f& position, bool hasSpring, bool hasJetpack, const std::tuple<int, int, int>& color) {
    tileSprite.setPosition(position);
    tileSprite.setColor(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color)));
    window.draw(tileSprite);


    if (hasSpring) {
        sf::Vector2f springPosition = position;
        springPosition.y -= 10.f; // offset to make the spring spawn above the tile

        springView.draw(window, springPosition);
    }

    if (hasJetpack) {
        sf::Vector2f jetpackPosition = position;
        jetpackPosition.y -= 20.f; // offset to make jetpack spawn above tile

        jetpackView.draw(window, jetpackPosition);
    }
}

float TileView::getSpriteWidth() const {
    return spriteWidth;
}

float TileView::getSpriteHeight() const {
    return spriteHeight;
}
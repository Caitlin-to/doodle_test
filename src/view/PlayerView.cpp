//
// Created by Caitlin To on 19/11/2024.
//

#include "PlayerView.h"

PlayerView::PlayerView() {
    loadTexture(State::STRAIGHT); // initial texture
    // default origin for visual
    setCenterOrigin();
}


void PlayerView::loadTexture(State state) {
    if (state != previousDirection) {
        std::string textureFile;
        switch (state) {
            case State::LEFT:
                textureFile = "assets/images/player_left.png";
                break;
            case State::RIGHT:
                textureFile = "assets/images/player_right.png";
                break;
            case State::STRAIGHT:
                textureFile = "assets/images/player_straight_good.png";
                break;
            case State::ROCKET:
                textureFile = "assets/images/rocket.png";
        }

        if (!playerTexture.loadFromFile(textureFile)) {
            std::cerr << "Error loading player texture!" << std::endl;
            return;
        }

        // Update sprite texture
        playerSprite.setTexture(playerTexture);

        // to avoid cropping of the image (stale bounds)
        playerSprite.setTextureRect(sf::IntRect(0, 0, playerTexture.getSize().x, playerTexture.getSize().y));

        spriteWidth = playerSprite.getLocalBounds().width;
        spriteHeight = playerSprite.getLocalBounds().height;
        setCenterOrigin();

        previousDirection = state;
    }
}
void PlayerView::setCenterOrigin() {
    sf::FloatRect bounds = playerSprite.getGlobalBounds();
    playerSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}

void PlayerView::draw(sf::RenderWindow& window, const sf::Vector2f& position) {
    playerSprite.setPosition(position);
    window.draw(playerSprite);
}

float PlayerView::getSpriteWidth() const {
    return spriteWidth;
}

float PlayerView::getSpriteHeight() const {
    return spriteHeight;
}

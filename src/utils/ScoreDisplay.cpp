//
// Created by Caitlin To on 18/12/2024.
//

#include "ScoreDisplay.h"

ScoreDisplay::ScoreDisplay(const sf::Font& font) {
    scoreText.setFont(font);
    scoreText.setCharacterSize(50);
    scoreText.setFillColor(sf::Color::White);
}

void ScoreDisplay::update(const ScoreTracker& scoreTracker, const sf::Vector2f& cameraCenter) {
    scoreText.setString(std::to_string(scoreTracker.getScore()));

    // keep it centered
    sf::FloatRect textBounds = scoreText.getLocalBounds();

    scoreText.setPosition(
            cameraCenter.x - textBounds.width / 2.0f,
            cameraCenter.y - settings::resolutionHeight / 2.0f + 10.0f
    );
}

void ScoreDisplay::render(sf::RenderWindow& window) {
    window.draw(scoreText);
}
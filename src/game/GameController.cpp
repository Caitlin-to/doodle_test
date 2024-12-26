//
// Created by Caitlin To on 19/11/2024.
//

#include "GameController.h"
#include "Game.h"

GameController::GameController(Game& game, World& world, Player& player, PlayerView& playerView, TileView& tileView, Camera& camera)
        : game(game), world(world), player(player), playerView(playerView), tileView(tileView), camera(camera) {
}

void GameController::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        player.move(-1);  // model updates only
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        player.move(1);
    }
    else {
        player.move(0);
    }

    // to avoid buggy toggle
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::H) && !keyHeldH) {
        toggleHitbox();
        keyHeldH = true;
    }
    else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::H) && keyHeldH) {
        keyHeldH = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F) && !keyHeldF) {
        showFPS = !showFPS;
        keyHeldF = true;
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::F) && keyHeldF) {
        keyHeldF = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && !keyHeldR) {
        if (world.getGameOver()) {
            game.resetGame();
            world.setGameOver(false);
        }
        keyHeldR = true;
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::R) && keyHeldR) {
        keyHeldR = false;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::M) && !keyHeldM) {
        toggleMusic = !toggleMusic;
        keyHeldM = true;
    } else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::M) && keyHeldM) {
        keyHeldM = false;
    }

}

void GameController::render(sf::RenderWindow& window) {

    //tiles
    tileView.loadTexture();
    for (const auto& tilo : world.getTiles()) {
        sf::Vector2f position = CoordinateUtils::normalizedToWindow(tilo->getPosition());
        bool hasSpring = tilo->hasSpring();
        bool hasJetpack = tilo->hasJetpack();
        const std::tuple<int, int, int>& color = tilo->getColor();
        tileView.draw(window, sf::Vector2f(position), hasSpring, hasJetpack, color);
    }

    // player above tiles
    playerView.loadTexture(player.getState());  // load correct texture based on player state
    playerView.draw(window, CoordinateUtils::normalizedToWindow(player.getPosition()));

    if (showHitboxes) {
        renderHitboxes(window);
    }

}

void drawBg(){

}


void GameController::renderHitboxes(sf::RenderWindow& window) {

    for (const auto& tilo : world.getTiles()) {
        sf::Vector2f position = CoordinateUtils::normalizedToWindow(tilo->getPosition());

        sf::RectangleShape tileHitbox(sf::Vector2f(tileView.getSpriteWidth(), tileView.getSpriteHeight()));
        tileHitbox.setPosition(position.x - tileHitbox.getSize().x / 2.0f, position.y - tileHitbox.getSize().y / 2.0f);
        tileHitbox.setOutlineColor(sf::Color::Green);
        tileHitbox.setOutlineThickness(2.0f);
        tileHitbox.setFillColor(sf::Color::Transparent);
        window.draw(tileHitbox);
    }


    sf::RectangleShape playerHitbox(sf::Vector2f(playerView.getSpriteWidth(), playerView.getSpriteHeight()));
    playerHitbox.setPosition(CoordinateUtils::normalizedToWindow(player.getPosition()).x - playerHitbox.getSize().x / 2.0f,
                             CoordinateUtils::normalizedToWindow(player.getPosition()).y - playerHitbox.getSize().y / 2.0f);
    playerHitbox.setOutlineColor(sf::Color::Red);
    playerHitbox.setOutlineThickness(2.0f);
    playerHitbox.setFillColor(sf::Color::Transparent);
    window.draw(playerHitbox);
}


void GameController::update(float dt) {
    player.jump();
    handleInput();
    world.update(camera, dt);
}

bool GameController::getShowFPS() const {
    return showFPS;
}

bool GameController::getToggleMusic() const {
    return toggleMusic;
}

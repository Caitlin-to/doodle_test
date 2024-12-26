//
// Created by Caitlin To on 18/11/2024.
//

#ifndef DOODLEJUMP_GAME_H
#define DOODLEJUMP_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <fstream>

#include "Settings.h"
#include "GameController.h"
#include "entities/Player.h"
#include "utils/Stopwatch.h"
#include "utils/ScoreDisplay.h"
#include "camera/Camera.h"

#include "../view/PlayerView.h"
#include "../view/TileView.h"

#include "../world/World.h"

#include "../factory/AbstractFactory.h"
#include "../factory/ConcreteFactory.h"

class GameController;

class Game {

public:
    Game();
    void run();
    void resetGame();

private:
    std::unique_ptr<ConcreteFactory> factory;
    World world;
    sf::RenderWindow window;
    std::unique_ptr<GameController> controller;
    Camera camera;

    TileView tileView;

    Player player;
    PlayerView playerView;

    Stopwatch stopwatch;


    int frameCount = 0;
    float elapsedTime = 0.0f;
    sf::Font font;
    sf::Text fpsText;
    sf::Text deathText;
    sf::Text restartText;
    sf::Text highScoreText;
    ScoreDisplay scoreDisplay;
    sf::Text congratsText;
    std::vector<sf::Color> rainbowColors = {
            sf::Color::Red, sf::Color::Yellow, sf::Color::Green,
            sf::Color::Cyan, sf::Color::Blue, sf::Color::Magenta
    };


    void loadHighScore();
    void saveHighScore();
    int highScore;

    sf::Music music;
    sf::SoundBuffer highScoreBuffer;
    sf::Sound highScoreSound;
};


#endif //DOODLEJUMP_GAME_H

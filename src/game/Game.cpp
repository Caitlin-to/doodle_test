//
// Created by Caitlin To on 18/11/2024.
//

#include "Game.h"


Game::Game()
        : window(sf::VideoMode(settings::resolutionWidth, settings::resolutionHeight), settings::gameName, sf::Style::Close),
        camera(settings::resolutionWidth, settings::resolutionHeight, 0.1f),
        factory(std::make_unique<ConcreteFactory>()),
          world(player, playerView, factory.get(), tileView), // init world with player
          controller(new GameController(*this, world, player, playerView, tileView, camera)),
          scoreDisplay(font)
          {
              if (!font.loadFromFile("assets/doodle_font.ttf")) {
                  std::cerr << "Error loading font!" << std::endl;
                  return;
              }

              if (!music.openFromFile("assets/sound/bg_music.mp3")){
                  std::cerr << "Error loading music!" << std::endl;
                  return;
              }

              if (!highScoreBuffer.loadFromFile("assets/sound/new_highscore.mp3")) {
                  std::cerr << "Error loading jetpack.mp3!" << std::endl;
              } else {
                  highScoreSound.setBuffer(highScoreBuffer);
              }

              music.play();
              music.setLoop(true);

              loadHighScore();

              fpsText.setFont(font);
              fpsText.setCharacterSize(20);
              fpsText.setFillColor(sf::Color::White);

              deathText.setFont(font);
              deathText.setCharacterSize(50);
              deathText.setFillColor(sf::Color::Red);
              deathText.setString("You Died!");

              restartText.setFont(font);
              restartText.setCharacterSize(30);
              restartText.setFillColor(sf::Color::White);
              restartText.setString("Press R to Restart");
          }

void Game::run() {
    const float SECONDS_PER_TICK = 1.0f / settings::FPS;
    float accumulator = 0.0f;
    stopwatch.start();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = stopwatch.getElapsedTime();
        stopwatch.start(); // Reset timer
        accumulator += dt;

        // update frame count and elapsed time for FPS calculation
        frameCount++;
        elapsedTime += dt;

        // calculate FPS every second
        if (elapsedTime >= 1.0f) {
            float fps = frameCount / elapsedTime;
            fpsText.setString("FPS " + std::to_string(static_cast<int>(fps)));  // update FPS text
            frameCount = 0;  // reset frame count
            elapsedTime = 0.0f;  // reset elapsed time
        }

        while (accumulator >= SECONDS_PER_TICK) {
            controller->update(SECONDS_PER_TICK);
            camera.update(player.getPosition());
            window.setView(camera.getView());
            accumulator -= SECONDS_PER_TICK;
        }

        if (controller->getToggleMusic()) {
            music.setVolume(100);
        }else{
            music.setVolume(0);
        }


        window.clear(sf::Color(153, 153, 153));
        controller->render(window);

        scoreDisplay.update(world.getScoreTracker(), camera.getView().getCenter());
        scoreDisplay.render(window);

        sf::Vector2f cameraCenter = camera.getView().getCenter();
        fpsText.setPosition(cameraCenter.x - settings::resolutionWidth / 2 + 10.f, cameraCenter.y - settings::resolutionHeight / 2 + 10.f);

        if (controller->getShowFPS()) {
            window.draw(fpsText);
        }

        if (world.getGameOver()) {
            deathText.setPosition(cameraCenter.x - deathText.getGlobalBounds().width / 2, cameraCenter.y - settings::resolutionHeight / 4);
            window.draw(deathText);

            sf::Text scoreText;
            scoreText.setFont(font);
            scoreText.setCharacterSize(30);
            scoreText.setFillColor(sf::Color::White);
            scoreText.setString("Score: " + std::to_string(world.getScoreTracker().getScore()));
            scoreText.setPosition(cameraCenter.x - scoreText.getGlobalBounds().width / 2, cameraCenter.y - settings::resolutionHeight / 4 + 60.f);
            window.draw(scoreText);

            if (world.getScoreTracker().getScore() > highScore) {
                highScore = world.getScoreTracker().getScore();
                saveHighScore();

                congratsText.setFont(font);
                congratsText.setCharacterSize(30);
                congratsText.setFillColor(sf::Color::Magenta);
                congratsText.setString("CONGRATS YOU HIT A NEW HIGHSCORE!");
                congratsText.setPosition(cameraCenter.x - congratsText.getGlobalBounds().width / 2, cameraCenter.y - settings::resolutionHeight / 4 - 40.f);

                highScoreSound.play();

            }

            highScoreText.setFont(font);
            highScoreText.setCharacterSize(30);
            highScoreText.setFillColor(sf::Color::White);
            highScoreText.setString("High Score: " + std::to_string(highScore));
            highScoreText.setPosition(cameraCenter.x - highScoreText.getGlobalBounds().width / 2, cameraCenter.y - settings::resolutionHeight / 4 + 100.f);
            window.draw(highScoreText);

            restartText.setPosition(cameraCenter.x - restartText.getGlobalBounds().width / 2, cameraCenter.y - settings::resolutionHeight / 4 + 160.f);
            window.draw(restartText);
            window.draw(congratsText);
        }

        window.display();
    }
}

void Game::resetGame() {
    player.reset();
    world.reset();
    camera.reset();
}


void Game::loadHighScore() {
    std::ifstream inputFile("highscore.txt");
    if (inputFile.is_open()) {
        inputFile >> highScore;
        inputFile.close();
    } else {
        highScore = 0;
    }
}

void Game::saveHighScore() {
    std::ofstream outputFile("highscore.txt");
    if (outputFile.is_open()) {
        outputFile << highScore;
        outputFile.close();
    }
}
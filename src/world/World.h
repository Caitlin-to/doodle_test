//
// Created by Caitlin To on 19/11/2024.
//

#ifndef DOODLEJUMP_WORLD_H
#define DOODLEJUMP_WORLD_H

#include "../Settings.h"
#include "../camera/Camera.h"

#include "../entities/Player.h"
#include "../entities/Tile.h"

#include "../view/PlayerView.h"
#include "../view/TileView.h"

#include "../utils/Helpers.h"
#include "../utils/Random.h"
#include "../utils/ScoreTracker.h"

#include "../factory/AbstractFactory.h"
#include "../factory/ConcreteFactory.h"

#include "SFML/Audio.hpp"

class World {

public:
    World(Player& player, PlayerView& playerView, ConcreteFactory* factory, TileView& tileView);

    void update(Camera& camera, float dt);
    const std::vector<std::unique_ptr<Tile>>& getTiles() const;
    ScoreTracker& getScoreTracker();
    void reset();
    bool getGameOver() const;
    void setGameOver(bool go);


private:
    Player& player;
    PlayerView& playerView;
    TileView& tileView;
    ScoreTracker scoreTracker;

    void checkWallCollisions();
    void checkTileCollisions();
    std::vector<std::unique_ptr<Tile>> tiles;
    ConcreteFactory* factory;


    void generatePlatform();
    void generateInitialPlatforms();

    float previousCameraY = 0;

    bool gameOver = false;

    sf::SoundBuffer deathBuffer;
    sf::SoundBuffer springBuffer;
    sf::SoundBuffer jetpackBuffer;
    sf::SoundBuffer jumpBuffer;

    sf::Sound death;
    sf::Sound spring;
    sf::Sound jetpack;
    sf::Sound jump;

};


#endif //DOODLEJUMP_WORLD_H

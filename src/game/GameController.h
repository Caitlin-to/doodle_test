//
// Created by Caitlin To on 19/11/2024.
//

#ifndef DOODLEJUMP_GAMECONTROLLER_H
#define DOODLEJUMP_GAMECONTROLLER_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "../Settings.h"

class Game;
#include "Game.h"
#include "../entities/Player.h"
#include "../entities/Tile.h"

#include "../view/PlayerView.h"
#include "../view/TileView.h"

#include "../world/World.h"

#include "../utils/Helpers.h"


class GameController {

public:
    GameController(Game& game, World &world, Player &player, PlayerView &playerView, TileView &tileView, Camera& camera);

    void handleInput();
    void update(float dt);
    void render(sf::RenderWindow& window);
    void toggleHitbox() { showHitboxes = !showHitboxes;}
    bool getShowFPS() const;
    bool getToggleMusic() const;

private:
    World& world;
    Player& player;
    PlayerView& playerView;
    TileView& tileView;
    Camera& camera;
    Game& game;

    sf::Texture bgTexture;
    sf::Sprite bgSprite;

    bool showHitboxes = settings::showHitboxesByDefault;
    bool keyHeldH = false; // tracks if h is being held to prevent rapid toggeling
    void renderHitboxes(sf::RenderWindow& window);

    bool keyHeldF = false;
    bool keyHeldM = false;
    bool toggleMusic = settings::enableMusicbyDefault;

    bool showFPS = settings::showFPSByDefault;

    bool keyHeldR = false;
};


#endif //DOODLEJUMP_GAMECONTROLLER_H

//
// Created by Caitlin To on 19/11/2024.
//

#include "World.h"

World::World(Player& player, PlayerView& playerView, ConcreteFactory* factory, TileView& tileView)
        : player(player), playerView(playerView), factory(factory), tileView(tileView) {
    generateInitialPlatforms();

    if (!deathBuffer.loadFromFile("assets/sound/louderdeath.mp3")) {
        std::cerr << "Error loading louderdeath.mp3!" << std::endl;
    } else {
        death.setBuffer(deathBuffer);
    }

    if (!springBuffer.loadFromFile("assets/sound/spring.mp3")) {
        std::cerr << "Error loading spring.mp3!" << std::endl;
    } else {
        spring.setBuffer(springBuffer);
    }

    if (!jetpackBuffer.loadFromFile("assets/sound/jetpack.mp3")) {
        std::cerr << "Error loading jetpack.mp3!" << std::endl;
    } else {
        jetpack.setBuffer(jetpackBuffer);
    }

    if (!jumpBuffer.loadFromFile("assets/sound/jump.mp3")) {
        std::cerr << "Error loading jump.mp3!" << std::endl;
    } else {
        jump.setBuffer(jumpBuffer);
    }

}

void World::update(Camera& camera, float dt) {
    checkWallCollisions();
    checkTileCollisions();

    // update tiles
    for (auto& tile : tiles) {
        tile->update(dt);
    }

    // remove inactive tiles
    tiles.erase(std::remove_if(tiles.begin(), tiles.end(),
                               [](const std::unique_ptr<Tile>& tile) {
                                   return !tile->isActive();  // Only remove inactive tiles
                               }),
                tiles.end());

    // increase score based on camera height
    float cameraY = camera.getCameraY();
    float cameraBottom = cameraY + 0.5f; // centered camera + half of the screen = bottom of the screen



    if (cameraY < previousCameraY) {
        float distanceMoved = previousCameraY - cameraY;
        float scoreIncrease = distanceMoved * 125;

        if (scoreIncrease > 0.0f) {
            scoreTracker.increment(static_cast<int>(std::floor(scoreIncrease)));
        }
    }

    previousCameraY = cameraY;

    // generate more platforms if too many despawned
    if (tiles.size() < 20) {
        generatePlatform();
    }

    // remove tiles that are off the screen (below the camera bottom)
    tiles.erase(std::remove_if(tiles.begin(), tiles.end(),
                               [cameraBottom](const std::unique_ptr<Tile>& tile) {
                                   return tile->getPosition()[1] > cameraBottom;
                               }),
                tiles.end());

    // make the player leave the rocket when he starts falling
    if (player.isFalling() && player.getState() == State::ROCKET) {
        player.setState(State::STRAIGHT);
    }

    if (player.getPosition()[1] > cameraBottom && !gameOver) {
        death.play();
        gameOver = true;
    }
}

const std::vector<std::unique_ptr<Tile>>& World::getTiles() const {
    return tiles;
}

void World::checkWallCollisions() {
    // get normalized width of the player's sprite so he doesnt visually go out of bounds
    float normalizedHalfWidth = (playerView.getSpriteWidth() / 2.0f) / settings::resolutionWidth;

    if (player.getPosition()[0] < normalizedHalfWidth) {
        player.setX(normalizedHalfWidth); // reposition to left bound
    }

    if (player.getPosition()[0] > 1.0f - normalizedHalfWidth) {
        player.setX(1.0f - normalizedHalfWidth); // reposition to right bound
    }
}



void World::checkTileCollisions() {
    const auto playerPos = player.getPosition();
    float adjustedPlayerWidth = (playerView.getSpriteWidth()) / settings::resolutionWidth;
    float playerHeight = playerView.getSpriteHeight() / settings::resolutionHeight;

    // to cancel the padding in the playerstraight

    if (player.isFalling()) {
        for (const auto& tile : tiles) {
            // if player is above the tile otherwise it snaps weirdly to the tile while being under the tile NOT FIXED
            if (playerPos[1] < tile->getPosition()[1]){
                const auto tilePos = tile->getPosition();
                float tileWidth = tileView.getSpriteWidth() / settings::resolutionWidth;
                float tileHeight = tileView.getSpriteHeight() / settings::resolutionHeight;

                bool isColliding =
                        playerPos[0] + adjustedPlayerWidth / 2.0f > tilePos[0] - tileWidth / 2.0f && // right side of the player is right of the left side of the tile
                        playerPos[0] - adjustedPlayerWidth / 2.0f < tilePos[0] + tileWidth / 2.0f && // left side of the player is left of the right side of the tile
                        playerPos[1] + playerHeight / 2.0f > tilePos[1] - tileHeight / 2.0f && // bottom side of the player is below the top side of the tile
                        playerPos[1] - playerHeight / 2.0f < tilePos[1] + tileHeight / 2.0f; // top side of the player is above the bottom side of the tile

                if (isColliding) {
                    tile->onCollision();// trigger collision on tile (temp tile)

                    if (tile->hasSpring()) {
                        spring.play();

                        player.setJumpVelocity(tile->getSpring()->getSpringForce());
                        player.setUsingJetpack(false);
                    }
                    else if (tile->hasJetpack()){
                        jetpack.play();

                        player.setJumpVelocity(tile->getJetpack()->getJetpackForce());
                        player.setUsingJetpack(true);
                    }
                    else{
                        jump.play();

                        player.setIsJumping(false); // jump again
                        player.setUsingJetpack(false);
                    }
                    break;
                }
            }

        }
    }
}

void World::generatePlatform() {
    // get last y to calculate new y
    float lastTileY = tiles.back()->getPosition()[1];

    // Gradually reduce the vertical spacing between platforms as score increases
    float minYSpacing = 0.15f;  // Minimum spacing between platforms
    float maxYSpacing = 0.2f;   // Maximum spacing between platforms
    if (scoreTracker.getScore() > 500) {
        maxYSpacing = std::max(0.12f, maxYSpacing - 0.01f);  // Gradually reduce max spacing
    }
    if (scoreTracker.getScore() > 1000) {
        maxYSpacing = std::max(0.1f, maxYSpacing - 0.01f);    // Further reduce max spacing
    }

    // Generate a random Y position with reduced spacing
    float randomY = lastTileY - Random::getFloat(minYSpacing, maxYSpacing);

    // Generate a random X position with padding to keep platforms within screen bounds
    float randomX = Random::getFloat(0.1f, 0.9f);

    // chance for static basic on score
    float scoreFactor = scoreTracker.getScore() / 50.0f;  // Increase this as score increases
    float staticChance = std::max(0.01f, 1.0f - scoreFactor * 0.01f);  // decrease by 1% per 50 score
    float randomChance = Random::getFloat(0.0f, 1.0f);

    // choose platform type based on score and staticChance
    std::string tileType;
    if (randomChance < staticChance) {
        tileType = "static";  // Static platform
    } else if (randomChance < staticChance + 0.25f) {
        tileType = "temporary";  // Temporary platform (25% chance if static chance is below 1)
    } else if (randomChance < staticChance + 0.5f) {
        tileType = "horizontal";  // Horizontal platform (25% chance after static)
    } else {
        tileType = "vertical";  // Vertical platform (25% chance)
    }

    auto tile = std::unique_ptr<Tile>(factory->createTile({randomX, randomY}, tileType));

    // Attach bonuses (e.g., spring or jetpack) based on score thresholds
    if (Random::getFloat(0.0f, 1.0f) < 0.1f && scoreTracker.getScore() > 300) { // 10% chance for spring
        tile->attachSpring(std::make_unique<Spring>());
    }
    if (Random::getFloat(0.0f, 1.0f) < 0.05f && !tile->hasSpring() && scoreTracker.getScore() > 1000) { // 5% chance for jetpack
        tile->attachJetpack(std::make_unique<Jetpack>());
    }

    tiles.push_back(std::move(tile));
}


void World::generateInitialPlatforms() {
    float lastY = 1.0f; // Start from the bottom of the screen
    for (int i = 0; i < 20; ++i) {
        float randomX = Random::getFloat(0.1f, 0.9f); // 10% - 90% (padding)
        lastY -= Random::getFloat(0.15f, 0.2f);        // random vertical spacing

        auto tile = std::unique_ptr<Tile>(factory->createTile({randomX, lastY}, "static"));
        tiles.push_back(std::move(tile));
    }
}

ScoreTracker& World::getScoreTracker() {
    return scoreTracker;
}


void World::reset(){
    tiles.clear();
    generateInitialPlatforms();
    scoreTracker.reset();
}

bool World::getGameOver() const {
    return gameOver;
}

void World::setGameOver(bool go) {
    gameOver = go;
}
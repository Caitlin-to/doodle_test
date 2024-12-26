//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_SCOREDISPLAY_H
#define DOODLEJUMP_SCOREDISPLAY_H


#include <SFML/Graphics.hpp>
#include "ScoreTracker.h"
#include "Settings.h"

class ScoreDisplay {
public:
    ScoreDisplay(const sf::Font& font);
    void update(const ScoreTracker& scoreTracker, const sf::Vector2f& cameraCenter);
    void render(sf::RenderWindow& window);

private:
    sf::Text scoreText;
};



#endif //DOODLEJUMP_SCOREDISPLAY_H

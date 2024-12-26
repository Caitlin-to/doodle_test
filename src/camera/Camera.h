//
// Created by Caitlin To on 18/12/2024.
//

#ifndef DOODLEJUMP_CAMERA_H
#define DOODLEJUMP_CAMERA_H


#include <SFML/Graphics.hpp>
#include <array>

#include "Settings.h"

class Camera {
public:
    Camera(float width, float height, float speed);

    void update(const std::array<float, 2>& playerPosition);
    sf::View getView() const;
    float getCameraY() const;
    void reset();

private:
    float width, height;
    float speed;
    float maxHeight;
    sf::View view;
    float followBuffer;
};


#endif //DOODLEJUMP_CAMERA_H

//
// Created by Caitlin To on 18/12/2024.
//

#include "Camera.h"

Camera::Camera(float width, float height, float speed)
        : width(width), height(height), speed(speed), maxHeight(0.5f * settings::resolutionHeight), followBuffer(5.0f) {
    view.setSize(width, height);
    view.setCenter(width / 2.0f, height / 2.0f);
}

void Camera::update(const std::array<float, 2>& playerPosition) {
    float targetX = view.getCenter().x;
    float targetY = playerPosition[1] * settings::resolutionHeight;

    if (targetY < maxHeight) {
        float cameraY = view.getCenter().y + (targetY - view.getCenter().y) * speed;
        view.setCenter(targetX, cameraY);
        maxHeight = targetY;
    } else {
        // buffer to get rid of camera snapping
        float bufferedHeight = maxHeight + followBuffer;

        float cameraY = view.getCenter().y + (bufferedHeight - view.getCenter().y) * speed;
        view.setCenter(targetX, cameraY);
    }
}

sf::View Camera::getView() const {
    return view;
}

float Camera::getCameraY() const {
    return view.getCenter().y / settings::resolutionHeight; // Normalized Y position
}

void Camera::reset() {
    view.setCenter(width / 2.0f, height / 2.0f);
    maxHeight = 0.5f * settings::resolutionHeight;
}
//
// Created by Caitlin To on 18/11/2024.
//

#include "Player.h"

Player::Player()
        : position{0.5, 1},
          speed(6.0f / settings::resolutionWidth),  // Normalize speed
          jumpVelocity(-12.5f / settings::resolutionHeight),  // Normalize jump velocity
          gravity(0.3f / settings::resolutionHeight),  // Normalize gravity
          isJumping(true),
          state(State::STRAIGHT) {}

void Player::move(float dX) {
    position[0] += speed * dX;
    if (state!=State::ROCKET){
        state = (dX < 0) ? State::LEFT : (dX > 0) ? State::RIGHT : State::STRAIGHT;
    }
}

void Player::jump() {
    position[1] += jumpVelocity;
    jumpVelocity += gravity;

    if (!isJumping) {
        jumpVelocity = -12.5 / settings::resolutionHeight;  // Reset jump velocity
        isJumping = true;
    }
}

std::array<float, 2> Player::getPosition() const {
    return position;
}

void Player::setPosition(const std::array<float, 2>& pos) {
    position = pos;
}

void Player::setX(const float newX) {
    position[0] = newX;
}

void Player::setY(const float newY) {
    position[1] = newY;
}

State Player::getState() const {
    return state;
}

void Player::setState(State newState){
    state = newState;
}

void Player::setIsJumping(bool isjumping) {
    isJumping = isjumping;
}

bool Player::isFalling() const {
    if (jumpVelocity > 0) {
        return true;
    }else{
        return false;
    }
}

bool Player::getIsJumping() const {
    return isJumping;
}

void Player::setJumpVelocity(float newJumpVelocity){
    jumpVelocity = newJumpVelocity;
};

float Player::getJumpVelocity() const {
    return jumpVelocity;
}

bool Player::isUsingJetpack() const {
    return usingJetpack;
}

void Player::setUsingJetpack(bool value) {
    usingJetpack = value;
    if (value) {
        state = State::ROCKET;
    }else{
        state = State::STRAIGHT;
    }
}

float Player::getMaxJumpHeight() const {
    return (jumpVelocity * jumpVelocity) / (2 * gravity);
}

void Player::reset() {
    position = {0.5f, 1.0f};  // Reset position to starting point
    jumpVelocity = -12.5f / settings::resolutionHeight;  // Reset jump velocity
    isJumping = true;  // Reset jumping state
    state = State::STRAIGHT;  // Reset state to straight
}
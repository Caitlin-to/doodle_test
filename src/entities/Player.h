//
// Created by Caitlin To on 18/11/2024.
//

#ifndef DOODLEJUMP_PLAYER_H
#define DOODLEJUMP_PLAYER_H

#include <array>
#include <iostream>
#include "../Settings.h"

enum class State {
    LEFT,
    RIGHT,
    STRAIGHT,
    ROCKET
};

class Player {
public:
    Player();
    void move(float dX);
    void jump();
    void setPosition(const std::array<float, 2>& pos);
    void setX(float newX);
    void setY(float newY);
    std::array<float, 2> getPosition() const;
    State getState() const;
    void setState(State newState);
    void setIsJumping(bool isJumping);
    bool isFalling() const;
    bool getIsJumping() const;
    void setJumpVelocity(float newJumpVelocity);
    float getJumpVelocity() const;
    float getMaxJumpHeight() const;


    bool isUsingJetpack() const;
    void setUsingJetpack(bool value);

    void reset();

private:
    std::array<float, 2> position;
    float speed;
    State state;
    float jumpVelocity;
    const float gravity;
    bool isJumping;
    bool usingJetpack = false;

};

#endif //DOODLEJUMP_PLAYER_H

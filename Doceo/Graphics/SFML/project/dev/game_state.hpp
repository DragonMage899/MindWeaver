#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include "game.hpp"

class GameState
{
    public:

    Game* game; //State manager

    //called by state manaer
    virtual void draw(const float dt) = 0; //draw state to screen
    virtual void update(const float dt) = 0; //update logic
    virtual void handleInput() = 0; //user input
};

#endif
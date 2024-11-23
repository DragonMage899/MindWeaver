#ifndef GAME_STATE_START_HPP
#define GAME_STATE_START_HPP

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Gui.h"
#include <map>
#include <string>


class GameStateStart : public GameState
{
private:
    sf::View view;
    std::map<std::string, Gui> guiSystem;
    void loadgame();

public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateStart(Game *game);
};

#endif /* GAME_STATE_START_HPP */

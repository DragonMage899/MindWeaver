#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>

#include "game_state.hpp"

class GameStateEditor : public GameState //Running Game
{
    private:

    sf::View gameView; //View -> Camera
    sf::View guiView;
    //Window shows what all views are seeing
    //2D game -> Co-ordinates in pixels (unbounded)
    //The views will look at a section of the co ordinates and draws them to a place in the window
    //Views can be moved, scaled and rotated
    public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEditor(Game* game);
};

#endif
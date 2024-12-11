#ifndef GAME_STATE_EDITOR_HPP
#define GAME_STATE_EDITOR_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "game_state.hpp"
#include "map.hpp"
#include "city.hpp"
#include "gui.hpp"

enum class ActionState { NONE, PANNING, SELECTING };

class GameStateEditor : public GameState //Running Game
{
    private:

    ActionState actionState;

    sf::View gameView; //View -> Camera
    sf::View guiView;
    //Window shows what all views are seeing
    //2D game -> Co-ordinates in pixels (unbounded)
    //The views will look at a section of the co ordinates and draws them to a place in the window
    //Views can be moved, scaled and rotated
    //Map map; dep
    City city;

    sf::Vector2i panningAnchor;
    float zoomLevel;

    sf::Vector2i selectionStart;
    sf::Vector2i selectionEnd;

    Tile* currentTile;

    std::map<std::string, Gui> guiSystem;

    public:

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

    GameStateEditor(Game* game);
};

#endif
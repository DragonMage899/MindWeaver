#ifndef GAMESTATEEDITOR_H
#define GAMESTATEEDITOR_H

#include <SFML/Graphics.hpp>

#include "GameState.h"
#include "Map.h"
#include "City.h"
#include "Gui.h"

enum class ActionState { NONE, PANNING, SELECTING };

class GameStateEditor : public GameState
{
    private:

    ActionState actionState;

    sf::View gameView;
    sf::View guiView;

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

#endif /* GAME_STATE_EDITOR_HPP */

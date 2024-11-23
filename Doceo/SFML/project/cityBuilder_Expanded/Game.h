#ifndef GAME_H
#define GAME_H

#include <stack>
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Tile.h"
#include "Grass.h"
#include "Gui.h"

#include "TileFactory.h"
#include "GrassFactory.h"
#include "ForestFactory.h"
#include "WaterFactory.h"
#include "ResidentialFactory.h"
#include "CommercialFactory.h"
#include "IndustrialFactory.h"
#include "LandmarkFactory.h"
#include "RoadFactory.h"


class GameState;

class Game
{
private:
 
    void loadTextures();
    void loadTiles();
    void loadStylesheets();
    void loadFonts();
    void loadFactories();

public:

    const static int tileSize = 8;
    std::stack<GameState*> states;

    sf::RenderWindow window;
    TextureManager texmgr;
    sf::Sprite background;

    std::map<std::string, Tile*> tileAtlas;
    std::map<std::string, GuiStyle> stylesheets;
    std::map<std::string, sf::Font> fonts;
    std::map<std::string, TileFactory*> Factory;

    void pushState(GameState* state);
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    void gameLoop();

    Game();
    ~Game();
};

#endif /* GAME_HPP */

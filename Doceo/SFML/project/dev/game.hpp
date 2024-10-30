#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"
#include "tile.hpp"
#include "gui.hpp"

class GameState;

class Game
{
    private:

    void loadTextures(); //fills std::map in texmgr
    void loadTiles();
    void loadStylesheets();
    void loadFonts();

    public:

    const static int tileSize = 8; // = half width (px) of each tile
    std::stack<GameState*> states; //State storage
        //Stack allows us to add new states over the top of old ones whilst keeping track of old states
        //e.g) push pause state, remove pause (now we're back in the state before paused)

    sf::RenderWindow window; //Window to draw game to
    TextureManager texmgr;
    sf::Sprite background; //Sprites are drawable and mutable

    std::map<std::string, Tile> tileAtlas;
    std::map<std::string, GuiStyle> stylesheets;
    std::map<std::string, sf::Font> fonts;

    void pushState(GameState* state); //
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    void gameLoop(); //calls virtual functions on game_state

    Game();
    ~Game();
};

#endif
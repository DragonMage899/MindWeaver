#ifndef GAME_HPP
#define GAME_HPP

#include <stack>
#include <SFML/Graphics.hpp>
#include "texture_manager.hpp"

class GameState;

class Game
{
    private:

    void loadTextures(); //fills std::map in texmgr

    public:

    std::stack<GameState*> states; //State storage
        //Stack allows us to add new states over the top of old ones whilst keeping track of old states
        //e.g) push pause state, remove pause (now we're back in the state before paused)

    sf::RenderWindow window; //Window to draw game to
    TextureManager texmgr;
    sf::Sprite background; //Sprites are drawable and mutable

    void pushState(GameState* state); //
    void popState();
    void changeState(GameState* state);
    GameState* peekState();

    void gameLoop(); //calls virtual functions on game_state

    Game();
    ~Game();
};

#endif
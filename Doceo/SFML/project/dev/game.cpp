#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"

Game::Game()
{
    this->loadTextures(); //load BG

    this->window.create(sf::VideoMode(800, 600), "City Builder");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texmgr.getRef("background")); //Update bg var with texmgr
}

void Game::pushState(GameState* state)
{
    this->states.push(state);

    return;
}

void Game::popState()
{
    delete this->states.top();
    this->states.pop();

    return;
}

void Game::changeState(GameState* state)
{
    if(!this->states.empty())
        popState();
    pushState(state);

    return;
}

GameState* Game::peekState()
{
    if(this->states.empty()) return nullptr;
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;

    while(this->window.isOpen())
    {

        //Want time to progress at same rate regardlless of fps
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds(); //time step
            // Start timer when a frame beings
            // End timer when frame stops
            // elapsed time stored in dt -> timestep variable
            // i.e) Storing the time it takes to render 1 frame
            // This stored time is passed to any function that needs the game speed
            // e,g) Want: Car move at 20 px/s
            //            And each frame takes 0.1 sec to render
            //            Then the car needs to move 2 pixels this frame

                        
                      

        if(peekState() == nullptr) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

void Game::loadTextures()
{
    texmgr.loadTexture("background", "media/background.png");
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}
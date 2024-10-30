#include <SFML/Graphics.hpp>

#include "game_state_start.hpp"
#include "game_state_editor.hpp"
#include "game_state.hpp"

void GameStateStart::draw(const float dt)
{
    this->game->window.setView(this->view); //Change view that is currently being drawn to the window
        //View takes up entire window, Everyting in this state will be drawn to it

    this->game->window.clear(sf::Color::Black);
    this->game->window.draw(this->game->background);
        //Draw arguements to the window's current view

    return;
}

void GameStateStart::update(const float dt)
{
}

void GameStateStart::handleInput()
{

    //SFML consider any interaction with a window input
    //When input occurs an event is triggered (Sounds like a design pattern can be added here)
    //Events store information about the interaction (coammnds pattern?)
        // i.e) Button Pressed event will contain a reference to the button all other required info  
    //Use pollEvent to process Events (part of the sf::window)
        //Takes in an sf::Event as an arg
        //returns true if there are still events left to process (done sequentially)
        //then use a switch statement to determine the type of event and what to do

    sf::Event event;

    while(this->game->window.pollEvent(event))
    {
        switch(event.type)
        {
            /* Close the window */
            case sf::Event::Closed:
            {
                game->window.close();
                break; //closes window
            }
            /* Resize the window */
            case sf::Event::Resized:
            {
                //Adjust view to match resized value so that the pixels don't stretch/distort
                this->view.setSize(event.size.width, event.size.height); //keeps a 1:1 relation between view and window size
                this->game->background.setPosition(this->game->window.mapPixelToCoords(sf::Vector2i(0, 0))); //create a mathematical vector of type int (point 0,0)
                    //Note: Location on window != world co-ordinates
                    //MapPixel function converts window co-oridnates to world co-ordinates using the curretn view
                    //This allows the background to stay the same regardless of what we do to the view
                this->game->background.setScale( //Make sure background takes up entire window
                    float(event.size.width) / float(this->game->background.getTexture()->getSize().x),
                    float(event.size.height) / float(this->game->background.getTexture()->getSize().y));
                break;
            }
            case sf::Event::KeyPressed:
            {
                if(event.key.code == sf::Keyboard::Escape) this->game->window.close(); //close window if user presses escape
                else if(event.key.code == sf::Keyboard::Space) this->loadgame(); //loadgame if user presses space
                break;
            }
            default: break;
        }
    }

    return;
}

GameStateStart::GameStateStart(Game* game)
{
    this->game = game;
    //Set view size to that of the window
    sf::Vector2f pos = sf::Vector2f(this->game->window.getSize()); 
    this->view.setSize(pos); 
    //Center view at the center of the window
    pos *= 0.5f; //vector multiplacation
    this->view.setCenter(pos); //Set to half the window size (2d vector * 0.5 -> (800,400) -> (400,200) which is the center of our window)
}

void GameStateStart::loadgame()
{
    this->game->pushState(new GameStateEditor(this->game)); //Push game editor state to the states tack of the game object 
    //Change state

    return;
}

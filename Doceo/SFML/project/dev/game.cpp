#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "game.hpp"
#include "game_state.hpp"
#include "texture_manager.hpp"
#include "animation_handler.hpp"
#include "tile.hpp"

Game::Game()
{
    this->loadTextures(); //load BG & other textures from files
    this->loadTiles(); //Init atlas
    this->loadFonts();
	this->loadStylesheets();

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
    
    texmgr.loadTexture("grass",         "media/grass.png");
    texmgr.loadTexture("forest",        "media/forest.png");
    texmgr.loadTexture("water",         "media/water.png");
    texmgr.loadTexture("residential",   "media/residential.png");
    texmgr.loadTexture("commercial",    "media/commercial.png");
    texmgr.loadTexture("industrial",    "media/industrial.png");
    texmgr.loadTexture("road",          "media/road.png");

    texmgr.loadTexture("background", "media/background.png");

}

void Game::loadTiles()
{
    Animation staticAnim(0, 0, 1.0f);
    //Create a new animation
    //Used for tiles with a single animations (static objects)
    //Start Frame = 0. End Frame = 0, duration = 1 sec

    //Creating tiles and adding them to our atlas
    
        //Add new entry to tileAtlas
            //String -> Tile
    this->tileAtlas["grass"] =
        Tile(this->tileSize, 1, texmgr.getRef("grass"),
            { staticAnim },
            TileType::GRASS, 50, 0, 1);
                //construction cost = 50
                //population per tile = 0
                //max variants = 1

    tileAtlas["forest"] =
        Tile(this->tileSize, 1, texmgr.getRef("forest"),
            { staticAnim },
            TileType::FOREST, 100, 0, 1);

    tileAtlas["water"] =
        Tile(this->tileSize, 1, texmgr.getRef("water"),
            { Animation(0, 3, 0.5f),
            Animation(0, 3, 0.5f),
            Animation(0, 3, 0.5f) },
            TileType::WATER, 0, 0, 1);

    tileAtlas["residential"] =
        Tile(this->tileSize, 2, texmgr.getRef("residential"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim },
            TileType::RESIDENTIAL, 300, 50, 6);

    tileAtlas["commercial"] =
        Tile(this->tileSize, 2, texmgr.getRef("commercial"),
            { staticAnim, staticAnim, staticAnim, staticAnim},
            TileType::COMMERCIAL, 300, 50, 4);
    tileAtlas["industrial"] =
        Tile(this->tileSize, 2, texmgr.getRef("industrial"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim },
            TileType::INDUSTRIAL, 300, 50, 4);

    tileAtlas["road"] =
        Tile(this->tileSize, 1, texmgr.getRef("road"),
            { staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim, staticAnim,
            staticAnim, staticAnim },
            TileType::ROAD, 100, 0, 1);

    return;
}

void Game::loadFonts()
{
    sf::Font font;
    font.loadFromFile("media/font.ttf");
    this->fonts["main_font"] = font;

    return;
}

void Game::loadStylesheets()
{
    this->stylesheets["button"] = GuiStyle(&this->fonts.at("main_font"), 1,
        sf::Color(0xc6,0xc6,0xc6), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00),
        sf::Color(0x61,0x61,0x61), sf::Color(0x94,0x94,0x94), sf::Color(0x00,0x00,0x00));
    this->stylesheets["text"] = GuiStyle(&this->fonts.at("main_font"), 0,
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0xff,0xff),
        sf::Color(0x00,0x00,0x00,0x00), sf::Color(0x00,0x00,0x00), sf::Color(0xff,0x00,0x00));

    return;
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}

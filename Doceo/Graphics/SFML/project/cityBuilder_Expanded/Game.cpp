#include "Game.h"
#include "GameState.h"

#include <SFML/System.hpp>


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
                                           sf::Color(0xc6, 0xc6, 0xc6), sf::Color(0x94, 0x94, 0x94), sf::Color(0x00, 0x00, 0x00),
                                           sf::Color(0x61, 0x61, 0x61), sf::Color(0x94, 0x94, 0x94), sf::Color(0x00, 0x00, 0x00));
    this->stylesheets["text"] = GuiStyle(&this->fonts.at("main_font"), 0,
                                         sf::Color(0x00, 0x00, 0x00, 0x00), sf::Color(0x00, 0x00, 0x00), sf::Color(0xff, 0xff, 0xff),
                                         sf::Color(0x00, 0x00, 0x00, 0x00), sf::Color(0x00, 0x00, 0x00), sf::Color(0xff, 0x00, 0x00));

    return;
}

void Game::loadTiles()
{
    Animation staticAnim(0, 0, 1.0f);
    this->tileAtlas["grass"] = Factory.at("grass")->Create(texmgr.getRef("grass"), {staticAnim});
    this->tileAtlas["forest"] = Factory.at("forest")->Create(texmgr.getRef("forest"), {staticAnim});
    this->tileAtlas["water"] = Factory.at("water")->Create(texmgr.getRef("water"),{Animation(0, 3, 0.5f), Animation(0, 3, 0.5f), Animation(0, 3, 0.5f)});
    this->tileAtlas["residential"] = Factory.at("residential")->Create(texmgr.getRef("residential"), {staticAnim, staticAnim, staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["commercial"] = Factory.at("commercial")->Create(texmgr.getRef("commercial"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["industrial"] = Factory.at("industrial")->Create(texmgr.getRef("industrial"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["landmark"] = Factory.at("landmark")->Create(texmgr.getRef("landmark"), {staticAnim, staticAnim, staticAnim, staticAnim});
    this->tileAtlas["road"] = Factory.at("road")->Create(texmgr.getRef("road"),{staticAnim, staticAnim, staticAnim, staticAnim, 
                                                                staticAnim, staticAnim, staticAnim, staticAnim, 
                                                                    staticAnim, staticAnim, staticAnim});

    return;
}

void Game::loadTextures()
{
    texmgr.loadTexture("grass",         "media/grass.png");
    texmgr.loadTexture("forest",        "media/forest.png");
    texmgr.loadTexture("water",         "media/water.png");
    texmgr.loadTexture("residential",   "media/residential.png");
    texmgr.loadTexture("commercial",    "media/commercial.png");
    texmgr.loadTexture("industrial",    "media/industrial.png");
    texmgr.loadTexture("landmark",    "media/landmarks.png");
    texmgr.loadTexture("road",          "media/road.png");
 
    texmgr.loadTexture("background",    "media/background.png");
}

void Game::loadFactories()
{
    this->Factory["grass"] = new GrassFactory();
    this->Factory["forest"] = new ForestFactory();
    this->Factory["water"] = new WaterFactory();
    this->Factory["residential"] = new ResidentialFactory();
    this->Factory["commercial"] = new CommercialFactory();
    this->Factory["industrial"] = new IndustrialFactory();
    this->Factory["landmark"] = new LandmarkFactory();
    this->Factory["road"] = new RoadFactory();
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
    if(this->states.empty()) return NULL;
    return this->states.top();
}

void Game::gameLoop()
{
    sf::Clock clock;
    float dt;

    while(this->window.isOpen())
    {
        dt = clock.restart().asSeconds();

        if(peekState() == NULL) continue;
        peekState()->handleInput();
        peekState()->update(dt);
        this->window.clear(sf::Color::Black);
        peekState()->draw(dt);
        this->window.display();
    }
}

Game::Game()
{
    this->loadTextures();
    this->loadFactories();
    this->loadTiles();
    this->loadFonts();
	this->loadStylesheets();

    this->window.create(sf::VideoMode(800, 600), "City Builder");
    this->window.setFramerateLimit(60);

    this->background.setTexture(this->texmgr.getRef("background"));
}

Game::~Game()
{
    while(!this->states.empty()) popState();
}

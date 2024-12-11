#include <SFML/Graphics.hpp>
 
#include "AnimationHandler.h"
#include "Tile.h"


Tile::Tile(const unsigned int tileSize, const unsigned int height, sf::Texture &texture,
     const std::vector<Animation> &animations,
     const TileType tileType, const unsigned int cost, const unsigned int maxPopPerLevel,
     const unsigned int maxLevels)
{
    this->tileType = tileType;
    this->tileVariant = 0;
    this->regions[0] = 0;

    this->cost = cost;
    this->population = 0;
    this->maxPopPerLevel = maxPopPerLevel;
    this->maxLevels = maxLevels;
    this->production = 0;
    this->storedGoods = 0;

    this->sprite.setOrigin(sf::Vector2f(0.0f, tileSize * (height - 1)));
    this->sprite.setTexture(texture);
    this->animHandler.frameSize = sf::IntRect(0, 0, tileSize * 2, tileSize * height);
    for (auto animation : animations)
    {
        this->animHandler.addAnim(animation);
    }
    this->animHandler.update(0.0f);
}

Tile::Tile(Tile* tile)
{
    this->tileType = tile->tileType;
    this->tileVariant = 0;
    this->regions[0] = 0;

    this->cost = tile->cost;
    this->population = 0;
    this->maxPopPerLevel = tile->maxPopPerLevel;
    this->maxLevels = tile->maxLevels;
    this->production = 0;
    this->storedGoods = 0;

    // this->sprite.setOrigin(sf::Vector2f(0.0f, tileSize * (height - 1)));
    // this->sprite.setTexture(texture);
    this->sprite = tile->sprite;
    // this->animHandler.frameSize = sf::IntRect(0, 0, tileSize * 2, tileSize * height);
    // for (auto animation : animations)
    // {
    //     this->animHandler.addAnim(animation);
    // }
    this->animHandler.frameSize = tile->animHandler.frameSize;
    this->animHandler = tile->animHandler;
    this->animHandler.update(0.0f);
}

Tile* Tile::clone()
{
    return new Tile(*this);
}

void Tile::draw(sf::RenderWindow& window, float dt)
{
    /* Change the sprite to reflect the tile variant */
    this->animHandler.changeAnim(this->tileVariant);
 
    /* Update the animation */
    this->animHandler.update(dt);
 
    /* Update the sprite */
    this->sprite.setTextureRect(this->animHandler.bounds);
 
    /* Draw the tile */
    window.draw(this->sprite);
 
    return;
}
 
void Tile::update()
{
    /* If the population is at the maximum value for the tile,
     * there is a small chance that the tile will increase its
     * building stage */
    if((this->tileType == TileType::RESIDENTIAL ||
        this->tileType == TileType::COMMERCIAL ||
        this->tileType == TileType::INDUSTRIAL ||
        this->tileType == TileType::LANDMARK) &&
        this->population == this->maxPopPerLevel * (this->tileVariant+1) &&
        this->tileVariant < this->maxLevels)
    {
        if(rand() % int(1e4) < 1e2 / (this->tileVariant+1)) ++this->tileVariant;
    }
 
}
/* Return a string containing the display cost of the tile */
std::string Tile::getCost()
{
    return std::to_string(this->cost);
}

std::string tileTypeToStr(TileType type)
{
    switch(type)
    {
        default:
        case TileType::VOID:            return "Void";
        case TileType::GRASS:           return "Flatten";
        case TileType::FOREST:          return "Forest";
        case TileType::WATER:           return "Water";
        case TileType::RESIDENTIAL:     return "Residential Zone";
        case TileType::COMMERCIAL:      return "Commercial Zone";
        case TileType::INDUSTRIAL:      return "Industrial Zone";
        case TileType::LANDMARK:        return "landmark Zone";
    }
}

void Tile::setMediator(CityMediator* mediator){
    this->mediator = mediator;
}

void Tile::notify(std::string notification){
    this->mediator->notify(this, notification);
}
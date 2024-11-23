#include "ForestFactory.h"

Tile* ForestFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Forest(texture, animations);
}
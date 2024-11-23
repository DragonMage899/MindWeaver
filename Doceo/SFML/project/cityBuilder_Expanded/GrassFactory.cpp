#include "GrassFactory.h"

Tile* GrassFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Grass(texture, animations);
}
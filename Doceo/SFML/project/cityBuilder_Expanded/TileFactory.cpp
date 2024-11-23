#include "TileFactory.h"

Tile* TileFactory::Create(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return CreateTile(texture, animations);
}
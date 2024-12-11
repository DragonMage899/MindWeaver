#include "WaterFactory.h"

Tile* WaterFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Water(texture, animations);
}
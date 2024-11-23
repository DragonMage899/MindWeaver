#include "IndustrialFactory.h"

Tile* IndustrialFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Industrial(texture, animations);
}
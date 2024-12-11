#include "ResidentialFactory.h"

Tile* ResidentialFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Residential(texture, animations);
}
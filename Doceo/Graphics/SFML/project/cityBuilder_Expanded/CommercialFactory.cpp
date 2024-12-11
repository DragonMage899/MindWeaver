#include "CommercialFactory.h"

Tile* CommercialFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Commercial(texture, animations);
}
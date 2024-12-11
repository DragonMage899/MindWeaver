#include "RoadFactory.h"

Tile* RoadFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Road(texture, animations);
}
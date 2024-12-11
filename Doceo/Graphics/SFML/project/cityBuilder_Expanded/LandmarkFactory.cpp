#include "LandmarkFactory.h"

Tile* LandmarkFactory::CreateTile(sf::Texture &texture, const std::vector<Animation> &animations)
{
    return new Landmark(texture, animations);
}
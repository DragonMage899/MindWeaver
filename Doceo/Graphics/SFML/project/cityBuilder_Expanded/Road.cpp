#include "Road.h"

Road::Road(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 1, texture, animations, TileType::ROAD, 100, 0, 1)
{}
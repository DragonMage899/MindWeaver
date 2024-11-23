#include "Forest.h"

Forest::Forest(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 1, texture, animations, TileType::FOREST, 100, 0, 1)
{}

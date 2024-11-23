#include "Grass.h"

Grass::Grass(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 1, texture, animations, TileType::GRASS, 50, 0, 1)
{}
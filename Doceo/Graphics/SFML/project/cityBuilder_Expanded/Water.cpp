#include "Water.h"

Water::Water(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 1, texture, animations, TileType::WATER, 0, 0, 1)
{}

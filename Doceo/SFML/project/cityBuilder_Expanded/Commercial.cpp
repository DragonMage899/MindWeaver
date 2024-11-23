#include "Commercial.h"

Commercial::Commercial(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::COMMERCIAL, 300, 50, 4)
{}
#include "Residential.h"

Residential::Residential(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::RESIDENTIAL, 300, 50, 6)
{}
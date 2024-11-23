#include "Landmark.h"

Landmark::Landmark(sf::Texture &texture,  const std::vector<Animation> &animations)
    :Tile(8, 2, texture, animations, TileType::LANDMARK, 100, 50, 4)
{}
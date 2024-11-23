#ifndef WATER_H
#define WATER_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Water : public Tile
{
public:

    /* Constructor */
    Water(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
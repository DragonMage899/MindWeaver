#ifndef GRASS_H
#define GRASS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Grass : public Tile
{
public:

    /* Constructor */
    Grass(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
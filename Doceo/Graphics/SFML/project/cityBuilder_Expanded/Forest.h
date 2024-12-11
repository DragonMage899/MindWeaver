#ifndef FOREST_H
#define FOREST_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Forest : public Tile
{
public:

    /* Constructor */
    Forest(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
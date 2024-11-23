#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Residential : public Tile
{
public:

    /* Constructor */
    Residential(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
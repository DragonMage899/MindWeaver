#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Commercial : public Tile
{
public:

    /* Constructor */
    Commercial(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Industrial : public Tile
{
public:

    /* Constructor */
    Industrial(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
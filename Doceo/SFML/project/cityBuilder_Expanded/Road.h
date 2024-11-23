#ifndef ROAD_H
#define ROAD_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Road : public Tile
{
public:

    /* Constructor */
    Road(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
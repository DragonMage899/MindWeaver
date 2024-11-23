#ifndef LANDMARK_H
#define LANDMARK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"

class Landmark : public Tile
{
public:

    /* Constructor */
    Landmark(sf::Texture &texture, const std::vector<Animation> &animations);

};

#endif /* TILE_HPP */
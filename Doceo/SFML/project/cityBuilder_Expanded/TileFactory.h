#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include <SFML/Graphics.hpp>
#include "Tile.h"


class TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations) = 0;
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
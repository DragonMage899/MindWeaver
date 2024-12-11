#ifndef INDUSTRIALFACTORY_H
#define INDUSTRIALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Industrial.h"

class IndustrialFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
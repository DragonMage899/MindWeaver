#ifndef ROADFACTORY_H
#define ROADFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Road.h"

class RoadFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
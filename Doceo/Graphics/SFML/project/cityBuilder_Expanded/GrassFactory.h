#ifndef GRASSFACTORY_H
#define GRASSFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Grass.h"

class GrassFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
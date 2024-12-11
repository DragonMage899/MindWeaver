#ifndef RESIDENTIALFACTORY_H
#define RESIDENTIALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Residential.h"

class ResidentialFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
#ifndef COMMERCIALFACTORY_H
#define COMMERCIALFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Commercial.h"

class CommercialFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
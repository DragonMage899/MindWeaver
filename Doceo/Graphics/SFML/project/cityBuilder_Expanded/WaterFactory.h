#ifndef WATERFACTORY_H
#define WATERFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Water.h"

class WaterFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
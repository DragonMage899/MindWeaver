#ifndef FORESTFACTORY_H
#define FORESTFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Forest.h"


class ForestFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
#ifndef LANDMARKFACTORY_H
#define LANDMARKFACTORY_H

#include <SFML/Graphics.hpp>
#include "TileFactory.h"
#include "Landmark.h"


class LandmarkFactory : public TileFactory
{
protected:
    virtual Tile* CreateTile(sf::Texture &texture, const std::vector<Animation> &animations);
public:
    Tile* Create(sf::Texture &texture, const std::vector<Animation> &animations);

    
};

#endif /* GAME_HPP */
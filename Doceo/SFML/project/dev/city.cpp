#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

#include "city.hpp"
#include "tile.hpp"

double City::distributePool(double& pool, Tile& tile, double rate = 0.0)
{
    const static int moveRate = 4;

    unsigned int maxPop = tile.maxPopPerLevel * (tile.tileVariant+1);

    /* If there is room in the zone, move up to 4 people from the
     * pool into the zone */
    if(pool > 0)
    {
        int moving = maxPop - tile.population;
        if(moving > moveRate) moving = moveRate;
        if(pool - moving < 0) moving = pool;
        pool -= moving;
        tile.population += moving;
    }

    /* Adjust the tile population for births and deaths */
    tile.population += tile.population * rate;

    /* Move population that cannot be sustained by the tile into
     * the pool */
    if(tile.population > maxPop)
    {
        pool += tile.population - maxPop;
        tile.population = maxPop;
    }

    return tile.population;
}
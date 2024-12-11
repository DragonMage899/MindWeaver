#include "CityMediator.h"

#include <string>
#include <random>

CityMediator::CityMediator(City gameCity) : city(gameCity ){}

CityMediator::CityMediator(){}

void CityMediator::notify(Tile* tile, std::string notification){

    if(notification == "fireAlert" && tile->tileType == TileType::RESIDENTIAL){
        //check if house is connnected to a fireStation using depth first search (will check spec on that after I eat)
        //if not destroy house and add to population pool, dec from population
    }

}
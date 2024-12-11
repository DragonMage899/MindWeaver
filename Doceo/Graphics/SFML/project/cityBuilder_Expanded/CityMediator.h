#ifndef CITYMEDIATOR_H
#define CITYMEDIATOR_H

#include "City.h"
#include "Tile.h"

class CityMediator{
    private:
    City city;
    void react();

    public:
    CityMediator();
    CityMediator(City city);


    void setCity(City city);
    void getCity(City city);
    void notify(Tile* tile, std::string notification);
};

#endif
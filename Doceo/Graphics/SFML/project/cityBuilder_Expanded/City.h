#ifndef CITY_H
#define CITY_H

#include <vector>
#include <map>

#include "Map.h"
#include "Tile.h"
#include "CityMediator.h"
#include "Command.h"

#include "TaxPolicy.h"
#include "LowTax.h"
#include "MidTax.h"
#include "HighTax.h"

class City
{
protected:
    std::vector<Command*> commands;

    float currentTime;
    float timePerDay;

    TaxPolicy* taxPolicy;

    std::vector<int> shuffledTiles;

    /* Number of residents who are not in a residential zone. */
    double populationPool;

    /* Number of residents who are not currently employed but can work. */
    double employmentPool;

    /* Proportion of citizens who can work. */
    float propCanWork;

    /* Proportion of residents who die/give birth each day.
     * Estimate for death rate = 1 / (life expectancy * 360)
     * Current world values are 0.000055 and 0.000023, respectively */
    double birthRate;
    double deathRate;

    double distributePool(double &pool, Tile *tile, double rate);

public:
    Map map;
    friend class CityMediator;
    friend class Command;

    void addCommand(Command* cmd); //has a reference to a Tile that we need to execute on
    void executeCommands(); //Clean up commands vector when done

    double population;
    double employable;

    double residentialTax;
    double commercialTax;
    double industrialTax;

    /* Running total of city earnings (from tax etc) this month. */
    double earnings;
    double funds;

    int day;

    City()
    {
        this->birthRate = 0.00055;
        this->deathRate = 0.00023;
        this->propCanWork = 0.50;
        this->populationPool = 0;
        this->population = populationPool;
        this->employmentPool = 0;
        this->employable = employmentPool;
        this->residentialTax = 0.05;
        this->commercialTax = 0.05;
        this->industrialTax = 0.05;
        this->earnings = 0;
        this->funds = 0;
        this->currentTime = 0.0;
        this->timePerDay = 0.1;
        this->day = 0;
        this->taxPolicy = new LowTax();
    }

    City(std::string cityName, int tileSize, std::map<std::string, Tile*> &tileAtlas) : City()
    {
        this->map.tileSize = tileSize;
        load(cityName, tileAtlas);
    }

    void load(std::string cityName, std::map<std::string, Tile*> &tileAtlas);
    void save(std::string cityName);

    void update(float dt);
    void bulldoze(Tile &tile);
    void shuffleTiles();
    void tileChanged();

    double getHomeless() { return this->populationPool; }
    double getUnemployed() { return this->employmentPool; }

    void setTaxPolicy(TaxPolicy* policy);
    std::string getTaxPolicy();
};

#endif /* CITY_HPP */

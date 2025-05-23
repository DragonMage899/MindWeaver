#ifndef CITY_HPP
#define CITY_HPP

#include <vector>
#include <map>

#include "map.hpp"

class City
{
    private:

    float currentTime; //real world time (sec) since the day updated
    float timePerDay; //Seconds each day should last
        //Add a function for speed up and speed down?
        //Game world updates at the end of each day

    std::vector<int> shuffledTiles;
        //randomizes tile vector so that updates are not predictable
        //e.g) house at 0,0 always being filled before house at 5,5

    /* Number of residents who are not in a residential zone */
    //Note: Each tile has a population value, if someone moves into that house, the population of that tile increases
    //and the population pool decreases  
    double populationPool;

    /* Number of residents who are not currently employed but can work */
    //Works similar to population
    double employmentPool;

    /* Proportion of citizens who can work */
    float propCanWork;

    /* Proportion of residents who die/give birth each day
     * Estimate for death rate = 1 / (life expectancy * 360)
     * Current world values are 0.000055 and 0.000023, respectively */
    double birthRate;
    double deathRate;

    //move citizens around
    double distributePool(double& pool, Tile& tile, double rate);

    public:

    Map map;

    double population; //tile population + population pool
    double employable;


    //Tax
    double residentialTax; 
    double commercialTax;
    double industrialTax;

    /* Running total of city earnings (from tax etc) this month */
    double earnings; //funds += earning every 30 days
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
    }

    City(std::string cityName, int tileSize, std::map<std::string, Tile>& tileAtlas) : City()
    {
        this->map.tileSize = tileSize;
        load(cityName, tileAtlas);
    }

    void load(std::string cityName, std::map<std::string, Tile>& tileAtlas);
    void save(std::string cityName);

    void update(float dt); //Move people around
    void bulldoze(const Tile& tile); 
    void shuffleTiles(); //randomize tiles
    void tileChanged(); //Update tile orientation
    void adjustPopulation(double popPool, double birthRate, double deathRate);

    double getHomeless() { return this->populationPool; }
    double getUnemployed() { return this->employmentPool; }
};

#endif
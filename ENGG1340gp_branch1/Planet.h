#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <map>

class Planet {
public:
    std::string name;
    std::map<std::string, int> marketPrices;

    Planet(); // Added a default constructor
    Planet(std::string name);
    void generateMarketPrices();
};

#endif // PLANET_H


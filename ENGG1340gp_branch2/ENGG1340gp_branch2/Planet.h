#ifndef PLANET_H
#define PLANET_H

#include <string>

typedef struct Planet {
    std::string name;
    int distance_from_sun;
    int marketPrices[4]; // Changed to an array from std::map
} Planet;

void initPlanet(Planet* planet, std::string name, int distance_from_sun);
void generateMarketPrices(Planet* planet);
int getDistanceFromSun(Planet* planet);

#endif // PLANET_H



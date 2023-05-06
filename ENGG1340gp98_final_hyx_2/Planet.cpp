#include "Planet.h"
#include <cstdlib>

void initPlanet(Planet* planet, std::string name, int distance_from_sun) {
    planet->name = name;
    planet->distance_from_sun = distance_from_sun;
}

void generateMarketPrices(Planet* planet) {
    for (int i = 0; i < 4; ++i) {
        planet->marketPrices[i] = rand() % 100 + 1; // Random price between 1 and 100
    }
}

int getDistanceFromSun(Planet* planet) {
    return planet->distance_from_sun;
}


//planet花费一些食物
//独特的星球上有特定的赚钱方式
//地球：模拟赛马，
//21点等游戏
//
//
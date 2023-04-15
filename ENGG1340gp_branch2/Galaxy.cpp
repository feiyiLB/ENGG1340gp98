#include "Galaxy.h"
#include <cstdlib>
#include <cstring>

void initGalaxy(Galaxy* galaxy, int num_planets) {
    galaxy->num_planets = num_planets;
    galaxy->planets = new Planet[num_planets];
    generateGalaxy(galaxy);
}

void freeGalaxy(Galaxy* galaxy) {
    delete[] galaxy->planets;
}

void generateGalaxy(Galaxy* galaxy) {
    const char* planet_names[] = {"Earth", "Mars", "Venus", "Jupiter", "Saturn", "Uranus", "Neptune"};
    int planet_distances[] = {1, 2, 3, 4, 5, 6, 7};
    int num_planet_names = sizeof(planet_names) / sizeof(planet_names[0]);

    for (int i = 0; i < galaxy->num_planets; ++i) {
        int name_index = rand() % num_planet_names;
        int distance = planet_distances[name_index];

        initPlanet(&galaxy->planets[i], planet_names[name_index], distance);
        generateMarketPrices(&galaxy->planets[i]);

        // Remove the used planet name and distance
        for (int j = name_index; j < num_planet_names - 1; ++j) {
            planet_names[j] = planet_names[j + 1];
            planet_distances[j] = planet_distances[j + 1];
        }
        num_planet_names--;
    }
}

#include "Galaxy.h"
#include <cstdlib>
#include <vector> // Included the <vector> header
#include <string> // Included the <string> header

Galaxy::Galaxy(int num_planets) : num_planets(num_planets) {
    planets = new Planet[num_planets];
    generateGalaxy();
}

Galaxy::~Galaxy() {
    delete[] planets;
}

void Galaxy::generateGalaxy() {
    std::vector<std::string> planet_names = {"Earth", "Mars", "Venus", "Jupiter", "Saturn", "Uranus", "Neptune"};
    for (int i = 0; i < num_planets; ++i) {
        int name_index = rand() % planet_names.size();
        planets[i] = Planet(planet_names[name_index]);
        planets[i].generateMarketPrices();
        planet_names.erase(planet_names.begin() + name_index); // Remove the used planet name
    }
}

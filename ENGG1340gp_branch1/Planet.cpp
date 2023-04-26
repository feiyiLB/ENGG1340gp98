#include "Planet.h"
#include <vector>
#include <cstdlib>

Planet::Planet() {} // Added a default constructor implementation

Planet::Planet(std::string name) : name(name) {}

void Planet::generateMarketPrices() {
    std::vector<std::string> goods = {"food", "water", "fuel", "metals"};
    for (const auto& good : goods) {
        marketPrices[good] = rand() % 100 + 1; // Random price between 1 and 100
    }
}


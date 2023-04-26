#include "Event.h"
#include <cstdlib>
#include <iostream>

void PirateEvent::execute(Player& player) {
    std::string good = "food"; // In this example, pirates will always steal food
    int stolen_amount = rand() % 10 + 1; // Random amount between 1 and 10

    int current_quantity = player.getCargoQuantity(good);
    int new_quantity = std::max(0, current_quantity - stolen_amount);
    player.removeCargo(good, stolen_amount);

    std::cout << "Pirates have stolen " << (current_quantity - new_quantity) << " units of " << good << "!\n";
}


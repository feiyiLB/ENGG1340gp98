#include "Event.h"
#include <iostream>
#include <cstdlib>

void execute_pirate_event(Player* player, PirateEvent* pirate_event) {
    std::cout << "A pirate ship appears and steals some of your cargo!\n";
    const char* goods[] = {"food", "water", "fuel", "metals", "money"};
    for (int i = 0; i < 5; ++i) {
        pirate_event->stolen_goods[i] = rand() % (getCargoQuantity(player, goods[i]) + 1);
        removeCargo(player, goods[i], pirate_event->stolen_goods[i]);
        std::cout << "The pirates stole " << pirate_event->stolen_goods[i] << " units of " << goods[i] << ".\n";
    }
}
// Add this function definition to Event.cpp#include "Event.h"
#include "Player.h"
#include "Planet.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

// Add this function definition to Event.cpp
void Travel(Player* player, Planet* current_planet, Planet* destination_planet) {
    int distance = abs(destination_planet->distance_from_sun - current_planet->distance_from_sun);
    int food_consumption = distance * 10;
    int water_consumption = distance * 5;
    int fuel_consumption = distance * 20;
    removeCargo(player, "food", food_consumption);
    removeCargo(player, "water", water_consumption);
    removeCargo(player, "fuel", fuel_consumption);

    std::cout << "You traveled " << distance << " units.\n";
    std::cout << "Food consumed: " << food_consumption << " units.\n";
    std::cout << "Water consumed: " << water_consumption << " units.\n";
    std::cout << "Fuel consumed: " << fuel_consumption << " units.\n";
}


/*
分为两类
星球之间的时间
星球之上的事件
*/
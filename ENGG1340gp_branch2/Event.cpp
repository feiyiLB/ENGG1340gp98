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

/*
分为两类
星球之间的时间
星球之上的事件
*/
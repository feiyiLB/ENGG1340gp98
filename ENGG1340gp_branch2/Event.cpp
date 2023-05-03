#include "Event.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
void execute_pirate_event(Player* player, PirateEvent* pirate_event) {
    std::cout << "A pirate ship appears and steals some of your cargo!\n";
    const char* goods[] = {"food", "water", "fuel", "metals", "money"};
    for (int i = 0; i < 5; ++i) {
        pirate_event->stolen_goods[i] = rand() % (getCargoQuantity(player, goods[i])/2 + 1);
        removeCargo(player, goods[i], pirate_event->stolen_goods[i]);
        Sleep(500);
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
    int food_consumption = distance * 1;
    int water_consumption = distance * 1;
    int fuel_consumption = distance * 3;
    removeCargo(player, "food", food_consumption);
    removeCargo(player, "water", water_consumption);
    removeCargo(player, "fuel", fuel_consumption);

    std::cout << "You traveled " << distance << " units.\n";
    std::cout << "Food consumed: " << food_consumption << " units.\n";
    std::cout << "Water consumed: " << water_consumption << " units.\n";
    std::cout << "Fuel consumed: " << fuel_consumption << " units.\n";
}

void Container(Player* player)
{
    //srand((int)time(NULL));
    int ran[6],a,b,add[5] = {0,0,0,0,0};
    b = rand()%5+0;
    for (int i = 0;i < b;i++)
    {
        a = rand()%4+0;
        add[a] += rand()%10+1;
    }
    if (b != 0)
    {
        for (int i = 0;i<5;i++)
        {
            if (add[i]!=0)
            {
                if(i == 0)
                {
                    std::cout << "Gain Food : " << add[i] << " units.\n";
                    addCargo(player,"food",add[i]);
                }
                else if(i == 1)
                {
                    std::cout << "Gain Water : " << add[i] << " units.\n";
                    addCargo(player,"water",add[i]);
                }
                else if(i == 2)
                {
                    std::cout << "Gain Money : " << add[i] << " units.\n";
                    addCargo(player,"money",add[i]);
                }
                else if(i == 3)
                {
                    std::cout << "Gain Fuel : " << add[i] << " units.\n";
                    addCargo(player,"fuel",add[i]);
                }
                else if(i == 4)
                {
                    std::cout << "Gain Metals : " << add[i] << " units.\n";
                    addCargo(player,"metals",add[i]);
                }
            }
        }
    }
    else std::cout << "Oh, it is a fucking empty container!!!!.\n";
}

// void aerolite()
//bring damage


/*
boss事件

*/
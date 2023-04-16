#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"
#include "Galaxy.h"
#include "Event.h"
#include "Planet.h"
struct Game {
    Player player;
    Galaxy galaxy;
    Planet* current_planet;
    Planet* planet;
};

void displayMenu();
void displayCargo(Game* game);
void displayMarketPrices(Game* game);
void displayPlanetNamesAndDistances(Game* game);
void generateAndExecuteEvent(Game* game);
void run(Game* game);

#endif // GAME_H

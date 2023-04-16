#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Player.h"
#include "Galaxy.h"
#include "Event.h"

struct Game {
    Player player;
    Galaxy galaxy;
    Planet* current_planet;
};

void displayMenu();
void displayCargo(Game* game);
void displayMarketPrices(Game* game);
void displayPlanetNamesAndDistances(Game* game);
void generateAndExecuteEvent(Game* game);
void run(Game* game);

#endif // GAME_H

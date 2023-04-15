#ifndef PLAYER_H
#define PLAYER_H

#include "CargoItem.h"

typedef struct Player {
    CargoItem* head;
} Player;

void initPlayer(Player* player);
void freePlayer(Player* player);
void addCargo(Player* player, const char* good, int quantity);
void removeCargo(Player* player, const char* good, int quantity);
int getCargoQuantity(Player* player, const char* good);

#endif // PLAYER_H



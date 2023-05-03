#ifndef PLAYER_H
#define PLAYER_H

#include "CargoItem.h"

typedef struct Player {
    CargoItem* head;
    int player_hp;
    int player_energy;
    int player_normal_attack;
    int player_defense;
} Player;

void initPlayer(Player* player);
void freePlayer(Player* player);
void addCargo(Player* player, const char* good, int quantity);
void removeCargo(Player* player, const char* good, int quantity);
int getCargoQuantity(Player* player, const char* good);

void setPlayerHP(Player* player, int hp);
void setPlayerEnergy(Player* player, int energy);
void setPlayerNormalAttack(Player* player, int normal_attack);
void setPlayerDefense(Player* player, int defense);

void increasePlayerHP(Player* player, int hp_increase);
void increasePlayerEnergy(Player* player, int energy_increase);
void increasePlayerNormalAttack(Player* player, int normal_attack_increase);
void increasePlayerDefense(Player* player, int defense_increase);
void displayPlayerAttributes(Player* player);
#endif // PLAYER_H



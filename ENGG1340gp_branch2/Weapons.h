#ifndef WEAPONS_H
#define WEAPONS_H

#include "Player.h"

void displayWeaponMenu(int current_money);
int getWeaponPrice(int weapon_choice);
void applyWeaponEffect(Player* player, int weapon_choice);
void buyWeapon(Player* player);

#endif // WEAPONS_H

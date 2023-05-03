#ifndef WEAPONS_H
#define WEAPONS_H

#include "Player.h"

void displayAttributeMenu(int current_money);
int getAttributePrice(int attribute_choice);
void buyAttributeUpgrade(Player* player);

#endif // WEAPONS_H

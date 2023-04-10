#ifndef PLAYER_H
#define PLAYER_H

#include "CargoItem.h"

class Player {
public:
    CargoItem* head;

    Player();
    ~Player();

    void addCargo(const std::string& good, int quantity);
    void removeCargo(const std::string& good, int quantity);
    int getCargoQuantity(const std::string& good);
};

#endif // PLAYER_H


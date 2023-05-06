#include "Player.h"
#include <cstring>
using namespace std;
#include <iostream>
void initPlayer(Player* player) {
    player->head = nullptr;
    player->player_hp = 100;
    player->player_energy = 10;
    player->player_normal_attack = 5;
    player->player_defense = 5;
}

void freePlayer(Player* player) {
    CargoItem* current = player->head;
    while (current != nullptr) {
        CargoItem* to_delete = current;
        current = current->next;
        delete to_delete;
    }
}

void addCargo(Player* player, const char* good, int quantity) {
    CargoItem* current = player->head;
    CargoItem* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->good, good) == 0) {
            current->quantity += quantity;
            return;
        }
        prev = current;
        current = current->next;
    }

    CargoItem* new_cargo_item = createCargoItem(good, quantity);
    if (prev != nullptr) {
        prev->next = new_cargo_item;
    } else {
        player->head = new_cargo_item;
    }
}

void removeCargo(Player* player, const char* good, int quantity) {
    CargoItem* current = player->head;
    CargoItem* prev = nullptr;

    while (current != nullptr) {
        if (strcmp(current->good, good) == 0) {
            current->quantity -= quantity;
            if (current->quantity <= 0) {
                if (prev != nullptr) {
                    prev->next = current->next;
                } else {
                    player->head = current->next;
                }
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

int getCargoQuantity(Player* player, const char* good) {
    CargoItem* current = player->head;

    while (current != nullptr) {
        if (strcmp(current->good, good) == 0) {
            return current->quantity;
        }
        current = current->next;
    }
    return 0;
}
int getPlayerHP(const Player* player) {
    return player->player_hp;
}

int getPlayerEnergy(const Player* player) {
    return player->player_energy;
}

int getPlayerNormalAttack(const Player* player) {
    return player->player_normal_attack;
}

int getPlayerDefense(const Player* player) {
    return player->player_defense;
}



void setPlayerHP(Player* player, int hp) {
    player->player_hp = hp;
}

void setPlayerEnergy(Player* player, int energy) {
    player->player_energy = energy;
}

void setPlayerNormalAttack(Player* player, int normal_attack) {
    player->player_normal_attack = normal_attack;
}

void setPlayerDefense(Player* player, int defense) {
    player->player_defense = defense;
}

void increasePlayerHP(Player* player, int hp_increase) {
    player->player_hp += hp_increase;
}

void increasePlayerEnergy(Player* player, int energy_increase) {
    player->player_energy += energy_increase;
}

void increasePlayerNormalAttack(Player* player, int normal_attack_increase) {
    player->player_normal_attack += normal_attack_increase;
}

void increasePlayerDefense(Player* player, int defense_increase) {
    player->player_defense += defense_increase;
}
void displayPlayerAttributes(const Player* player) {
    cout << "Player's attributes:" << endl;
    cout << "Player HP: " << player->player_hp << endl;
    cout << "Player Energy: " << player->player_energy << endl;
    cout << "Player Normal Attack: " << player->player_normal_attack << endl;
    cout << "Player Defense: " << player->player_defense << endl;

}
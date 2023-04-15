#include "Player.h"
#include <cstring>

void initPlayer(Player* player) {
    player->head = nullptr;
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

#include "Player.h"

Player::Player() : head(nullptr) {}

Player::~Player() {
    CargoItem* current = head;
    while (current != nullptr) {
        CargoItem* to_delete = current;
        current = current->next;
        delete to_delete;
    }
}

void Player::addCargo(const std::string& good, int quantity) {
    CargoItem* current = head;
    CargoItem* prev = nullptr;

    while (current != nullptr) {
        if (current->good == good) {
            current->quantity += quantity;
            return;
        }
        prev = current;
        current = current->next;
    }

    CargoItem* new_cargo_item = new CargoItem(good, quantity);
    if (prev != nullptr) {
        prev->next = new_cargo_item;
    } else {
        head = new_cargo_item;
    }
}

void Player::removeCargo(const std::string& good, int quantity) {
    CargoItem* current = head;
    CargoItem* prev = nullptr;

    while (current != nullptr) {
        if (current->good == good) {
            current->quantity -= quantity;
            if (current->quantity <= 0) {
                if (prev != nullptr) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

int Player::getCargoQuantity(const std::string& good) {
    CargoItem* current = head;

    while (current != nullptr) {
        if (current->good == good) {
            return current->quantity;
        }
        current = current->next;
    }
    return 0;
}

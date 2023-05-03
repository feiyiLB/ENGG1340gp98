#include "Weapons.h"
#include "Player.h"
#include <iostream>

using namespace std;

void displayAttributeMenu(int current_money) {
    cout << "Attribute upgrades menu:\n";
    cout << "1. Player HP (Price: 11)\n";
    cout << "2. Player Energy (Price: 10)\n";
    cout << "3. Player Normal Attack (Price: 9)\n";
    cout << "4. Player Defense (Price: 8)\n";
    cout << "5. Display weapons menu\n";
    cout << "6. Exit\n";
    cout << "Current money: " << current_money << endl;
    cout << "Enter your attribute choice: ";
}

int getAttributePrice(int attribute_choice) {
    switch (attribute_choice) {
        case 1:
            return 11;
        case 2:
            return 10;
        case 3:
            return 9;
        case 4:
            return 8;
        default:
            return -1;
    }
}

void buyAttributeUpgrade(Player* player) {
    int attribute_choice;
    int quantity;

    while (true) {
        int current_money = getCargoQuantity(player, "money");
        displayAttributeMenu(current_money);
        cin >> attribute_choice;

        if (attribute_choice == 5) {
            displayAttributeMenu(current_money);
            continue;
        } else if (attribute_choice == 6) {
            break;
        }

        cout << "Enter quantity: ";
        cin >> quantity;

        int price = getAttributePrice(attribute_choice);
        if (price == -1) {
            cout << "Invalid attribute choice. Please try again.\n";
            continue;
        }

        int cost = quantity * price;

        if (current_money >= cost) {
            switch (attribute_choice) {
                case 1:
                    player->player_hp += quantity;
                    break;
                case 2:
                    player->player_energy += quantity;
                    break;
                case 3:
                    player->player_normal_attack += quantity;
                    break;
                case 4:
                    player->player_defense += quantity;
                    break;
                default:
                    cout << "Invalid attribute choice. Please try again.\n";
                    continue;
            }

            // Deduct money from the player's cargo
            removeCargo(player, "money", cost);
            cout << "Attribute upgraded successfully!\n";
        } else {
            cout << "Not enough money to buy the attribute upgrade.\n";
        }
    }
}

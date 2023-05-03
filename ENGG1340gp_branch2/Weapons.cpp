/*
Write a programme to display several weapons
like "storm hammer", "Excaliber", "Tomahawk","Energy Vessel"
for example
the "storm hammer" costs 1000, with values of 10 assigning to Player Normal Attack 
the "Excaliber" costs 500, with values of 5 assigning to Player Normal Attack
The "Tomahawk" costs 300, with values of 3 assigning to Player Normal Attack
The "Tomahawk" costs 500, with values of 10 assigning to Player Energy
Same with the previous Weapons.cpp
you need to displaythemenu(prices) for each weapon
getweaponprice() and
buyweapon() is similar withbuyattributeupgrade but for each weapon, the player can only buy it once
*/

#include "Weapons.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

typedef struct Weapon {
    string name;
    int price;
    string attribute;
    int value;
} Weapon;

vector<Weapon> weapons = {
    {"Storm Hammer", 1000, "Player Normal Attack", 10},
    {"Excaliber", 500, "Player Normal Attack", 5},
    {"Tomahawk", 300, "Player Normal Attack", 3},
    {"Energy Vessel", 500, "Player Energy", 10}
};

void displayWeaponMenu(int current_money) {
    cout << "Weapons menu:\n";
    for (int i = 0; i < weapons.size(); ++i) {
        cout << (i + 1) << ". " << weapons[i].name << " (Price: " << weapons[i].price << ")\n";
    }
    cout << weapons.size() + 1 << ". Exit\n";
    cout << "Current money: " << current_money << endl;
    cout << "Enter your weapon choice: ";
}

int getWeaponPrice(int weapon_choice) {
    if (weapon_choice > 0 && weapon_choice <= weapons.size()) {
        return weapons[weapon_choice - 1].price;
    }
    return -1;
}

void applyWeaponEffect(Player* player, int weapon_choice) {
    string attribute = weapons[weapon_choice - 1].attribute;
    int value = weapons[weapon_choice - 1].value;

    if (attribute == "Player Normal Attack") {
        player->player_normal_attack += value;
    } else if (attribute == "Player Energy") {
        player->player_energy += value;
    }
}

void buyWeapon(Player* player) {
    int weapon_choice;

    while (true) {
        int current_money = getCargoQuantity(player, "money");
        displayWeaponMenu(current_money);
        cin >> weapon_choice;

        if (weapon_choice == weapons.size() + 1) {
            break;
        }

        int price = getWeaponPrice(weapon_choice);
        if (price == -1) {
            cout << "Invalid weapon choice. Please try again.\n";
            continue;
        }

        if (current_money >= price) {
            // Apply weapon effect
            applyWeaponEffect(player, weapon_choice);

            // Deduct money from the player's cargo
            removeCargo(player, "money", price);
            cout << "Weapon purchased successfully!\n";

            // Remove purchased weapon from the vector
            weapons.erase(weapons.begin() + weapon_choice - 1);
        } else {
            cout << "Not enough money to buy the weapon.\n";
        }
    }
}

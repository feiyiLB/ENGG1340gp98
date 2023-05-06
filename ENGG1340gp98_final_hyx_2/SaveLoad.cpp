#include "Game.h"
#include "CargoItem.h"
#include "Player.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void saveGame(const Game* game, const string& filename) {
    ofstream outfile(filename, ios::binary);

    if (!outfile.is_open()) {
        cout << "Failed to open the file for saving.\n";
        return;
    }

    // Save player's cargo
    CargoItem* current = game->player.head;
    while (current != nullptr) {
        outfile.write(current->good, sizeof(current->good));
        outfile.write(reinterpret_cast<const char*>(&current->quantity), sizeof(current->quantity));
        current = current->next;
    }

    // Save current planet
    outfile.write(game->current_planet->name.c_str(), game->current_planet->name.length() + 1);
    
    // Save market prices for each planet
    for (int i = 0; i < game->galaxy.num_planets; ++i) {
        for (int j = 0; j < 4; ++j) {
            outfile.write(reinterpret_cast<const char*>(&game->galaxy.planets[i].marketPrices[j]), sizeof(game->galaxy.planets[i].marketPrices[j]));
        }
    }

    outfile.close();
    cout << "Game saved successfully.\n";
}

void loadGame(Game* game, const string& filename) {
    ifstream infile(filename, ios::binary);

    if (!infile.is_open()) {
        cout << "Failed to open the file for loading.\n";
        return;
    }

    // Load player's cargo
    freePlayer(&game->player);
    initPlayer(&game->player);
    while (infile.peek() != ifstream::traits_type::eof()) {
        CargoItem* new_item = new CargoItem;
        infile.read(new_item->good, sizeof(new_item->good));
        infile.read(reinterpret_cast<char*>(&new_item->quantity), sizeof(new_item->quantity));
        new_item->next = nullptr;

        if (game->player.head == nullptr) {
            game->player.head = new_item;
        } else {
            CargoItem* current = game->player.head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_item;
        }
    }

    // Load current planet
    string planet_name;
    getline(infile, planet_name);
    for (int i = 0; i < game->galaxy.num_planets; ++i) {
        if (game->galaxy.planets[i].name == planet_name) {
            game->current_planet = &game->galaxy.planets[i];
            break;
        }
    }

    // Load market prices for each planet
    for (int i = 0; i < game->galaxy.num_planets; ++i) {
        for (int j = 0; j < 4; ++j) {
            infile.read(reinterpret_cast<char*>(&game->galaxy.planets[i].marketPrices[j]), sizeof(game->galaxy.planets[i].marketPrices[j]));
        }
    }

    infile.close();
    cout << "Game loaded successfully.\n";
}

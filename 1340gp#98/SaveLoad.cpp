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

    const Player* player_ptr = &game->player;
    int hp = getPlayerHP(player_ptr);
    int energy = getPlayerEnergy(player_ptr);
    int normal_attack = getPlayerNormalAttack(player_ptr);
    int defense = getPlayerDefense(player_ptr);

    // Save player attributes
    outfile.write(reinterpret_cast<const char*>(&hp), sizeof(hp));
    outfile.write(reinterpret_cast<const char*>(&energy), sizeof(energy));
    outfile.write(reinterpret_cast<const char*>(&normal_attack), sizeof(normal_attack));
    outfile.write(reinterpret_cast<const char*>(&defense), sizeof(defense));

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
    //cout<<"Energy:" <<getPlayerEnergy(player_ptr)<< "Game saved successfully.\n";
}

void loadGame(Game* game, const string& filename) {
    ifstream infile(filename, ios::binary);

    if (!infile.is_open()) {
        cout << "Failed to open the file for loading.\n";
        return;
    }
    int hp, energy, normal_attack, defense;
    infile.read(reinterpret_cast<char*>(&hp), sizeof(hp));
    infile.read(reinterpret_cast<char*>(&energy), sizeof(energy));
    infile.read(reinterpret_cast<char*>(&normal_attack), sizeof(normal_attack));
    infile.read(reinterpret_cast<char*>(&defense), sizeof(defense));

    setPlayerHP(&game->player, hp);
    setPlayerEnergy(&game->player, energy);
    setPlayerNormalAttack(&game->player, normal_attack);
    setPlayerDefense(&game->player, defense);
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
    //cout<<"Energy:" << energy<< "Game saved successfully.\n";
}

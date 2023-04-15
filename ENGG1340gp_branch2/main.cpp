#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include "Player.h"
#include "Galaxy.h"
#include "Event.h"

using namespace std;

void generateAndExecuteEvent(Player* player) {
    int event_type = rand() % 2;

    if (event_type == 0) {
        PirateEvent pirate_event;
        execute_pirate_event(player, &pirate_event);
    } else {
        cout << "No event occurred.\n";
    }
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Display cargo\n";
    cout << "2. Travel to another planet (may trigger an event)\n";
    cout << "3. Exit game\n";
    cout << "Enter your choice: ";
}

void displayCargo(Player* player) {
    cout << "Current cargo:\n";
    cout << "Food: " << getCargoQuantity(player, "food") << "\n";
    cout << "Water: " << getCargoQuantity(player, "water") << "\n";
    cout << "Fuel: " << getCargoQuantity(player, "fuel") << "\n";
    cout << "Metals: " << getCargoQuantity(player, "metals") << "\n";
    cout << "Money: " << getCargoQuantity(player, "money") << "\n";
}

int main() {
    srand(time(0));
    Player player;
    initPlayer(&player);
    addCargo(&player, "food", 20);
    Galaxy galaxy;
    initGalaxy(&galaxy, 5);
    int choice;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                displayCargo(&player);
                break;
            case 2:
                generateAndExecuteEvent(&player);
                break;
            case 3:
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
        // Clear the input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return 0;
}


/*
1. display cargoItem
2. Travel to another planet
3. exit

Initial planet=Earth
1. displaycargoItem
2. "Mars", 
3. "Venus", 
4. "Jupiter", 
5. "Saturn",
6. "Uranus", 
7. "Neptune"
8. Exit

Travel between planets--> trigger events randomly
After arriving a planet
max[0,Food, Water, Fuel-=distance]
Mars exmple:
    display the market price:   Food
                                Metal
                                Fuel
                                water
    1. sell
        Food
        Metal
        Fuel
        water
    2. sold
        Food
        Metal
        Fuel
        water
    
    
*/
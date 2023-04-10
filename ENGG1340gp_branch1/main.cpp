#include "Player.h"
#include "Galaxy.h"
#include "Event.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

void generateAndExecuteEvent(Player& player) {
    int event_type = rand() % 2;

    if (event_type == 0) {
        PirateEvent pirate_event;
        pirate_event.execute(player);
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

void displayCargo(Player& player) {
    cout << "Current cargo:\n";
    cout << "Food: " << player.getCargoQuantity("food") << "\n";
    cout << "Water: " << player.getCargoQuantity("water") << "\n";
    cout << "Fuel: " << player.getCargoQuantity("fuel") << "\n";
    cout << "Metals: " << player.getCargoQuantity("metals") << "\n";
}

int main() {
    srand(time(0));

    Player player;
    player.addCargo("food", 20);

    Galaxy galaxy(5);

    int choice;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                displayCargo(player);
                break;
            case 2:
                generateAndExecuteEvent(player);
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


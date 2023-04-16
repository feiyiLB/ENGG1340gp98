#include "Game.h"
#include "Galaxy.h"
#include "Planet.h"
#include "Player.h"
#include "CargoItem.h"
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

void displayPlanetNamesAndDistances(Planet* planets, int num_planets, Planet* current_planet) {
    std::cout << "Planet list:\n";
    for (int i = 0; i < num_planets; i++) {
        int distance = abs(planets[i].distance_from_sun - current_planet->distance_from_sun);
        std::cout << (i + 1) << ". " << planets[i].name << " (" << distance << " units away)\n";
    }
}
void displayMarketPrices(Planet* current_planet) {
    const char* goods[] = {"Food", "Water", "Fuel", "Metals"};

    std::cout << "Market prices on " << current_planet->name << ":\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << goods[i] << ": " << current_planet->marketPrices[i] << "\n";
    }
}

void generateAndExecuteEvent(Game* game) {
    int event_type = rand() % 2;

    if (event_type == 0) {
        PirateEvent pirate_event;
        execute_pirate_event(&game->player, &pirate_event);
    } else {
        cout << "No event occurred.\n";
    }
    displayPlanetNamesAndDistances(game->galaxy.planets,7, game->current_planet);
}
void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Display cargo\n";
    cout << "2. Travel to another planet (may trigger an event)\n";
    cout << "3. Exit game\n";
    cout << "Enter your choice: ";
}

void displayCargo(Game* game) {
    cout << "Current cargo:\n";
    cout << "Food: " << getCargoQuantity(&game->player, "food") << "\n";
    cout << "Water: " << getCargoQuantity(&game->player, "water") << "\n";
    cout << "Fuel: " << getCargoQuantity(&game->player, "fuel") << "\n";
    cout << "Metals: " << getCargoQuantity(&game->player, "metals") << "\n";
    cout << "Money: " << getCargoQuantity(&game->player, "money") << "\n";
}

void run(Game* game) {
    srand(time(0));
    initPlayer(&game->player);
    addCargo(&game->player, "food", 20);
    initGalaxy(&game->galaxy, 7);
    game->current_planet = &game->galaxy.planets[0];
    int choice;
    bool running = true;
    while (running) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                displayCargo(game);
                break;
            case 2:
                generateAndExecuteEvent(game);
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
}

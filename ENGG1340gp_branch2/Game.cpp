#include "Game.h"
#include "Galaxy.h"
#include "Planet.h"
#include "Player.h"
#include "CargoItem.h"
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <algorithm>
using namespace std;
void TravelGame(Game *game);
void Deal(Game* game);
void displayMarketPrices(Planet* current_planet);
void generateAndExecuteEvent(Game* game);
void displayPlanetNamesAndDistances(Planet* planets, int num_planets, Planet* current_planet) {
    std::cout << "Planet list:\n";
    const char* goods[] = {"Food", "Water", "Fuel", "Metals"};
    for (int i = 0; i < num_planets; i++) {
        int distance = abs(planets[i].distance_from_sun - current_planet->distance_from_sun);
        cout << (i + 1) << ". " << planets[i].name << " (" << distance << " units away)\n";
        for (int j = 0; j < 4; ++j) {
        cout << goods[j] << ": " << planets[i].marketPrices[j] << "HKD\n";
        }       
        cout<<"-------------------------------------------------------------------------"<<endl;
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
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout << "Current cargo:\n";
    cout << "Food: " << getCargoQuantity(&game->player, "food") << "\n";
    cout << "Water: " << getCargoQuantity(&game->player, "water") << "\n";
    cout << "Fuel: " << getCargoQuantity(&game->player, "fuel") << "\n";
    cout << "Metals: " << getCargoQuantity(&game->player, "metals") << "\n";
    cout << "Money: " << getCargoQuantity(&game->player, "money") << "\n";
    cout<<"-------------------------------------------------------------------------"<<endl;
}

void run(Game* game) {
    srand(time(0));
    initPlayer(&game->player);
    //if file cannot be opened
    addCargo(&game->player, "food", 20);
    addCargo(&game->player, "water", 20);
    addCargo(&game->player, "money", 1000);
    // if file can be opened
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
                displayPlanetNamesAndDistances(game->galaxy.planets,7, game->current_planet);
                TravelGame(game);
                break;
            case 3:
                running = false;
                //写入文件
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


void TravelGame(Game *game){
    int choice;
    bool running = true;
    while (running) {
        cout<<"Please input which planet you want to travel to [1-7]"<<endl;
        cout<<"8. display Item"<<endl;
        cout<<"9. exit"<<endl;
        cin >> choice;
        if(choice>0 && choice<8){
            game->current_planet=&game->galaxy.planets[choice-1];
            cout << "You have arrived at " << game->current_planet->name << endl;
            generateAndExecuteEvent(game);
            displayMarketPrices(game->current_planet);
            Deal(game);
        }else if(choice==8){
            displayCargo(game);
        }else if(choice==9){
            running=false;
        }else{
            cout<<"Invalid input"<<endl;  
        }

}
}
void Deal(Game* game) {
    int choice;
    const char* goods[] = {"food", "water", "fuel", "metals"};
    bool running = true;

    while (running) {
        cout << "Deal options:\n";
        cout << "1. Sell\n";
        cout << "2. Buy\n";
        cout << "3. Display cargo\n";
        if (game->current_planet->name== "Earth") {
            cout << "4. Gamble the horse\n";
        }
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int good_choice;
            int quantity;

            cout << "Choose the good:\n";
            for (int i = 0; i < 4; ++i) {
                cout << (i + 1) << ". " << goods[i] << endl;
            }
            cout << "Enter your choice: ";
            cin >> good_choice;

            if (good_choice > 0 && good_choice <= 4) {
                cout << "Enter quantity: ";
                cin >> quantity;
                int price = game->current_planet->marketPrices[good_choice - 1];
                if (choice == 1) { // Selling
                    // Check if the player has enough items in their cargo to sell
                    int current_item_quantity = getCargoQuantity(&game->player, goods[good_choice - 1]);
                    if (current_item_quantity >= quantity) {
                        // Update cargo: remove the items from the player's inventory
                        removeCargo(&game->player, goods[good_choice - 1], quantity);

                        // Add money to the player's cargo
                        addCargo(&game->player, "money", quantity * price);
                    } else {
                        cout << "Not enough items in the cargo to sell.\n";
                    }
                } else if (choice == 2) { // Buying
                    // Check if the player has enough money
                    int current_money = getCargoQuantity(&game->player, "money");
                    if (current_money >= (quantity * price)) {
                        // Update cargo: add the items to the player's inventory
                        addCargo(&game->player, goods[good_choice - 1], quantity);

                        // Remove money from the player's cargo
                        removeCargo(&game->player, "money", quantity * price);
                    } else {
                        cout << "Not enough money to buy the items.\n";
                    }
                }
            } else {
                cout << "Invalid good choice. Please try again.\n";
            }
        } else if (choice == 3) {
            displayCargo(game);
        } else if (choice == 4 && game->current_planet->name== "Earth") {
            cout<<"Horse"<<endl;
        } else if (choice == 5) {
            running = false;
        } else {
            cout << "Invalid deal choice. Please try again.\n";
        }
    }
}



//Why when I sell the a specific item, it only call removeCargo
//It should also add the money to the cargo
//same for the buy
//money should be removed from cargo when I buy it 
//买卖完成后直接display
//钱的数量的目标，赚到10万就赢
//清0为输
//持续的买卖
//文件输入输出-->
//地球商店
//把钱转换成技能点或者运气值-->来加强
/*
没打过boss
无数次挑战(失败后治疗可以付出代价)
打斗事件
海盗事件
赚钱突发事件

Player的进攻点数
防御点数
血量
技能条
物资
File:
存档
HYX：
player
Boss
LB:
Game

YZL：
Random Event
存档

YAB&Granger:
Planet&21点



*/
//赚钱变成武器打败大Boss



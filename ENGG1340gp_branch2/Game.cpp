#include "Game.h"
#include "Galaxy.h"
#include "Planet.h"
#include "Player.h"
#include "CargoItem.h"
#include "SaveLoad.h" // Include the SaveLoad header
#include <ctime>
#include <cstdlib>
#include <limits>
#include <cstring>
#include <algorithm>
#include "boss.h"
#include "Weapons.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <unistd.h> // For sleep function
#include <Windows.h>
#include "BlackJack.h"
using namespace std;
void TravelGame(Game *game);
void basicinfo();
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
        Sleep(500);
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
    
    int event_type = rand() % 5;
    if (event_type == 0) {
        PirateEvent pirate_event;
        execute_pirate_event(&game->player, &pirate_event);
    } else {
        cout << "No event occurred.\n";
    }
    //displayPlanetNamesAndDistances(game->galaxy.planets,7, game->current_planet);
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Display cargo\n";
    cout << "2. Travel to another planet (may trigger an event)\n";
    cout << "3. Save game\n";
    cout << "4. Load game\n";
    cout << "5. Exit game\n";
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
    if(getCargoQuantity(&game->player, "money")>=0){
        displayPlayerAttributes(&game->player);
    }
}

void run(Game* game) {
    basicinfo();
    srand(time(0));
    initPlayer(&game->player);
    //if file cannot be opened
    addCargo(&game->player, "food", 10);
    addCargo(&game->player, "water", 10);
    addCargo(&game->player, "fuel", 20);
    addCargo(&game->player, "metal", 10);
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
            case 3: // Save game
                {
                    string filename;
                    cout << "Enter a file name to save your game: ";
                    cin >> filename;
                    saveGame(game, filename);
                }
                break;
            case 4: // Load game
                {
                    string filename;
                    cout << "Enter a file name to load a saved game: ";
                    cin >> filename;
                    loadGame(game, filename);
                }
                break;
            case 5:
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


void TravelGame(Game *game){
    int choice;
    bool running = true;
    while (running) {
        cout<<"Please input which planet you want to travel to [1-7]"<<endl;
        cout<<"8. display Item"<<endl;
        cout<<"9. exit"<<endl;
        cin >> choice;
        if(choice>0 && choice<8){
            Travel(&game->player,game->current_planet, &game->galaxy.planets[choice-1]);
            game->current_planet=&game->galaxy.planets[choice-1];
            cout << "You have arrived at " << game->current_planet->name << endl;
            displayMarketPrices(game->current_planet);
            generateAndExecuteEvent(game);
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

        if (game->current_planet->name == "Earth") {
            cout << "4. Challenge the boss\n";
            cout << "5. Exit\n";
        } else if (game->current_planet->name == "Mars") {
            cout << "4. Arm yourself\n";
            cout << "5. Exit\n";
        }else if(game->current_planet->name == "Jupiter"){
            cout << "4. Play BlackJack\n";
            cout << "5. Exit\n";
        }else if(game->current_planet->name == "Saturn"){
            cout << "4. Saturn events\n";
            cout << "5. Exit\n";
        }
        else {
            cout << "4. Exit\n";
        }
        cout << "Enter your choice: ";
        cin >> choice;

        if (game->current_planet->name == "Earth" && choice == 4) {
            int result = boss(&game->player); // Call the boss function
            if (result == 1) { // You may want to modify the boss function to return 1 if the player wins
                cout << "You have defeated the boss!" << endl;
                exit(0);
                return;
                //after winning end of the game
            } else {
                cout << "You lost to the boss. Try again." << endl;
                //after lost the boss remove the money 
            }
            continue; // To skip the rest of the loop iteration and move to the next iteration
        } else if (game->current_planet->name == "Mars" && choice == 4) {
            cout << "Arm yourself" << endl;
            // Add code to handle buying weapons here
            buyWeapon(&game->player);
            continue; // To skip the rest of the loop iteration and move to the next iteration
        } else if (game->current_planet->name == "Jupiter" && choice == 4) {
            cout << "Play BlackJack" << endl;
            int m=getCargoQuantity(&game->player, "money");
            int bet=playBlackJack(m);
            addCargo(&game->player,"money",bet);
            continue; // To skip the rest of the loop iteration and move to the next iteration
        }else if (game->current_planet->name == "Saturn" && choice == 4) {
            cout << "Saturn Events" << endl;
            // Add code to handle buying weapons here
            continue; // To skip the rest of the loop iteration and move to the next iteration
        }
        else if (choice == 4) {
            running = false;
            continue; // To skip the rest of the loop iteration and move to the next iteration
        }





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
            cout<<"Challenge the boss"<<endl;
        } else if (choice == 5) {
            running = false;
        } else {
            cout << "Invalid deal choice. Please try again.\n";
        }
    }
}

void basicinfo(){
    
    cout << "Title: Space Trader: A Galactic Adventure\n\n";
    cout << "------------------User Guide---------------\n\n";
    cout << "Welcome to Space Trader: A Galactic Adventure! This guide will help you understand the game mechanics, objectives, and tips to become the ultimate space trader.\n\n";
    cout << "---------Game Overview:---------------\n";
    cout << "In Space Trader: A Galactic Adventure, you assume the role of a trader exploring the vast universe, buying and selling goods to amass a fortune, and ultimately, defeating the boss to become the most successful trader in the galaxy. Travel between planets, encounter random events, and face challenges to achieve your ultimate goal.\n\n";
    cout << "------------Getting Started:------------\n";
    cout << "The game begins with your character being initialized with a starting cargo of food, water, fuel, metals, and money. Your journey starts on Earth, and from there, you will travel to other planets in the galaxy to trade goods and make a profit.\n\n";
    cout << "Controls and Navigation:\n";
    cout << "The game is menu-driven, and you will make your selections by entering the corresponding number for each menu option. The main menu provides the following options:\n\n";
    cout << "1. Display cargo - View your current inventory of goods and money.\n";
    cout << "2. Travel to another planet - Choose a planet to travel to, potentially triggering events.\n";
    cout << "3. Save game - Save your progress to a file.\n";
    cout << "4. Load game - Load a saved game from a file.\n";
    cout << "5. Exit game - End the game.\n\n";
    cout << "-------------rading:---------------\n";
    cout << "When you arrive at a new planet, you can trade goods (food, water, fuel, and metals) with the local market. Each planet has its own market prices for goods, so it's essential to buy low and sell high to make a profit. The trading menu provides the following options:\n\n";
    cout << "1. Sell - Sell goods from your cargo.\n";
    cout << "2. Buy - Buy goods to add to your cargo.\n";
    cout << "3. Display cargo - View your current inventory.\n";
    cout << "4. Planet-specific options - Participate in planet-specific events or challenges (e.g., Challenge the boss on Earth, Arm yourself on Mars, Play Blackjack on Jupiter, or Saturn events).\n";
    cout << "5. Exit - Return to the main menu.\n\n";
    cout << "Events and Challenges:\n";
    cout << "During your travels, you may encounter random events, such as pirate attacks or other surprises. Each planet also offers unique challenges and events that can help you progress in the game. For example, you can buy weapons on Mars, play Blackjack on Jupiter, or challenge the boss on Earth.\n\n";
    cout << "Defeating the Boss:\n";
    cout << "The ultimate goal is to defeat the boss on Earth. To increase your chances of success, amass a fortune, trade goods, participate in planet-specific events, and arm yourself with powerful weapons.\n\n";
    cout << "Tips for Success:\n\n";
    cout << "1. You can arm your self in Mars\n";
    cout << "2. You can beat the boss in the Earth\n";
    cout << "3. You can play BalckJack in Jupiter\n";
    cout << "4. You can do something else in Saturn";
    cout << "\n";
    cout << "\n";
    cout << "\n";
    cout << "      /^\\  " << endl;
    cout << "     /   \\ " << endl;
    cout << "    /  O  \\ " << endl;
    cout << "   /_____\\  "<< endl;
    cout << "      |||  " << endl;
    cout << "      |||  " << endl;

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



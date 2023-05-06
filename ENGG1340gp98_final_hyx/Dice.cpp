#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Dice(int money) {
    cout << "Welcome to the dice game!" << endl;
    cout << "The game has two rounds:  big or samll, and the guess the total number." << endl;
    cout << "In the big or samll round, you need to guess whether the total of three dice is \"big\" (11-17) or \"small\" (4-10)." << endl;
    cout << "If you guess correctly, you win your bet amount. Otherwise, you lose your bet amount." << endl;
    cout << "In the guessing total number round, you need to guess the exact total of three dice." << endl;
    cout << "If you guess correctly, you win 10 times your bet amount. Otherwise, you lose your bet amount." << endl;
    cout << "You can choose to quit the game at any time by entering 0 as your bet amount." << endl;
    srand(time(NULL));
    int totalMoney = money;
    bool playAgain = true;

    while (playAgain && totalMoney > 0) {
        cout << "You have $" << totalMoney << "Left."<<endl;
        cout <<  "How much do you want to bet? (Enter 0 to quit) "<<endl;
        int bet;
        cin >> bet;
        if (bet == 0) {
            playAgain = false;
            break;
        }
        while (bet > totalMoney) {
            cout << "You don't have enough money. Enter a bet less than or equal to $" << totalMoney << ": ";
            cin >> bet;
            if (bet == 0) {
                playAgain = false;
                break;
            }
        }
        if (!playAgain) {
            break;
        }
        bool freshmanTest = true;
        if (totalMoney > 0) {
            cout << "Guess \"big\" or \"small\" based on the total of three dice (4-10 for small, 11-17 for big): ";
            string guess;
            cin >> guess;
            for (int i = 0; i < guess.size(); i++)
            {
                guess[i] = tolower(guess[i]);
            }
            while (guess != "big" && guess != "small") {
                cout << "Invalid input. Please enter \"big\" or \"small\": ";
                cin >> guess;
            }
            int total = 0;
            for (int i = 0; i < 3; i++) {
                int dice = rand() % 6 + 1;
                total += dice;
            }
            cout << "The dice is " << total << "." << endl;

            if ((total >= 4 && total <= 10 && guess == "small") || (total >= 11 && total <= 17 && guess == "big")) {
                cout << "You win $" << bet << "!" << endl;
                totalMoney += bet;
            } 
            else if ((total >= 4 && total <= 10 && guess == "big") || (total >= 11 && total <= 17 && guess == "small")){
                cout << "You lose $" << bet << "!" << endl;
                totalMoney -= bet;
            }
            freshmanTest = false;
        }
        if (totalMoney > 0) {
            cout << "Guess the total number of three dice (3 to 18): ";
            int guess;
            cin >> guess;
            while (guess < 3 || guess > 18) {
                cout << "Invalid input. Please enter a number between 3 and 18: ";
                cin >> guess;
            }
            int total = 0;
            for (int i = 0; i < 3; i++) {
                int dice = rand() % 6 + 1;
                total += dice;
            }
            cout << "The total is " << total << "." << endl;
            if (total == guess) {
                cout << "You win $" << bet * 10 << "!" << endl;
                totalMoney += bet * 10;
            } else {
                cout << "You lose $" << bet << "!" << endl;
                totalMoney -= bet;
            }
        }
    }
    if (totalMoney == 0) {
        cout << "You have run out of money. Game over." << endl;
        return 0;
    } else {
        cout << "You have chosen to quit. You leave with $" << totalMoney << "." << endl;
        return totalMoney;
    }
}
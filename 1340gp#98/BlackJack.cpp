#include "BlackJack.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int getRandomCard() {
    return rand() % 10 + 1;
}

int calculateHandValue(const vector<int>& hand) {
    int value = 0;
    int num_aces = 0;
    for (int card : hand) {
        value += card;
        if (card == 1) {
            num_aces++;
        }
    }

    while (value <= 11 && num_aces > 0) {
        value += 10;
        num_aces--;
    }

    return value;
}

int playBlackJack(int player_money) {
    srand(time(0));

    int bet;
    cout << "You have " << player_money << " money. How much would you like to bet? ";
    cin >> bet;

    if (bet <= 0 || bet > player_money) {
        cout << "Invalid bet. Returning to the main menu." << endl;
        return 0;
    }

    vector<int> player_hand = {getRandomCard(), getRandomCard()};
    vector<int> dealer_hand = {getRandomCard(), getRandomCard()};

    cout << "Your hand: " << player_hand[0] << ", " << player_hand[1] << endl;
    cout << "Dealer's up card: " << dealer_hand[0] << endl;

    bool player_turn = true;
    bool dealer_turn = false;

    while (player_turn) {
        cout << "1. Hit\n";
        cout << "2. Stand\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int new_card = getRandomCard();
            player_hand.push_back(new_card);
            cout << "You got a " << new_card << endl;

            if (calculateHandValue(player_hand) > 21) {
                cout << "You busted! You lost " << bet << " money." << endl;
                return -bet;
            }
        } else if (choice == 2) {
            player_turn = false;
            dealer_turn = true;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    while (dealer_turn) {
        if (calculateHandValue(dealer_hand) < 17) {
            int new_card = getRandomCard();
            dealer_hand.push_back(new_card);
            cout << "Dealer got a " << new_card << endl;

            if (calculateHandValue(dealer_hand) > 21) {
                cout << "Dealer busted! You won " << bet << " money." << endl;
                return bet;
            }
        } else {
            dealer_turn = false;
        }
    }

    int player_value = calculateHandValue(player_hand);
    int dealer_value = calculateHandValue(dealer_hand);

    if (player_value > dealer_value) {
        cout << "You won! You gained " << bet << " money." << endl;
        return bet;
    } else if (player_value < dealer_value) {
        cout << "You lost! You lost " << bet << " money." << endl;
        return -bet;
    } else {
        cout << "It's a tie! No money gained or lost." << endl;
        return 0;
    }
}

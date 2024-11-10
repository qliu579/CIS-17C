#include "Gameplay.h"
#include <iostream>
#include <ctime>

using namespace std;

void Gameplay::play() {
    char playAga;
    do {
        Player user;
        Player dealer;
        Deck deckObj;

        stack<Card> deck = deckObj.crtDeck();

        map<string, int> cardValues = { {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7},
                                        {"8", 8}, {"9", 9}, {"10", 10}, {"Jack", 10}, {"Queen", 10},
                                        {"King", 10}, {"Ace", 11} };

        if (!deck.empty()) {
            Card dltCard = deck.top();
            deck.pop();
            user.hand.push_back(dltCard);
        }

        if (!deck.empty()) {
            Card dltCard = deck.top();
            deck.pop();
            dealer.hand.push_back(dltCard);
        }

        if (!deck.empty()) {
            Card dealtCard = deck.top();
            deck.pop();
            user.hand.push_back(dealtCard);
        }

        if (!deck.empty()) {
            Card dealtCard = deck.top();
            deck.pop();
            dealer.hand.push_back(dealtCard);
        }

        cout << "Your hand:" << endl << fixed;
        user.shwHand();
        cout << endl;

        cout << "Dealer's hand:" << endl << fixed;
        dealer.shwHand(true);
        cout << endl;

        char choice;
        bool userBst = false;
        do {
            cout << "Do you want to Hit or Stand? (h/s): " << endl;
            cin >> choice;
            if (choice == 'h' || choice == 'H') {
                if (!deck.empty()) {
                    Card dealtCard = deck.top();
                    deck.pop();
                    user.hand.push_back(dealtCard);
                    cout << "You drew: " << dealtCard << endl;
                    cout << "Your current hand:" << endl << fixed;
                    user.shwHand();
                    cout << endl;
                    int userTot = user.calHVal(cardValues);
                    if (userTot > 21) {
                        cout << "You bust with " << userTot << " points." << endl;
                        userBst = true;
                        break;
                    }
                }
            }
        } while ((choice == 'h' || choice == 'H') && user.hand.size() < 5);

        if (!userBst) {
            cout << "Dealer reveals their hand: " << fixed;
            dealer.shwHand(false);
            cout << endl;

            int dealTot = dealer.calHVal(cardValues);
            while (dealTot < 17) {
                if (!deck.empty()) {
                    Card dealtCard = deck.top();
                    deck.pop();
                    dealer.hand.push_back(dealtCard);
                    dealTot = dealer.calHVal(cardValues);
                }
            }

            cout << "Dealer's final hand: " << fixed;
            dealer.shwHand();
            cout << "Dealer's total: " << dealTot << endl;

            int userTot = user.calHVal(cardValues);
            if (dealTot > 21) {
                cout << "Dealer busts! You win!" << endl;
            } else if (userTot > dealTot) {
                cout << "You win with " << userTot << " points!" << endl;
            } else if (userTot < dealTot) {
                cout << "Dealer wins with " << dealTot << " points." << endl;
            } else {
                cout << "It's a tie!" << endl;
            }
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAga;

    } while (playAga == 'y' || playAga == 'Y');
}

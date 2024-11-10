#include "Player.h"
#include <iostream>
#include <iomanip>

using namespace std;

void Player::shwHand(bool hideFirstCard, int hiddenCardCount) {
    bool firstCard = true;
    for (auto& card : hand) {
        if (hideFirstCard && firstCard) {
            cout << setw(10) << "Hidden Card" << " ";
            firstCard = false;
        } else {
            cout << setw(10) << card << " ";
        }
    }
    for (int i = 0; i < hiddenCardCount; ++i) {
        cout << setw(10) << "Hidden Card" << " ";
    }
    cout << endl;
}

int Player::calHVal(const map<string, int>& cardVal) {
    int totVal = 0;
    int aCount = countAces();
    for (const auto& card : hand) {
        totVal += cardVal.at(card.value);
    }
    while (totVal > 21 && aCount > 0) {
        totVal -= 10;
        aCount--;
    }
    return totVal;
}

int Player::countAces() const {
    int aCount = 0;
    for (const auto& card : hand) {
        if (card.value == "Ace") {
            aCount++;
        }
    }
    return aCount;
}

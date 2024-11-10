#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

using namespace std;

class Card {
public:
    string suit;
    string value;
    friend ostream& operator<<(ostream& os, const Card& card);
};

#endif // CARD_H

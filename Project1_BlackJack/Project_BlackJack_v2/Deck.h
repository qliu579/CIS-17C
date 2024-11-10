#ifndef DECK_H
#define DECK_H

#include <stack>
#include <list>
#include <set>    // Include the set header
#include "Card.h"

using namespace std;

class Deck {
public:
    stack<Card> crtDeck();
    set<string> dealtCards;  // Set to keep track of dealt cards
};

#endif // DECK_H

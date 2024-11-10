#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include <map>
#include "Card.h"

using namespace std;

class Player {
public:
    list<Card> hand;
    void shwHand(bool hideFirstCard = false, int hiddenCardCount = 0);
    int calHVal(const map<string, int>& cardVal);
    int countAces() const;
};

#endif // PLAYER_H

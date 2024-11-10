#include "Card.h"

using namespace std;

ostream& operator<<(ostream& os, const Card& card) {
    string suitAbb;
    if (card.suit == "Hearts") suitAbb = "H";
    else if (card.suit == "Diamonds") suitAbb = "D";
    else if (card.suit == "Clubs") suitAbb = "C";
    else if (card.suit == "Spades") suitAbb = "S";
    
    os << (card.value == "Jack" ? "J" : card.value == "Queen" ? "Q" : card.value == "King" ? "K" : card.value == "Ace" ? "A" : card.value) << suitAbb;
    return os;
}

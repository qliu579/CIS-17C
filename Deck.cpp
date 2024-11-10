#include "Deck.h"
#include <random>

using namespace std;

stack<Card> Deck::crtDeck() {
    list<string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    list<string> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    list<Card> deckLst;

    for (auto& suit : suits) {
        for (auto& value : values) {
            Card newCard = {suit, value};
            if (dealtCards.find(suit + value) == dealtCards.end()) {  // Check if card has been dealt before
                deckLst.push_back(newCard);
            }
        }
    }

    random_device rd;
    mt19937 g(rd());
    deckLst.sort([&g](const Card& a, const Card& b) { return g() % 2 == 0; });

    stack<Card> deck;
    for (auto& card : deckLst) {
        deck.push(card);
    }

    return deck;
}

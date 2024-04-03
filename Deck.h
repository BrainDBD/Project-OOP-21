#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck(const std::vector<Card> &cards_ = {});
    Deck(const Deck &other);
    void addToDeck(Card card_);
    void createDeck(Deck &deck);
    void emptyDeck();
    void shuffleDeck();
    Card dealCard();
    Card lastCard();
    friend std::ostream &operator<<(std::ostream &os, const Deck &deck);
    Deck &operator=(const Deck &other);
    ~Deck() = default;
};
#endif  //DECK_H
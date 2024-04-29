#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck(const std::vector<Card> &cards_ = {});
    Deck(const Deck &other);
    void createDeck();
    void shuffleDeck();
    void emptyDeck();
    void addToDeck(Card card_);
    void removefromDeck(Card card_);
    int DeckSize();
    Card dealCard();
    Card drawCard(Card card_);
    Card lastCard();
    void removeLastCard();
    void exchange(Deck &other);
    friend std::ostream &operator<<(std::ostream &os, const Deck &deck);
    Deck &operator=(const Deck &other);
    ~Deck() = default;
};
#endif  //DECK_H
#ifndef TRUMPDECK_H
#define TRUMPDECK_H

#include <vector>
#include "TrumpCard.h"

class TrumpDeck
{
private:
    std::vector<TrumpCard> tcards;

public:
    TrumpDeck() = default;
    TrumpDeck(const std::vector<TrumpCard> &tcards_);
    TrumpDeck(const TrumpDeck &other);
    void addToTrumpDeck(TrumpCard tcard_);
    void removefromTrumpDeck(TrumpCard tcard_);
    void createTrumpDeck();
    void emptyTrumpDeck();
    void shuffleTrumpDeck();
    int showTrumpSize();
    bool checkEmpty();
    TrumpCard dealTrumpCard();
    TrumpCard drawTrumpCard(TrumpCard tcard_);
    TrumpCard lastTrumpCard();
    void removeLastTrumpCard();
    TrumpDeck &operator=(const TrumpDeck &other);
    friend std::ostream &operator<<(std::ostream &os, const TrumpDeck &tdeck);
    ~TrumpDeck() = default;
};

#endif  // TRUMPCARD_H

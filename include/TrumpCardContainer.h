#ifndef TCC_H
#define TCC_H

#include "BasicCardContainer.h"
#include "TrumpCard.h"

class TrumpCardContainer : public BasicCardContainer
{
protected:
    TrumpCardContainer(const std::vector<AnyCard*> &cards_ = {});

public:
    int DeckSize();
    void emptyDeck();
    void removefromDeck(TrumpCard &card_);
    void removeLastCard();
    friend std::ostream &operator<<(std::ostream &os, const TrumpCardContainer &deck);
    void Afisare(std::ostream &os);
    virtual ~TrumpCardContainer();
};

#endif  //TCC_H
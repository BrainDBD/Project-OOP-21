#ifndef NCC_H
#define NCC_H

#include "BasicCardContainer.h"
#include "NumCard.h"

class NumCardContainer : public BasicCardContainer
{
protected:
    NumCardContainer(const std::vector<AnyCard*> &cards_ = {});
public:
    int DeckSize();
    void emptyDeck();
    void removefromDeck(NumCard &card_);
    void removeLastCard();
    friend std::ostream &operator<<(std::ostream &os, const NumCardContainer &deck);
    virtual ~NumCardContainer();
};

#endif  //NCC_H
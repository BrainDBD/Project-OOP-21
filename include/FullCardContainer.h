#ifndef FCC_H
#define FCC_H

#include "BasicCardContainer.h"
#include "FullCard.h"

class FullCardContainer : public BasicCardContainer
{
protected:
    FullCardContainer(const std::vector<AnyCard*> &cards_ = {});
public:
    int DeckSize();
    void emptyDeck();
    void removefromDeck(FullCard card_);
    void removeLastCard();
    friend std::ostream &operator<<(std::ostream &os, const FullCardContainer &deck);
    virtual ~FullCardContainer();
};

#endif  //FCC_H
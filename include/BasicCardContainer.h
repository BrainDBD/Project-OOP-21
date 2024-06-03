#ifndef BCC_H
#define BCC_H

#include <vector>
#include <algorithm>
#include <random>
#include "AnyCard.h"

class BasicCardContainer
{
protected:
    std::vector<AnyCard*> cards;
public:
    BasicCardContainer(const std::vector<AnyCard*> &cards_ = {});
    virtual int DeckSize() = 0;
    bool checkEmpty();
    virtual void emptyDeck() = 0;
    virtual void removeLastCard() = 0;
    virtual void Afisare(std::ostream &os) = 0;
};

#endif  //BCC_H
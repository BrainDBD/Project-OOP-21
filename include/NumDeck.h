#ifndef NDECK_H
#define NDECK_H

#include "NumCardContainer.h"

class NumDeck : public NumCardContainer
{
public:
    NumDeck(const std::vector<AnyCard*> &cards_ = {});
    NumDeck(const NumDeck &other);
    void createDeck();
    void shuffleDeck();
    NumCard dealCard();
    NumCard drawCard(NumCard card_);
    NumDeck &operator=(const NumDeck &other);
    void Afisare(std::ostream &os) override;
    ~NumDeck() override;
};

#endif  //NDECK_H
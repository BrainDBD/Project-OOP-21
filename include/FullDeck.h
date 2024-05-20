#ifndef FDECK_H
#define FDECK_H

#include "FullCardContainer.h"

class FullDeck : public FullCardContainer
{
public:
    FullDeck(const std::vector<AnyCard*> &cards_ = {});
    FullDeck(const FullDeck &other);
    void createDeck();
    void shuffleDeck();
    FullCard dealCard();
    FullCard drawCard(FullCard card_);
    FullDeck &operator=(const FullDeck &other);
    void Afisare(std::ostream &os) override;
    ~FullDeck() override;
};

#endif  //FDECK_H
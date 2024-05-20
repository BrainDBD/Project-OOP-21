#ifndef FHAND_H
#define FHAND_H

#include "FullCardContainer.h"

class FullHand : public FullCardContainer
{
public:
    FullHand(const std::vector<AnyCard*> &cards_ = {});
    FullHand(const FullHand &other);
    void addToDeck(const FullCard &card_);
    FullCard lastCard();
    void exchange(FullHand &other);
    int getnAces();
    FullHand &operator=(const FullHand &other);
    void Afisare(std::ostream &os) override;
    ~FullHand() override;
};

#endif  //FHAND_H
#ifndef THAND_H
#define THAND_H

#include "TrumpCardContainer.h"

class TrumpHand : public TrumpCardContainer
{
public:
    TrumpHand(const std::vector<AnyCard*> &cards_ = {});
    TrumpHand(const TrumpHand &other);
    void addToDeck(const TrumpCard &card_);
    TrumpCard lastCard();
    void exchange(TrumpHand &other);
    TrumpHand &operator=(const TrumpHand &other);
    ~TrumpHand() override;
};

#endif  //THAND_H
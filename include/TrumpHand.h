#ifndef THAND_H
#define THAND_H

#include "TrumpCardContainer.h"

class TrumpHand : public TrumpCardContainer
{
public:
    TrumpHand(const std::vector<AnyCard*> &cards_ = {});
    TrumpHand(const TrumpHand &other);
    TrumpHand(TrumpHand&& other) noexcept; 
    void addToDeck(const TrumpCard &card_);
    TrumpCard lastCard();
    void exchange(TrumpHand &other);
    TrumpHand &operator=(const TrumpHand &other);
    TrumpHand &operator=(TrumpHand&& other) noexcept;
    ~TrumpHand() override;
};

#endif  //THAND_H
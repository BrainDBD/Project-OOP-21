#ifndef NHAND_H
#define NHAND_H

#include "NumCardContainer.h"

class NumHand : public NumCardContainer
{
public:
    NumHand(const std::vector<AnyCard*> &cards_ = {});
    NumHand(const NumHand &other);
    NumHand(NumHand&& other) noexcept; 
    void addToDeck(const NumCard &card_);
    NumCard lastCard();
    void exchange(NumHand &other);
    NumHand &operator=(const NumHand &other);
    NumHand &operator=(NumHand&& other) noexcept;
    void Afisare(std::ostream &os) override;
    ~NumHand() override;
};

#endif  //NHAND_H
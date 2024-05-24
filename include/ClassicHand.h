#ifndef FHAND_H
#define FHAND_H

#include "ClassicCardContainer.h"

class ClassicHand : public ClassicCardContainer
{
public:
    ClassicHand(const std::vector<AnyCard*> &cards_ = {});
    ClassicHand(const ClassicHand &other);
    ClassicHand(ClassicHand&& other) noexcept; 
    void addToDeck(const ClassicCard &card_);
    void getDealerHand();
    ClassicCard lastCard();
    void exchange(ClassicHand &other);
    int getnAces();
    ClassicHand &operator=(const ClassicHand &other);
    ClassicHand &operator=(ClassicHand&& other) noexcept;
    void Afisare(std::ostream &os) override;
    ~ClassicHand() override;
};

#endif  //FHAND_H
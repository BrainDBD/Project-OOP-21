#ifndef FDECK_H
#define FDECK_H

#include "ClassicCardContainer.h"

class ClassicDeck : public ClassicCardContainer
{
public:
    ClassicDeck(const std::vector<AnyCard*> &cards_ = {});
    ClassicDeck(const ClassicDeck &other);
    ClassicDeck(ClassicDeck&& other) noexcept; 
    void createDeck();
    void shuffleDeck();
    bool lowCards();
    ClassicCard dealCard();
    ClassicCard drawCard(ClassicCard card_);
    ClassicDeck &operator=(const ClassicDeck &other);
    ClassicDeck &operator=(ClassicDeck&& other) noexcept;
    void Afisare(std::ostream &os) override;
    ~ClassicDeck() override;
};

#endif  //FDECK_H
#ifndef FDECK_H
#define FDECK_H

#include "ClassicCardContainer.h"

class ClassicDeck : public ClassicCardContainer
{
public:
    ClassicDeck(const std::vector<AnyCard*> &cards_ = {});
    ClassicDeck(const ClassicDeck &other);
    void createDeck();
    void shuffleDeck();
    ClassicCard dealCard();
    ClassicCard drawCard(ClassicCard card_);
    ClassicDeck &operator=(const ClassicDeck &other);
    void Afisare(std::ostream &os) override;
    ~ClassicDeck() override;
};

#endif  //FDECK_H
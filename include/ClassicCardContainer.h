#ifndef FCC_H
#define FCC_H

#include "BasicCardContainer.h"
#include "ClassicCard.h"

class ClassicCardContainer : public BasicCardContainer
{
protected:
    ClassicCardContainer(const std::vector<AnyCard*> &cards_ = {});
public:
    int DeckSize();
    void emptyDeck();
    void removefromDeck(ClassicCard card_);
    void removeLastCard();
    friend std::ostream &operator<<(std::ostream &os, const ClassicCardContainer &deck);
    virtual ~ClassicCardContainer();
};

#endif  //FCC_H
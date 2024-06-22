#ifndef TRUMPDECK_H
#define TRUMPDECK_H

#include <vector>
#include "TrumpCardContainer.h"

class TrumpDeck : public TrumpCardContainer
{
public:
    TrumpDeck(const std::vector<AnyCard*> &cards_ = {});
    TrumpDeck(const TrumpDeck &other);
    TrumpDeck(TrumpDeck&& other) noexcept; 
    TrumpDeck* clone() const;
    void removefromDeck(TrumpCard tcard_);
    void createDeck();
    void shuffleDeck();
    bool checkEmpty();
    TrumpCard dealCard();
    TrumpCard drawCard(TrumpCard tcard_);
    TrumpDeck &operator=(const TrumpDeck &other);
    TrumpDeck &operator=(TrumpDeck&& other) noexcept;
    ~TrumpDeck() override;
};

#endif  // TRUMPCARD_H

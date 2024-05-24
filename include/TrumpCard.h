#ifndef TRUMPCARD_H
#define TRUMPCARD_H

#include "AnyCard.h"
#include "./enums/TrumpType.h"

class TrumpCard : public AnyCard
{
private:
    TrumpType type;
public:
    TrumpCard(TrumpType type_ = TrumpType::None);
    TrumpCard &operator=(const TrumpCard &other);
    std::string getType() const override;
    friend std::ostream &operator<<(std::ostream &os, const TrumpCard &tcard);
    ~TrumpCard();
};

#endif  // TRUMPCARD_H

#ifndef TRUMPCARD_H
#define TRUMPCARD_H

#include <iostream>
#include "./enums/TrumpType.h"

class TrumpCard {
private:
    TrumpType type;
public:
    TrumpCard(TrumpType type_ = TrumpType::None);
    TrumpCard &operator=(const TrumpCard &other);
    std::string getString();
    friend std::ostream &operator<<(std::ostream &os, const TrumpCard &tcard);
    ~TrumpCard() = default;
};

#endif  // TRUMPCARD_H

#ifndef NUMCARD_H_
#define NUMCARD_H_

#include "AnyCard.h"
#include "./enums/NumType.h"

class NumCard : public AnyCard
{
private:
    NumType type;
public:
    NumCard(NumType type_ = NumType::None);
    NumCard &operator=(const NumCard &other);
    std::string getType() const override;
    int getValue() const;
    friend std::ostream &operator<<(std::ostream &os, const NumCard &ncard);
    ~NumCard();
};

#endif  // NUMCARD_H
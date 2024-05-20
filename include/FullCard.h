#ifndef FULLCARD_H_
#define FULLCARD_H_
#include "AnyCard.h"
#include "./enums/FullType.h"

class FullCard : public AnyCard
{
private:
    FullType type;
    Suit suit;
public:
    FullCard(FullType type_ = FullType::None, Suit suit_ = Suit::None);
    FullCard &operator=(const FullCard &other);
    std::string getType() const override;
    std::string getSuit() const;
    bool checkAce();
    int getValue() const;
    friend std::ostream &operator<<(std::ostream &os, const FullCard &ncard);
    ~FullCard();
};

#endif  // FULLCARD_H
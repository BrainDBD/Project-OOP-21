#ifndef FULLCARD_H_
#define FULLCARD_H_

#include "AnyCard.h"
#include "./enums/ClassicType.h"

class ClassicCard : public AnyCard
{
private:
    ClassicType type;
    Suit suit;
public:
    ClassicCard(ClassicType type_ = ClassicType::None, Suit suit_ = Suit::None);
    ClassicCard &operator=(const ClassicCard &other);
    std::string getType() const override;
    std::string getSuit() const;
    bool checkAce();
    int getValue() const;
    friend std::ostream &operator<<(std::ostream &os, const ClassicCard &ncard);
    ~ClassicCard();
};

#endif  // FULLCARD_H
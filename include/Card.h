#ifndef CARD_H
#define CARD_H
#include <iostream>

class Card
{
private:
    int rank;

public:
    Card();
    Card(const int rank_);
    int getValue() const;
    friend std::ostream &operator<<(std::ostream &os, const Card &card);
    Card &operator=(const Card &other);
    ~Card() = default;
};
#endif  //CARD_H
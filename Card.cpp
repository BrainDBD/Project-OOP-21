#include "Card.h"
Card::Card(const int rank_) : rank{rank_} {}
int Card::getValue() const { return rank; }
Card &Card::operator=(const Card &other)
    {
        rank = other.rank;
        return *this;
    }
std::ostream &operator<<(std::ostream &os, const Card &card)
    {
        os << card.rank << " ";
        return os;
    }

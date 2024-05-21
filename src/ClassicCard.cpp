#include "../include/ClassicCard.h"

ClassicCard::ClassicCard(ClassicType type_, Suit suit_) : type(type_), suit(suit_) {}
ClassicCard &ClassicCard::operator=(const ClassicCard &other)
{
    if (this != &other)
    {
        type = other.type;
        suit = other.suit;
    }
    return *this;
}
std::string ClassicCard::getType() const
{
    std::string strtype;
    if (type == ClassicType::Two)
        strtype = "Two";
    else if (type == ClassicType::Three)
        strtype = "Three";
    else if (type == ClassicType::Four)
        strtype = "Four";
    else if (type == ClassicType::Five)
        strtype = "Five";
    else if (type == ClassicType::Six)
        strtype = "Six";
    else if (type == ClassicType::Seven)
        strtype = "Seven";
    else if (type == ClassicType::Eight)
        strtype = "Eight";
    else if (type == ClassicType::Nine)
        strtype = "Nine";
    else if (type == ClassicType::Ten)
        strtype = "Ten";
    else if (type == ClassicType::Ace)
        strtype = "Ace";
    else if (type == ClassicType::Jack)
        strtype = "Jack";
    else if (type == ClassicType::Queen)
        strtype = "Queen";
    else if (type == ClassicType::King)
        strtype = "King";
    else if (type == ClassicType::None)
        strtype = "None";
    else if (type == ClassicType::Error)
        strtype = "Error";
    else
        strtype = "Unknown";
    return strtype;
}
std::string ClassicCard::getSuit() const
{
    std::string strtype;
    if (suit == Suit::Spades)
        strtype = "Spades";
    else if (suit == Suit::Clubs)
        strtype = "Clubs";
    else if (suit == Suit::Hearts)
        strtype = "Hearts";
    else if (suit == Suit::Diamonds)
        strtype = "Diamonds";
    else if (suit == Suit::None)
        strtype = "None";
    else if (suit == Suit::Error)
        strtype = "Error";
    else
        strtype = "Unknown";
    return strtype;
}
bool ClassicCard::checkAce()
{
    if (type == ClassicType::Ace)
        return 1;
    return 0;
}
int ClassicCard::getValue() const
{
    int inttype;
    if (type == ClassicType::None)
        inttype = 0;
    else if (type == ClassicType::Two)
        inttype = 2;
    else if (type == ClassicType::Three)
        inttype = 3;
    else if (type == ClassicType::Four)
        inttype = 4;
    else if (type == ClassicType::Five)
        inttype = 5;
    else if (type == ClassicType::Six)
        inttype = 6;
    else if (type == ClassicType::Seven)
        inttype = 7;
    else if (type == ClassicType::Eight)
        inttype = 8;
    else if (type == ClassicType::Nine)
        inttype = 9;
    else if (type == ClassicType::Ten || type == ClassicType::Jack || type == ClassicType::Queen || type == ClassicType::King)
        inttype = 10;
    else if (type == ClassicType::Ace)
        inttype = 11;
    else if (type == ClassicType::Error)
        inttype = 12;
    return inttype;
}
std::ostream &operator<<(std::ostream &os, const ClassicCard &ncard)
{
    std::cout << ncard.getType() << " of " << ncard.getSuit() << " ";
    return os;
}
ClassicCard::~ClassicCard() = default;
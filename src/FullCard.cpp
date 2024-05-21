#include "../include/FullCard.h"

FullCard::FullCard(FullType type_, Suit suit_) : type(type_), suit(suit_) {}
FullCard &FullCard::operator=(const FullCard &other)
{
    if (this != &other)
    {
        type = other.type;
        suit = other.suit;
    }
    return *this;
}
std::string FullCard::getType() const
{
    std::string strtype;
    if (type == FullType::Two)
        strtype = "Two";
    else if (type == FullType::Three)
        strtype = "Three";
    else if (type == FullType::Four)
        strtype = "Four";
    else if (type == FullType::Five)
        strtype = "Five";
    else if (type == FullType::Six)
        strtype = "Six";
    else if (type == FullType::Seven)
        strtype = "Seven";
    else if (type == FullType::Eight)
        strtype = "Eight";
    else if (type == FullType::Nine)
        strtype = "Nine";
    else if (type == FullType::Ten)
        strtype = "Ten";
    else if (type == FullType::Ace)
        strtype = "Ace";
    else if (type == FullType::Jack)
        strtype = "Jack";
    else if (type == FullType::Queen)
        strtype = "Queen";
    else if (type == FullType::King)
        strtype = "King";
    else if (type == FullType::None)
        strtype = "None";
    else if (type == FullType::Error)
        strtype = "Error";
    else
        strtype = "Unknown";
    return strtype;
}
std::string FullCard::getSuit() const
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
bool FullCard::checkAce()
{
    if (type == FullType::Ace)
        return 1;
    return 0;
}
int FullCard::getValue() const
{
    int inttype;
    if (type == FullType::None)
        inttype = 0;
    else if (type == FullType::Two)
        inttype = 2;
    else if (type == FullType::Three)
        inttype = 3;
    else if (type == FullType::Four)
        inttype = 4;
    else if (type == FullType::Five)
        inttype = 5;
    else if (type == FullType::Six)
        inttype = 6;
    else if (type == FullType::Seven)
        inttype = 7;
    else if (type == FullType::Eight)
        inttype = 8;
    else if (type == FullType::Nine)
        inttype = 9;
    else if (type == FullType::Ten || type == FullType::Jack || type == FullType::Queen || type == FullType::King)
        inttype = 10;
    else if (type == FullType::Ace)
        inttype = 11;
    else if (type == FullType::Error)
        inttype = 12;
    return inttype;
}
std::ostream &operator<<(std::ostream &os, const FullCard &ncard)
{
    std::cout << ncard.getType() << " of " << ncard.getSuit() << " ";
    return os;
}
FullCard::~FullCard() = default;
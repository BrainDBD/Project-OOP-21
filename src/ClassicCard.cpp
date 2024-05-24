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
    switch (type)
    {
        case ClassicType::Two:
            strtype = "Two";
            break;
        case ClassicType::Three:
            strtype = "Three";
            break;
        case ClassicType::Four:
            strtype = "Four";
            break;
        case ClassicType::Five:
            strtype = "Five";
            break;
        case ClassicType::Six:
            strtype = "Six";
            break;
        case ClassicType::Seven:
            strtype = "Seven";
            break;
        case ClassicType::Eight:
            strtype = "Eight";
            break;
        case ClassicType::Nine:
            strtype = "Nine";
            break;
        case ClassicType::Ten:
            strtype = "Ten";
            break;
        case ClassicType::Ace:
            strtype = "Ace";
            break;
        case ClassicType::Jack:
            strtype = "Jack";
            break;
        case ClassicType::Queen:
            strtype = "Queen";
            break;
        case ClassicType::King:
            strtype = "King";
            break;
        case ClassicType::None:
            strtype = "None";
            break;
        case ClassicType::Error:
            strtype = "Error";
            break;
        default:
            strtype = "Unknown";
    }
    return strtype;
}
std::string ClassicCard::getSuit() const
{
    std::string strtype;
    switch (suit)
    {
        case Suit::Spades:
            strtype = "Spades";
            break;
        case Suit::Clubs:
            strtype = "Clubs";
            break;
        case Suit::Hearts:
            strtype = "Hearts";
            break;
        case Suit::Diamonds:
            strtype = "Diamonds";
            break;
        case Suit::None:
            strtype = "None";
            break;
        case Suit::Error:
            strtype = "Error";
            break;
        default:
            strtype = "Unknown";
    }
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
    switch (type)
    {
        case ClassicType::None:
            inttype = 0;
            break;
        case ClassicType::Two:
            inttype = 2;
            break;
        case ClassicType::Three:
            inttype = 3;
            break;
        case ClassicType::Four:
            inttype = 4;
            break;
        case ClassicType::Five:
            inttype = 5;
            break;
        case ClassicType::Six:
            inttype = 6;
            break;
        case ClassicType::Seven:
            inttype = 7;
            break;
        case ClassicType::Eight:
            inttype = 8;
            break;
        case ClassicType::Nine:
            inttype = 9;
            break;
        case ClassicType::Ten: case ClassicType::Jack: case ClassicType::Queen: case ClassicType::King:
            inttype = 10;
            break;
        case ClassicType::Ace:
            inttype = 11;
            break;
        case ClassicType::Error:
            inttype = 12;
            break;
        default:
            inttype = -1;
    }
    return inttype;
}

std::ostream &operator<<(std::ostream &os, const ClassicCard &ncard)
{
    std::cout << ncard.getType() << " of " << ncard.getSuit() << " ";
    return os;
}
ClassicCard::~ClassicCard() = default;
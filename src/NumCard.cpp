#include "../include/NumCard.h"

NumCard::NumCard(NumType type_) : type(type_) {}
NumCard &NumCard::operator=(const NumCard &other)
{
    if (this != &other)
        type = other.type;
    return *this;
}
std::string NumCard::getType() const
{
    std::string strtype;
    switch (type)
    {
        case NumType::One:
            strtype = "One";
            break;
        case NumType::Two:
            strtype = "Two";
            break;
        case NumType::Three:
            strtype = "Three";
            break;
        case NumType::Four:
            strtype = "Four";
            break;
        case NumType::Five:
            strtype = "Five";
            break;
        case NumType::Six:
            strtype = "Six";
            break;
        case NumType::Seven:
            strtype = "Seven";
            break;
        case NumType::Eight:
            strtype = "Eight";
            break;
        case NumType::Nine:
            strtype = "Nine";
            break;
        case NumType::Ten:
            strtype = "Ten";
            break;
        case NumType::Eleven:
            strtype = "Eleven";
            break;
        case NumType::None:
            strtype = "None";
            break;
        case NumType::Error:
            strtype = "Error";
            break;
        default:
            strtype = "Unknown";
    }
    return strtype;
}
int NumCard::getValue() const
{
    int inttype;
    switch (type)
    {
        case NumType::None:
            inttype = 0;
            break;
        case NumType::One:
            inttype = 1;
            break;
        case NumType::Two:
            inttype = 2;
            break;
        case NumType::Three:
            inttype = 3;
            break;
        case NumType::Four:
            inttype = 4;
            break;
        case NumType::Five:
            inttype = 5;
            break;
        case NumType::Six:
            inttype = 6;
            break;
        case NumType::Seven:
            inttype = 7;
            break;
        case NumType::Eight:
            inttype = 8;
            break;
        case NumType::Nine:
            inttype = 9;
            break;
        case NumType::Ten:
            inttype = 10;
            break;
        case NumType::Eleven:
            inttype = 11;
            break;
        case NumType::Error:
            inttype = 12;
            break;
        default:
            inttype = -1;
    }
    return inttype;
}
std::ostream &operator<<(std::ostream &os, const NumCard &ncard)
{
    std::string strtype;
    switch (ncard.type)
    {
        case NumType::One:
            strtype = "One";
            break;
        case NumType::Two:
            strtype = "Two";
            break;
        case NumType::Three:
            strtype = "Three";
            break;
        case NumType::Four:
            strtype = "Four";
            break;
        case NumType::Five:
            strtype = "Five";
            break;
        case NumType::Six:
            strtype = "Six";
            break;
        case NumType::Seven:
            strtype = "Seven";
            break;
        case NumType::Eight:
            strtype = "Eight";
            break;
        case NumType::Nine:
            strtype = "Nine";
            break;
        case NumType::Ten:
            strtype = "Ten";
            break;
        case NumType::Eleven:
            strtype = "Eleven";
            break;
        case NumType::None:
            strtype = "None";
            break;
        case NumType::Error:
            strtype = "Error";
            break;
        default:
            strtype = "Unknown";
    }
    os << strtype << " ";
    return os;
}
NumCard::~NumCard() = default;
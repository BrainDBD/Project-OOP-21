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
    if (type == NumType::One)
        strtype = "One";
    else if (type == NumType::Two)
        strtype = "Two";
    else if (type == NumType::Three)
        strtype = "Three";
    else if (type == NumType::Four)
        strtype = "Four";
    else if (type == NumType::Five)
        strtype = "Five";
    else if (type == NumType::Six)
        strtype = "Six";
    else if (type == NumType::Seven)
        strtype = "Seven";
    else if (type == NumType::Eight)
        strtype = "Eight";
    else if (type == NumType::Nine)
        strtype = "Nine";
    else if (type == NumType::Ten)
        strtype = "Ten";
    else if (type == NumType::Eleven)
        strtype = "Eleven";
    else if (type == NumType::None)
        strtype = "None";
    else if (type == NumType::Error)
        strtype = "Error";
    else
        strtype = "Unknown";
    return strtype;
}
int NumCard::getValue() const
{
    int inttype;
    if (type == NumType::None)
        inttype = 0;
    else if (type == NumType::One)
        inttype = 1;
    else if (type == NumType::Two)
        inttype = 2;
    else if (type == NumType::Three)
        inttype = 3;
    else if (type == NumType::Four)
        inttype = 4;
    else if (type == NumType::Five)
        inttype = 5;
    else if (type == NumType::Six)
        inttype = 6;
    else if (type == NumType::Seven)
        inttype = 7;
    else if (type == NumType::Eight)
        inttype = 8;
    else if (type == NumType::Nine)
        inttype = 9;
    else if (type == NumType::Ten)
        inttype = 10;
    else if (type == NumType::Eleven)
        inttype = 11;
    else if (type == NumType::Error)
        inttype = 12;
    return inttype;
}
std::ostream &operator<<(std::ostream &os, const NumCard &ncard)
{
    std::string strtype;
    if (ncard.type == NumType::One)
        strtype = "One";
    else if (ncard.type == NumType::Two)
        strtype = "Two";
    else if (ncard.type == NumType::Three)
        strtype = "Three";
    else if (ncard.type == NumType::Four)
        strtype = "Four";
    else if (ncard.type == NumType::Five)
        strtype = "Five";
    else if (ncard.type == NumType::Six)
        strtype = "Six";
    else if (ncard.type == NumType::Seven)
        strtype = "Seven";
    else if (ncard.type == NumType::Eight)
        strtype = "Eight";
    else if (ncard.type == NumType::Nine)
        strtype = "Nine";
    else if (ncard.type == NumType::Ten)
        strtype = "Ten";
    else if (ncard.type == NumType::Eleven)
        strtype = "Eleven";
    else if (ncard.type == NumType::None)
        strtype = "None";
    else if (ncard.type == NumType::Error)
        strtype = "Error";
    else
        strtype = "Unknown";
    std::cout << strtype << " ";
    return os;
}
NumCard::~NumCard() = default;
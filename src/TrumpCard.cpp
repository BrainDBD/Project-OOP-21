#include "../include/TrumpCard.h"

TrumpCard::TrumpCard(TrumpType type_) : type(type_) {}
TrumpCard &TrumpCard::operator=(const TrumpCard &other)
{
    if (this != &other)
        type = other.type;
    return *this;
}
std::string TrumpCard::getType() const
{
    std::string strtype;
    if (type == TrumpType::Attack)
        strtype = "Attack";
    else if (type == TrumpType::Shield)
        strtype = "Shield";
    else if (type == TrumpType::Return)
        strtype = "Return";
    else if (type == TrumpType::Remove)
        strtype = "Remove";
    else if (type == TrumpType::Exchange)
        strtype = "Exchange";
    else if (type == TrumpType::Destroy)
        strtype = "Destroy";
    else if (type == TrumpType::Clairvoyance)
        strtype = "Clairvoyance";
    else if (type == TrumpType::Card2)
        strtype = "Draw 2 Card";
    else if (type == TrumpType::Card3)
        strtype = "Draw 3 Card";
    else if (type == TrumpType::Card4)
        strtype = "Draw 4 Card";
    else if (type == TrumpType::Card5)
        strtype = "Draw 5 Card";
    else if (type == TrumpType::Card6)
        strtype = "Draw 6 Card";
    else if (type == TrumpType::Card7)
        strtype = "Draw 7 Card";
    else if (type == TrumpType::GoFor17)
        strtype = "Go For 17";
    else if (type == TrumpType::GoFor24)
        strtype = "Go For 24";
    else if (type == TrumpType::None)
        strtype = "None";
    else if (type == TrumpType::Error)
        strtype = "Error";
    else
        strtype = "Unknown";
    return strtype;
}
std::ostream &operator<<(std::ostream &os, const TrumpCard &tcard)
{
    std::string strtype;
    if (tcard.type == TrumpType::Attack)
        strtype = "Attack";
    else if (tcard.type == TrumpType::Shield)
        strtype = "Shield";
    else if (tcard.type == TrumpType::Return)
        strtype = "Return";
    else if (tcard.type == TrumpType::Remove)
        strtype = "Remove";
    else if (tcard.type == TrumpType::Exchange)
        strtype = "Exchange";
    else if (tcard.type == TrumpType::Destroy)
        strtype = "Destroy";
    else if (tcard.type == TrumpType::Clairvoyance)
        strtype = "Clairvoyance";
    else if (tcard.type == TrumpType::Card2)
        strtype = "Draw 2 Card";
    else if (tcard.type == TrumpType::Card3)
        strtype = "Draw 3 Card";
    else if (tcard.type == TrumpType::Card4)
        strtype = "Draw 4 Card";
    else if (tcard.type == TrumpType::Card5)
        strtype = "Draw 5 Card";
    else if (tcard.type == TrumpType::Card6)
        strtype = "Draw 6 Card";
    else if (tcard.type == TrumpType::Card7)
        strtype = "Draw 7 Card";
    else if (tcard.type == TrumpType::GoFor17)
        strtype = "Go For 17";
    else if (tcard.type == TrumpType::GoFor24)
        strtype = "Go For 24";
    else if (tcard.type == TrumpType::None)
        strtype = "None";
    else if (tcard.type == TrumpType::Error)
        strtype = "Error";
    else
        strtype = "Unknown";

    os << strtype << " ";
    return os;
}
TrumpCard::~TrumpCard() = default;
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
    switch (type)
    {
        case TrumpType::Attack:
            strtype = "Attack";
            break;
        case TrumpType::Shield:
            strtype = "Shield";
            break;
        case TrumpType::Return:
            strtype = "Return";
            break;
        case TrumpType::Remove:
            strtype = "Remove";
            break;
        case TrumpType::Exchange:
            strtype = "Exchange";
            break;
        case TrumpType::Destroy:
            strtype = "Destroy";
            break;
        case TrumpType::Clairvoyance:
            strtype = "Clairvoyance";
            break;
        case TrumpType::Card2:
            strtype = "Draw 2 Card";
            break;
        case TrumpType::Card3:
            strtype = "Draw 3 Card";
            break;
        case TrumpType::Card4:
            strtype = "Draw 4 Card";
            break;
        case TrumpType::Card5:
            strtype = "Draw 5 Card";
            break;
        case TrumpType::Card6:
            strtype = "Draw 6 Card";
            break;
        case TrumpType::Card7:
            strtype = "Draw 7 Card";
            break;
        case TrumpType::GoFor17:
            strtype = "Go For 17";
            break;
        case TrumpType::GoFor24:
            strtype = "Go For 24";
            break;
        case TrumpType::None:
            strtype = "None";
            break;
        case TrumpType::Error:
            strtype = "Error";
            break;
        default:
            strtype = "Unknown";
    }
    return strtype;
}
std::ostream &operator<<(std::ostream &os, const TrumpCard &tcard)
{
    std::string strtype;
    switch (tcard.type)
    {
        case TrumpType::Attack:
            strtype = "Attack";
            break;
        case TrumpType::Shield:
            strtype = "Shield";
            break;
        case TrumpType::Return:
            strtype = "Return";
            break;
        case TrumpType::Remove:
            strtype = "Remove";
            break;
        case TrumpType::Exchange:
            strtype = "Exchange";
            break;
        case TrumpType::Destroy:
            strtype = "Destroy";
            break;
        case TrumpType::Clairvoyance:
            strtype = "Clairvoyance";
            break;
        case TrumpType::Card2:
            strtype = "Draw 2 Card";
            break;
        case TrumpType::Card3:
            strtype = "Draw 3 Card";
            break;
        case TrumpType::Card4:
            strtype = "Draw 4 Card";
            break;
        case TrumpType::Card5:
            strtype = "Draw 5 Card";
            break;
        case TrumpType::Card6:
            strtype = "Draw 6 Card";
            break;
        case TrumpType::Card7:
            strtype = "Draw 7 Card";
            break;
        case TrumpType::GoFor17:
            strtype = "Go For 17";
            break;
        case TrumpType::GoFor24:
            strtype = "Go For 24";
            break;
        case TrumpType::None:
            strtype = "None";
            break;
        case TrumpType::Error:
            strtype = "Error";
            break;
        default:
            strtype = "Unknown";
    }
    os << strtype << " ";
    return os;
}
TrumpCard::~TrumpCard() = default;
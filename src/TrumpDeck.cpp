#include "../include/TrumpDeck.h"

TrumpDeck::TrumpDeck(const std::vector<AnyCard*> &cards_) : TrumpCardContainer(cards_) {}
TrumpDeck::TrumpDeck(const TrumpDeck &other) : TrumpCardContainer(other) {}
void TrumpDeck::removefromDeck(TrumpCard tcard_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i]->getType() == tcard_.getType())
        {
            cards.erase(cards.begin() + i);
            break;
        }
}
void TrumpDeck::createDeck()
{
    for (int type = static_cast<int>(TrumpType::Attack); type <= static_cast<int>(TrumpType::GoFor24); ++type)
    {
        TrumpType cardType = static_cast<TrumpType>(type);
        AnyCard *auxcard = new TrumpCard{cardType};
        int i
        ;
        if (type == static_cast<int>(TrumpType::Attack) || type == static_cast<int>(TrumpType::Shield) || type == static_cast<int>(TrumpType::Return) || type == static_cast<int>(TrumpType::Remove))
            i = 3;
        else if (type == static_cast<int>(TrumpType::Exchange) || type == static_cast<int>(TrumpType::Destroy) || type == static_cast<int>(TrumpType::Clairvoyance))
            i = 2;
        else
            i = 1;
        for (int j = 0; j < i; j++)
            cards.emplace_back(auxcard);
    }
}
void TrumpDeck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}
bool TrumpDeck::checkEmpty()
{
    if (!cards.empty())
        return 0;
    return 1;
}
TrumpCard TrumpDeck::dealCard()
{
    if (!cards.empty())
    {
        TrumpCard dealttcard = *dynamic_cast<TrumpCard*>(cards.back());
        cards.pop_back();
        return dealttcard;
    }
    else
    {
        TrumpCard errortcard{TrumpType::Error};
        return errortcard;
    }
}
TrumpCard TrumpDeck::drawCard(TrumpCard tcard_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i]->getType() == tcard_.getType())
        {
            TrumpCard drawntcard = *dynamic_cast<TrumpCard*>(cards[i]);
            removefromDeck(*dynamic_cast<TrumpCard*>(cards[i]));
            return drawntcard;
        }
    TrumpCard drawntcard = {TrumpType::Error};
    return drawntcard;
}
TrumpDeck &TrumpDeck::operator=(const TrumpDeck &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
TrumpDeck::~TrumpDeck() = default;
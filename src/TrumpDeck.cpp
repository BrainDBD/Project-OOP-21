#include "../include/TrumpDeck.h"
#include <algorithm>
#include <random>

TrumpDeck::TrumpDeck(const std::vector<TrumpCard> &tcards_) : tcards{tcards_} {}
TrumpDeck::TrumpDeck(const TrumpDeck &other) : tcards{other.tcards} {}
void TrumpDeck::addToTrumpDeck(TrumpCard tcard_) { tcards.push_back(tcard_); }
void TrumpDeck::removefromTrumpDeck(TrumpCard tcard_)
{
    for (unsigned int i = 0; i < tcards.size(); i++)
        if (tcards[i].getString() == tcard_.getString())
        {
            tcards.erase(tcards.begin() + i);
            break;
        }
}
void TrumpDeck::createTrumpDeck()
{
    TrumpCard vtcard[22] = {TrumpType::Attack, TrumpType::Attack, TrumpType::Attack, TrumpType::Shield, TrumpType::Shield, TrumpType::Shield, TrumpType::Return, TrumpType::Return, TrumpType::Remove, TrumpType::Remove, TrumpType::Exchange, TrumpType::Exchange, TrumpType::Card2, TrumpType::Card3, TrumpType::Card4, TrumpType::Card5, TrumpType::Card6, TrumpType::Card7, TrumpType::Clairvoyance, TrumpType::Clairvoyance, TrumpType::GoFor17, TrumpType::GoFor24};
    for (int i = 0; i < 22; i++)
        tcards.push_back(vtcard[i]);
}
void TrumpDeck::emptyTrumpDeck()
{
    while (!tcards.empty())
    {
        TrumpCard dealttcard = tcards.back();
        tcards.pop_back();
    }
}
void TrumpDeck::shuffleTrumpDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(tcards.begin(), tcards.end(), g);
}
int TrumpDeck::showTrumpSize()
{
    int s = tcards.size();
    return s;
}
bool TrumpDeck::checkEmpty()
{
    if (!tcards.empty())
        return 0;
    return 1;
}
TrumpCard TrumpDeck::dealTrumpCard()
{
    if (!tcards.empty())
    {
        TrumpCard dealttcard = tcards.back(); // pretend that the deck is bottom-up
        tcards.pop_back();
        return dealttcard;
    }
    else
    {
        TrumpCard errortcard = {TrumpType::Error};
        return errortcard; // will serve as a tell that the deck is empty
    }
}
TrumpCard TrumpDeck::drawTrumpCard(TrumpCard tcard_)
{
    for (unsigned int i = 0; i < tcards.size(); i++)
        if (tcards[i].getString() == tcard_.getString())
        {
            TrumpCard drawntcard = tcards[i];
            removefromTrumpDeck(tcards[i]);
            return drawntcard;
        }
    TrumpCard drawntcard = {TrumpType::Error};
    return drawntcard;
}
TrumpCard TrumpDeck::lastTrumpCard()
{
    TrumpCard lasttcard = tcards.back();
    return lasttcard;
}
void TrumpDeck::removeLastTrumpCard()
{
    tcards.pop_back();
}
TrumpDeck &TrumpDeck::operator=(const TrumpDeck &other)
{
    for (unsigned int i = 0; i < other.tcards.size(); i++)
        tcards[i] = other.tcards[i];
    return *this;
}
std::ostream &operator<<(std::ostream &os, const TrumpDeck &tdeck)
{
    for (unsigned int i = 0; i < tdeck.tcards.size(); i++)
        std::cout << tdeck.tcards[i] << " ";
    std::cout << '\n';
    return os;
}
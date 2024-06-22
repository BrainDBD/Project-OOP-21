#include "../include/TrumpCardContainer.h"

TrumpCardContainer::TrumpCardContainer(const std::vector<AnyCard*> &cards_) : BasicCardContainer{cards_} {}

int TrumpCardContainer::DeckSize()
{
    int s = cards.size();
    return s;
}
void TrumpCardContainer::emptyDeck()
{
    std::for_each(cards.begin(), cards.end(), [](AnyCard* card)
    {
        delete card;
    });
    cards.clear();
}
void TrumpCardContainer::removefromDeck(TrumpCard &card_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i]->getType() == card_.getType())
        {
            cards.erase(cards.begin() + i);
            break;
        }
}
void TrumpCardContainer::removeLastCard()
{
    cards.pop_back();
}
void TrumpCardContainer::Afisare(std::ostream &os)
{
    std::for_each(cards.begin(), cards.end(), [&os](AnyCard* card)
    {
        os << card << " (" << dynamic_cast<TrumpCard*>(card)->getType() << ")";
    });
    os << '\n';
}
std::ostream &operator<<(std::ostream &os, const TrumpCardContainer &deck)
{
    std::for_each(deck.cards.begin(), deck.cards.end(), [&os](AnyCard* card)
    {
        os << *dynamic_cast<TrumpCard*>(card) << " ";
    });
    os << '\n';
    return os;
}
TrumpCardContainer::~TrumpCardContainer() = default;

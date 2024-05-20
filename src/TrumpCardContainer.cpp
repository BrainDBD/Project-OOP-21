#include "../include/TrumpCardContainer.h"

TrumpCardContainer::TrumpCardContainer(const std::vector<AnyCard*> &cards_) : BasicCardContainer{cards_} {}

int TrumpCardContainer::DeckSize()
{
    int s = cards.size();
    return s;
}
void TrumpCardContainer::emptyDeck()
{
    while (!cards.empty())
    {
        TrumpCard dealtcard = *dynamic_cast<TrumpCard*>(cards.back());
        cards.pop_back();
    }
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
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " (" << dynamic_cast<TrumpCard*>(cards[i])->getType() << ")";
    std::cout << '\n';
}
std::ostream &operator<<(std::ostream &os, const TrumpCardContainer &deck)
{
    for (unsigned int i = 0; i < deck.cards.size(); i++)
        std::cout << *dynamic_cast<TrumpCard*>(deck.cards[i]) << " ";
    std::cout << '\n';
    return os;
}
TrumpCardContainer::~TrumpCardContainer() = default;

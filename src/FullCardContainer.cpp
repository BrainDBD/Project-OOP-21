#include "../include/FullCardContainer.h"

FullCardContainer::FullCardContainer(const std::vector<AnyCard*> &cards_) : BasicCardContainer{cards_} {}

int FullCardContainer::DeckSize()
{
    int s = cards.size();
    return s;
}
void FullCardContainer::emptyDeck()
{
    while (!cards.empty())
    {
        FullCard dealtcard = *dynamic_cast<FullCard*>(cards.back());
        cards.pop_back();
    }
}
void FullCardContainer::removefromDeck(FullCard &card_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i]->getType() == card_.getType())
        {
            cards.erase(cards.begin() + i);
            break;
        }
}
void FullCardContainer::removeLastCard()
{
    cards.pop_back();
}
std::ostream &operator<<(std::ostream &os, const FullCardContainer &deck)
{
    for (unsigned int i = 0; i < deck.cards.size(); i++)
        std::cout << *dynamic_cast<FullCard*>(deck.cards[i]) << " ";
    std::cout << '\n';
    return os;
}
FullCardContainer::~FullCardContainer() = default;

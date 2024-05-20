#include "../include/NumCardContainer.h"

NumCardContainer::NumCardContainer(const std::vector<AnyCard*> &cards_) : BasicCardContainer{cards_} {}

int NumCardContainer::DeckSize()
{
    int s = cards.size();
    return s;
}
void NumCardContainer::emptyDeck()
{
    while (!cards.empty())
    {
        NumCard dealtcard = *dynamic_cast<NumCard*>(cards.back());
        cards.pop_back();
    }
}
void NumCardContainer::removefromDeck(NumCard &card_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i]->getType() == card_.getType())
        {
            cards.erase(cards.begin() + i);
            break;
        }
}
void NumCardContainer::removeLastCard()
{
    cards.pop_back();
}
std::ostream &operator<<(std::ostream &os, const NumCardContainer &deck)
{
    for (unsigned int i = 0; i < deck.cards.size(); i++)
        std::cout << *dynamic_cast<NumCard*>(deck.cards[i]) << " ";
    std::cout << '\n';
    return os;
}
NumCardContainer::~NumCardContainer() = default;

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
void FullCardContainer::removefromDeck(FullCard card_)
{
    for (auto newfullCard = cards.begin(); newfullCard != cards.end(); ++newfullCard)
    {
        FullCard* fullCard = dynamic_cast<FullCard*>(*newfullCard);
        if (fullCard && fullCard->getType() == card_.getType() && fullCard->getSuit() == card_.getSuit())
        {
            cards.erase(newfullCard);
            break;
        }
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

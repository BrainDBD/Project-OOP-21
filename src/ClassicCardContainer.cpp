#include "../include/ClassicCardContainer.h"

ClassicCardContainer::ClassicCardContainer(const std::vector<AnyCard*> &cards_) : BasicCardContainer{cards_} {}
int ClassicCardContainer::DeckSize()
{
    int s = cards.size();
    return s;
}
void ClassicCardContainer::emptyDeck()
{
    std::for_each(cards.begin(), cards.end(), [](AnyCard* card)
    {
        delete card;
    });
    cards.clear();
}
void ClassicCardContainer::removefromDeck(ClassicCard card_)
{
    for (auto newfullCard = cards.begin(); newfullCard != cards.end(); ++newfullCard)
    {
        ClassicCard* fullCard = dynamic_cast<ClassicCard*>(*newfullCard);
        if (fullCard && fullCard->getType() == card_.getType() && fullCard->getSuit() == card_.getSuit())
        {
            cards.erase(newfullCard);
            break;
        }
    }
}
void ClassicCardContainer::removeLastCard()
{
    cards.pop_back();
}
std::ostream &operator<<(std::ostream &os, const ClassicCardContainer &deck)
{
    std::for_each(deck.cards.begin(), deck.cards.end(), [&os](AnyCard* card)
    {
        os << *dynamic_cast<ClassicCard*>(card) << " ";
    });
    os << '\n';
    return os;
}
ClassicCardContainer::~ClassicCardContainer() = default;

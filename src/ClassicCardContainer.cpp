#include "../include/ClassicCardContainer.h"

ClassicCardContainer::ClassicCardContainer(const std::vector<AnyCard*> &cards_) : BasicCardContainer{cards_} {}

int ClassicCardContainer::DeckSize()
{
    int s = cards.size();
    return s;
}
void ClassicCardContainer::emptyDeck()
{
    while (!cards.empty())
    {
        ClassicCard dealtcard = *dynamic_cast<ClassicCard*>(cards.back());
        cards.pop_back();
    }
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
    for (unsigned int i = 0; i < deck.cards.size(); i++)
        std::cout << *dynamic_cast<ClassicCard*>(deck.cards[i]) << " ";
    std::cout << '\n';
    return os;
}
ClassicCardContainer::~ClassicCardContainer() = default;

#include "../include/ClassicHand.h"

ClassicHand::ClassicHand(const std::vector<AnyCard*> &cards_) : ClassicCardContainer(cards_) {}
ClassicHand::ClassicHand(const ClassicHand &other) : ClassicCardContainer(other.cards) {}
void ClassicHand::addToDeck(const ClassicCard &card_) { cards.push_back(new ClassicCard(card_)); }
ClassicCard ClassicHand::lastCard()
{
    ClassicCard lastcard = *dynamic_cast<ClassicCard*>(cards.back());
    return lastcard;
}
void ClassicHand::exchange(ClassicHand &other)
{
    ClassicCard lastcard1 = lastCard();
    ClassicCard lastcard2 = other.lastCard();
    removeLastCard();
    other.removeLastCard();
    addToDeck(lastcard2);
    other.addToDeck(lastcard1);
}
int ClassicHand::getnAces()
{
    int n = 0;
    for (auto newfullCard = cards.begin(); newfullCard != cards.end(); ++newfullCard)
    {
        ClassicCard* fullCard = dynamic_cast<ClassicCard*>(*newfullCard);
        if (fullCard->checkAce() == 1)
            n++;
    }
    return n;
}
ClassicHand &ClassicHand::operator=(const ClassicHand &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
void ClassicHand::Afisare(std::ostream &os)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " (" << dynamic_cast<ClassicCard *>(cards[i])->getValue() << ")";
    std::cout << '\n';
}
ClassicHand::~ClassicHand() = default;
#include "../include/FullHand.h"

FullHand::FullHand(const std::vector<AnyCard*> &cards_) : FullCardContainer(cards_) {}
FullHand::FullHand(const FullHand &other) : FullCardContainer(other) {}
void FullHand::addToDeck(const FullCard &card_) { cards.push_back(new FullCard(card_)); }
FullCard FullHand::lastCard()
{
    FullCard lastcard = *dynamic_cast<FullCard*>(cards.back());
    return lastcard;
}
void FullHand::exchange(FullHand &other)
{
    FullCard lastcard1 = lastCard();
    FullCard lastcard2 = other.lastCard();
    removeLastCard();
    other.removeLastCard();
    addToDeck(lastcard2);
    other.addToDeck(lastcard1);
}
int FullHand::getnAces()
{
    int n = 0;
    for (auto newfullCard = cards.begin(); newfullCard != cards.end(); ++newfullCard)
    {
        FullCard* fullCard = dynamic_cast<FullCard*>(*newfullCard);
        if (fullCard->checkAce() == 1)
            n++;
    }
    return n;
}
FullHand &FullHand::operator=(const FullHand &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
void FullHand::Afisare(std::ostream &os)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " (" << dynamic_cast<FullCard *>(cards[i])->getValue() << ")";
    std::cout << '\n';
}
FullHand::~FullHand() = default;
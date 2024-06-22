#include "../include/ClassicHand.h"

ClassicHand::ClassicHand(const std::vector<AnyCard*> &cards_) : ClassicCardContainer(cards_) {}
ClassicHand::ClassicHand(const ClassicHand &other) : ClassicCardContainer(other.cards) {}
ClassicHand::ClassicHand(ClassicHand&& other) noexcept : ClassicCardContainer()
{
    //cards.swap(other.cards);
    cards = std::move(other.cards);
    other.cards.clear();
}
void ClassicHand::addToDeck(const ClassicCard &card_) { cards.push_back(new ClassicCard(card_)); }
void ClassicHand::getDealerHand()
{
    std::for_each(cards.begin(), cards.end(), [this](AnyCard* card)
    {
        if(card != cards[1])
            std::cout << *dynamic_cast<ClassicCard*>(card) << " ";
        else
            std::cout << "[[Face-Down Card]]";
    });
    std::cout << "\n\n";         
}
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
    std::for_each(cards.begin(), cards.end(), [&n](AnyCard* card)
    {
        ClassicCard* classicCard = dynamic_cast<ClassicCard*>(card);
        if (classicCard->checkAce() == 1)
            n++;
    });
    return n;
}
ClassicHand &ClassicHand::operator=(const ClassicHand &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
ClassicHand &ClassicHand::operator=(ClassicHand&& other) noexcept
{
    if (this != &other)
    {
        std::for_each(cards.begin(), cards.end(), [](AnyCard* card) {
            delete card;
        });
        cards.clear();
        cards = std::move(other.cards);
        other.cards.clear();
    }
    return *this;
}
void ClassicHand::Afisare(std::ostream &os)
{
    std::for_each(cards.begin(), cards.end(), [](AnyCard* card) {
        std::cout << card << " (" << dynamic_cast<ClassicCard*>(card)->getValue() << ")";
    });
    std::cout << '\n';
}
ClassicHand::~ClassicHand() = default;
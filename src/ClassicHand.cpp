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
    for (unsigned int i = 0; i < cards.size(); i++)
        if(i != 1)
            std::cout << *dynamic_cast<ClassicCard*>(cards[i]) << " ";
        else
            std::cout<<"[[Face-Down Card]]";
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
    for (auto newclassicCard = cards.begin(); newclassicCard != cards.end(); ++newclassicCard)
    {
        ClassicCard* classicCard = dynamic_cast<ClassicCard*>(*newclassicCard);
        if (classicCard->checkAce() == 1)
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
ClassicHand &ClassicHand::operator=(ClassicHand&& other) noexcept
{
    if (this != &other)
    {
        for (auto& card : cards)
        {
            delete card;
        }
        cards.clear();
        cards = std::move(other.cards);
        other.cards.clear();
    }
    return *this;
}
void ClassicHand::Afisare(std::ostream &os)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " (" << dynamic_cast<ClassicCard*>(cards[i])->getValue() << ")";
    std::cout << '\n';
}
ClassicHand::~ClassicHand() = default;
#include "../include/NumHand.h"

NumHand::NumHand(const std::vector<AnyCard*> &cards_) : NumCardContainer(cards_) {}
NumHand::NumHand(const NumHand &other) : NumCardContainer(other) {}
NumHand::NumHand(NumHand&& other) noexcept : NumCardContainer()
{
    //cards.swap(other.cards);
    cards = std::move(other.cards);
    other.cards.clear();
}
void NumHand::addToDeck(const NumCard &card_) { cards.push_back(new NumCard(card_)); }
NumCard NumHand::lastCard()
{
    NumCard lastcard = *dynamic_cast<NumCard*>(cards.back());
    return lastcard;
}
void NumHand::exchange(NumHand &other)
{
    NumCard lastcard1 = lastCard();
    NumCard lastcard2 = other.lastCard();
    removeLastCard();
    other.removeLastCard();
    addToDeck(lastcard2);
    other.addToDeck(lastcard1);
}
NumHand &NumHand::operator=(const NumHand &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
NumHand &NumHand::operator=(NumHand&& other) noexcept
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
void NumHand::Afisare(std::ostream &os)
{
    std::for_each(cards.begin(), cards.end(), [](const AnyCard* card)
    {
        std::cout << card << " (" << dynamic_cast<const NumCard*>(card)->getValue() << ")";
    });
    std::cout << '\n';
}
NumHand::~NumHand() = default;
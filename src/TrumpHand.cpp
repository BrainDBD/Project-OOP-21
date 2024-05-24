#include "../include/TrumpHand.h"

TrumpHand::TrumpHand(const std::vector<AnyCard*> &cards_) : TrumpCardContainer(cards_) {}
TrumpHand::TrumpHand(const TrumpHand &other) : TrumpCardContainer(other) {}
TrumpHand::TrumpHand(TrumpHand&& other) noexcept : TrumpCardContainer()
{
    //cards.swap(other.cards);
    cards = std::move(other.cards);
    other.cards.clear();
}
void TrumpHand::addToDeck(const TrumpCard &card_) { cards.push_back(new TrumpCard(card_)); }
TrumpCard TrumpHand::lastCard()
{
    TrumpCard lastcard = *dynamic_cast<TrumpCard*>(cards.back());
    return lastcard;
}
void TrumpHand::exchange(TrumpHand &other)
{
    TrumpCard lastcard1 = lastCard();
    TrumpCard lastcard2 = other.lastCard();
    removeLastCard();
    other.removeLastCard();
    addToDeck(lastcard2);
    other.addToDeck(lastcard1);
}
TrumpHand &TrumpHand::operator=(const TrumpHand &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
TrumpHand &TrumpHand::operator=(TrumpHand&& other) noexcept
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
TrumpHand::~TrumpHand() = default;
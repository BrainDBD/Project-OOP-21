#include "../include/Deck.h"
#include <algorithm>
#include <random>

Deck::Deck(const std::vector<Card> &cards_) : cards{cards_} {}
Deck::Deck(const Deck &other) : cards{other.cards} {}
void Deck::createDeck()
{
    Card vcard[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (int i = 0; i < 11; i++)
        cards.push_back(vcard[i]);
}
void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}
void Deck::addToDeck(Card card_) { cards.push_back(card_); }
void Deck::emptyDeck()
{
    while (!cards.empty())
    {
        Card dealtcard = cards.back();
        cards.pop_back();
    }
}
void Deck::removefromDeck(Card card_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i].getValue() == card_.getValue())
        {
            cards.erase(cards.begin() + i);
            break;
        }
}
int Deck::DeckSize()
{
    int s = cards.size();
    return s;
}
Card Deck::dealCard()
{
    if (!cards.empty())
    {
        Card dealtcard = cards.back(); // pretend that the deck is bottom-up
        cards.pop_back();
        return dealtcard;
    }
    else
    {
        Card errorcard{12};
        return errorcard; // will serve as a tell that the deck is empty
    }
}
Card Deck::drawCard(Card card_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i].getValue() == card_.getValue())
        {
            Card drawncard = cards[i];
            removefromDeck(cards[i]);
            return drawncard;
        }
    Card drawncard = {12};
    return drawncard;
}
Card Deck::lastCard()
{
    Card lastcard = cards.back();
    return lastcard;
}
void Deck::removeLastCard()
{
    cards.pop_back();
}
void Deck::exchange(Deck &other)
{
    Card lastcard1 = lastCard();
    Card lastcard2 = other.lastCard();
    removeLastCard();
    other.removeLastCard();
    addToDeck(lastcard2);
    other.addToDeck(lastcard1);
}
Deck &Deck::operator=(const Deck &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Deck &deck)
{
    for (unsigned int i = 0; i < deck.cards.size(); i++)
        std::cout << deck.cards[i] << " ";
    std::cout << '\n';
    return os;
}

#include "Deck.h"
#include <vector>
#include <algorithm>
#include <random>


Deck::Deck(const std::vector<Card> &cards_) : cards{cards_} {}
Deck::Deck(const Deck &other) : cards{other.cards} {}
void Deck::addToDeck(Card card_) { cards.push_back(card_); }
void Deck::createDeck(Deck &deck)
{
    Card vcard[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for (int i = 0; i < 11; i++)
        deck.addToDeck(vcard[i]);
}
void Deck::emptyDeck()
{
    while (!cards.empty())
        {
            Card dealtcard = cards.back();
            cards.pop_back();
        }
    }
void Deck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
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
Card Deck::lastCard()
{
    Card lastcard =cards.back();
    return lastcard;
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

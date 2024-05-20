#include "../include/TrumpPlayer.h"

TrumpPlayer::TrumpPlayer(const std::string name_, int points_, int score_, const NumHand hand_, const TrumpHand trumphand_) : StarterPlayer(name_, points_, score_), hand{hand_}, trumphand{trumphand_} {}
TrumpPlayer::TrumpPlayer(const TrumpPlayer &other) : StarterPlayer(other), hand{other.hand}, trumphand{other.trumphand} {}
std::string TrumpPlayer::getName() const { return name; }
void TrumpPlayer::showHand() { std::cout << hand; }
int TrumpPlayer::HandSize()
{
    int s = hand.DeckSize();
    return s;
}
void TrumpPlayer::showhiddenHand()
{
    for (int i = 0; i < hand.DeckSize(); i++)
        std::cout << "## ";
    std::cout << '\n';
}
void TrumpPlayer::addToHand(NumCard card_) { hand.addToDeck(card_); }
void TrumpPlayer::exchangeHands(TrumpPlayer &other) { hand.exchange(other.hand); }
void TrumpPlayer::returnHand(NumHand &deck)
{
    NumCard lastcard = hand.lastCard();
    hand.removeLastCard();
    deck.addToDeck(lastcard);
}
void TrumpPlayer::clearHand() { hand.emptyDeck(); }
void TrumpPlayer::showTrumpHand() { std::cout << trumphand; }
void TrumpPlayer::addToTrumpHand(TrumpCard tcard_) { trumphand.addToDeck(tcard_); }
int TrumpPlayer::getTrumpHandSize()
{
    int s = trumphand.DeckSize();
    return s;
}
void TrumpPlayer::clearTrumpHand() { trumphand.emptyDeck(); }
TrumpPlayer &TrumpPlayer::operator=(const TrumpPlayer &other)
{
    if (this != &other)
    {
        name = other.name;
        points = other.points;
        score = other.score;
        hand = other.hand;
        trumphand = other.trumphand;
    }
    return *this;
}
void TrumpPlayer::Display(std::ostream &os) const
{
    os << "Printing all data for NumPlayer with Id: " << Id << '\n';
}
std::ostream &operator<<(std::ostream &os, const TrumpPlayer &player)
{
    player.Display(os);
    os << "Name: " << player.name << '\n';
    os << "Points: " << player.points << '\n';
    os << "Score: " << player.score << '\n';
    os << "Hand: " << player.hand << '\n';
    os << "Trump Cards: " << player.trumphand << '\n';
    return os;
}
TrumpPlayer::~TrumpPlayer() = default;
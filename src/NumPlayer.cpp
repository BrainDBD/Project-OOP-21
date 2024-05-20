#include "../include/NumPlayer.h"

NumPlayer::NumPlayer(std::string name_, int points_, int score_, NumHand hand_) : StarterPlayer(name_, points_, score_), hand{hand_} {}

NumPlayer::NumPlayer(const NumPlayer &other) : StarterPlayer(other), hand{other.hand} {}

void NumPlayer::showHand() { std::cout << hand << '\n'; }

int NumPlayer::HandSize()
{
    int s = hand.DeckSize();
    return s;
}

void NumPlayer::addToHand(NumCard card_) { hand.addToDeck(card_); }

void NumPlayer::exchangeHands(NumPlayer &other) { hand.exchange(other.hand); }

void NumPlayer::returnHand(NumHand &deck)
{
    NumCard lastcard = hand.lastCard();
    hand.removeLastCard();
    deck.addToDeck(lastcard);
}

void NumPlayer::clearHand() { hand.emptyDeck(); }

void NumPlayer::decreaseScore(int betsy) { score = score - betsy; }

NumPlayer &NumPlayer::operator=(const NumPlayer &other)
{
    if (this != &other)
    {
        name = other.name;
        points = other.points;
        score = other.score;
        hand = other.hand;
    }
    return *this;
}

void NumPlayer::Display(std::ostream &os) const
{
    os << "Printing all data for NumPlayer with Id: " << Id << '\n';
}

std::ostream &operator<<(std::ostream &os, const NumPlayer &player)
{
    player.Display(os);
    os << "Name: " << player.name << '\n';
    os << "Points: " << player.points << '\n';
    os << "Score: " << player.score << '\n';
    os << "Hand: " << player.hand << '\n';
    return os;
}

NumPlayer::~NumPlayer() = default;
#include "../include/ClassicPlayer.h"

ClassicPlayer::ClassicPlayer(std::string name_, int points_, int score_, ClassicHand hand_) : StarterPlayer(name_, points_, score_), hand{hand_} {}
ClassicPlayer::ClassicPlayer(const ClassicPlayer &other) : StarterPlayer(other), hand{other.hand} {}
void ClassicPlayer::showHand() { std::cout << hand << calculatePoints() << '\n'; }
int ClassicPlayer::HandSize()
{
    int s = hand.DeckSize();
    return s;
}
void ClassicPlayer::showhiddenHand()
{
    for (int i = 0; i < hand.DeckSize(); i++)
        std::cout << "## ";
    std::cout << '\n';
}
void ClassicPlayer::addToHand(ClassicCard card_) { hand.addToDeck(card_); }
void ClassicPlayer::exchangeHands(ClassicPlayer &other) { hand.exchange(other.hand); }
void ClassicPlayer::returnHand(ClassicHand &deck)
{
    ClassicCard lastcard = hand.lastCard();
    hand.removeLastCard();
    deck.addToDeck(lastcard);
}
void ClassicPlayer::clearHand() { hand.emptyDeck(); }
int ClassicPlayer::calculatePoints()
{
    int aux = points;
    if (aux > 21)
    {
        int n = hand.getnAces();
        while (n)
        {
            aux -= 10;
            n--;
        }
    }
    return aux;
}

void ClassicPlayer::decreaseScore(int betsy) { score = score - betsy; }
ClassicPlayer &ClassicPlayer::operator=(const ClassicPlayer &other)
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
void ClassicPlayer::Display(std::ostream &os) const
{
    os << "Printing all data for NumPlayer with Id: " << Id << '\n';
}
std::ostream &operator<<(std::ostream &os, const ClassicPlayer &player)
{
    player.Display(os);
    os << "Name: " << player.name << '\n';
    os << "Points: " << player.points << '\n';
    os << "Score: " << player.score << '\n';
    os << "Hand: " << player.hand << '\n';
    return os;
}
ClassicPlayer::~ClassicPlayer() = default;
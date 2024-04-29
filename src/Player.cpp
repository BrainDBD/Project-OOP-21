#include "../include/Player.h"

Player::Player(std::string name_, int points_, int score_, Deck hand_, TrumpDeck trumphand_) : name{name_}, points{points_}, score{score_}, hand{hand_}, trumphand{trumphand_} {}
Player::Player(const Player &other) : name{other.name}, points{other.points}, score{other.score}, hand{other.hand} {}
std::string Player::getName() const { return name; }
void Player::addToHand(Card card_) { hand.addToDeck(card_); }
void Player::exchangeHands(Player &other) { hand.exchange(other.hand); }
void Player::returnHand(Deck &deck)
{
    Card lastcard = hand.lastCard();
    hand.removeLastCard();
    deck.addToDeck(lastcard);
}
void Player::showHand() { std::cout << hand; }
void Player::showhiddenHand()
{
    for (int i = 0; i < hand.DeckSize(); i++)
        std::cout << "## ";
    std::cout << '\n';
}
int Player::HandSize()
{
    int s = hand.DeckSize();
    return s;
}
void Player::clearHand() { hand.emptyDeck(); }
void Player::showTrumpHand() { std::cout << trumphand; }
void Player::addToTrumpHand(TrumpCard tcard_) { trumphand.addToTrumpDeck(tcard_); }
int Player::getTrumpHandSize()
{
    int s = trumphand.showTrumpSize();
    return s;
}
void Player::clearTrumpHand() { trumphand.emptyTrumpDeck(); }
int Player::getPoints() const { return points; }
void Player::addtoPoints(int add) { points = points + add; }
void Player::resetPoints() { points = 0; }
int Player::getScore() const { return score; }
void Player::increaseScore(int betsy) { score = score + betsy; }
Player &Player::operator=(const Player &other)
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
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << "Name: " << player.name << '\n';
    os << "Points: " << player.points << '\n';
    os << "Score: " << player.score << '\n';
    os << "Hand: " << player.hand << '\n';
    os << "Trump Cards: " << player.trumphand << '\n';
    return os;
}
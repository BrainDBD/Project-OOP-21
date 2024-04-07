#include "../include/Player.h"

Player::Player(std::string name_, int score_, int hp_ , Deck hand_) : name{name_}, score{score_}, hp{hp_}, hand(hand_) {}
Player::Player(const Player &other) : name{other.name}, score{other.score}, hp{other.hp}, hand{other.hand} {}
std::string Player::getName() const { return name; }
int Player::getScore() const { return score; }
int Player::getHealth() const { return hp; }
void Player::addToHand(Card card_) { hand.addToDeck(card_); }
void Player::showHand() { std::cout << hand; }
void Player::clearHand() { hand.emptyDeck(); }
void Player::resetScore() { score = 0; }
void Player::addtoScore(int add) { score = score + add; }
void Player::lowerHealth(int betsy) { hp = hp - betsy; }
Player &Player::operator=(const Player &other)
{
    if (this != &other)
    {
        name = other.name;
        score = other.score;
        hp = other.hp;
        hand = other.hand;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << "Name: " << player.name << '\n';
    os << "Score: " << player.score << '\n';
    os << "Health: " << player.hp << '\n';
    os << "Hand: " << player.hand << '\n';
    return os;
}
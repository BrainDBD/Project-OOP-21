#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
class Player
{
private:
    std::string name;
    int score;
    int hp;
    Deck hand;

public:
    Player(std::string name_, int score_, int hp_, Deck hand_);
    Player(const Player &other);
    std::string getName() const;
    int getScore() const;
    int getHealth() const;
    void addToHand(Card card_);
    void showHand();
    void clearHand();
    void resetScore();
    void addtoScore(int add);
    void lowerHealth(int betsy);
    Player &operator=(const Player &other);
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
    ~Player() = default;
};
#endif  //PLAYER_H
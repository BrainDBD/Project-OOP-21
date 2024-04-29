#ifndef PLAYER_H
#define PLAYER_H
#include "Deck.h"
#include "TrumpDeck.h"
class Player
{
private:
    std::string name;
    int points;
    int score;
    Deck hand;
    TrumpDeck trumphand;

public:
    Player(std::string name_, int points_, int score_, Deck hand_, TrumpDeck trumphand_);
    Player(const Player &other);
    std::string getName() const;
    void addToHand(Card card_);
    void exchangeHands(Player &other);
    void returnHand(Deck &deck);
    void showHand();
    void showhiddenHand();
    int HandSize();
    void clearHand();
    void showTrumpHand();
    void addToTrumpHand(TrumpCard tcard_);
    int getTrumpHandSize();
    void clearTrumpHand();
    int getPoints() const;
    void addtoPoints(int add);
    void resetPoints();
    int getScore() const;
    void increaseScore(int betsy);
    Player &operator=(const Player &other);
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
    ~Player() = default;
};
#endif  //PLAYER_H
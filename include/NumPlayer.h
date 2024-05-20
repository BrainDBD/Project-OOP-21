#ifndef NPLAYER_H
#define NPLAYER_H

#include <iostream>
#include "StarterPlayer.h"
#include "NumHand.h"

class NumPlayer : public StarterPlayer
{
private:
    NumHand hand;
public:
    NumPlayer() = default;
    NumPlayer(std::string name_ = "Hoffman", int points_ = 0, int score_ = 0, NumHand hand_ = {});
    NumPlayer(const NumPlayer &other);
    void showHand();
    int HandSize();
    void addToHand(NumCard card_);
    void exchangeHands(NumPlayer &other);
    void returnHand(NumHand &deck);
    void clearHand();
    void decreaseScore(int betsy);
    NumPlayer &operator=(const NumPlayer &other);
    void Display(std::ostream &os) const override;
    friend std::ostream &operator<<(std::ostream &os, const NumPlayer &player);
    ~NumPlayer() override;
};

#endif  // NPLAYER_H
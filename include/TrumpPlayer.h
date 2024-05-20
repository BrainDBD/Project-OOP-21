#ifndef TLAYER_H
#define TPLAYER_H

#include <iostream>
#include "StarterPlayer.h"
#include "NumHand.h"
#include "TrumpHand.h"

class TrumpPlayer : public StarterPlayer
{
private:
    NumHand hand;
    TrumpHand trumphand;
public:
    TrumpPlayer() = default;
    TrumpPlayer(const std::string name_ = "Hoffman", int points_ = 0, int score_ = 0, const NumHand hand_ = {}, const TrumpHand trumphand_ = {});
    TrumpPlayer(const TrumpPlayer &other);
    std::string getName() const;
    void showHand();
    int HandSize();
    void showhiddenHand();
    void addToHand(NumCard card_);
    void exchangeHands(TrumpPlayer &other);
    void returnHand(NumHand &deck);
    void clearHand();
    void showTrumpHand();
    void addToTrumpHand(TrumpCard tcard_);
    int getTrumpHandSize();
    void clearTrumpHand();
    TrumpPlayer &operator=(const TrumpPlayer &other);
    void Display(std::ostream &os) const override;
    friend std::ostream &operator<<(std::ostream &os, const TrumpPlayer &player);
    ~TrumpPlayer() override;
};

#endif  // TPLAYER_H
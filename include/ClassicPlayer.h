#ifndef FPLAYER_H
#define FPLAYER_H

#include <iostream>
#include "StarterPlayer.h"
#include "FullHand.h"

class ClassicPlayer : public StarterPlayer
{
private:
    FullHand hand;
public:
ClassicPlayer(std::string name_ = "Hoffman", int points_ = 0, int score_ = 0, FullHand hand_ = {});
ClassicPlayer(const ClassicPlayer &other);
void showHand();
int HandSize();
void showhiddenHand();
void addToHand(FullCard card_);
void exchangeHands(ClassicPlayer &other);
void returnHand(FullHand &deck);
void clearHand();
int calculatePoints();
void decreaseScore(int betsy);
ClassicPlayer &operator=(const ClassicPlayer &other);
void Display(std::ostream &os) const override;
friend std::ostream &operator<<(std::ostream &os, const ClassicPlayer &player);
~ClassicPlayer() override;
};

#endif  // FPLAYER_H
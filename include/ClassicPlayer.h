#ifndef FPLAYER_H
#define FPLAYER_H

#include <iostream>
#include "StarterPlayer.h"
#include "ClassicHand.h"

class ClassicPlayer : public StarterPlayer
{
private:
    ClassicHand hand;
public:
ClassicPlayer(std::string name_ = "Hoffman", int points_ = 0, int score_ = 0, ClassicHand hand_ = {});
ClassicPlayer(const ClassicPlayer &other);
void showHand();
int HandSize();
void showhiddenHand();
void addToHand(ClassicCard card_);
void exchangeHands(ClassicPlayer &other);
void returnHand(ClassicHand &deck);
void clearHand();
int calculatePoints();
void decreaseScore(int betsy);
ClassicPlayer &operator=(const ClassicPlayer &other);
void Display(std::ostream &os) const override;
friend std::ostream &operator<<(std::ostream &os, const ClassicPlayer &player);
~ClassicPlayer() override;
};

#endif  // FPLAYER_H
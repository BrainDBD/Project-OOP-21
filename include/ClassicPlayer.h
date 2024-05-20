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
ClassicPlayer() = default;
ClassicPlayer(std::string name_ = "Hoffman", int points_ = 0, int score_ = 0, FullHand hand_ = {});
ClassicPlayer(const ClassicPlayer &other);
std::string getName() const;
void showHand();
int HandSize();
void showhiddenHand();
void addToHand(FullCard card_);
void exchangeHands(ClassicPlayer &other);
void returnHand(FullHand &deck);
void clearHand();
void addtoPoints(int add);
int calculatePoints();
int getPoints() const;
void resetPoints();
int getScore() const;
void increaseScore(int betsy);
void decreaseScore(int betsy);
ClassicPlayer &operator=(const ClassicPlayer &other);
void Display(std::ostream &os) const override;
friend std::ostream &operator<<(std::ostream &os, const ClassicPlayer &player);
~ClassicPlayer() override;
};

#endif  // FPLAYER_H
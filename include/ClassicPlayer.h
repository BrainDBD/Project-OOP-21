#ifndef FPLAYER_H
#define FPLAYER_H

#include <iostream>
#include "StarterPlayer.h"
#include "ClassicHand.h"
#include "./enums/Roles.h"
#include "Exceptions.h"

class ClassicPlayer : public StarterPlayer
{
private:
    Role role;
    int bet;
    ClassicHand hand;
public:
ClassicPlayer(std::string name_ = "Hoffman", int points_ = 0, int score_ = 0, int bet_ = 0, ClassicHand hand_ = {}, Role role = Role::None);
ClassicPlayer(const ClassicPlayer &other);
Role getRole();
void setRole(Role newRole);
int getBet();
void Bet();
void showHand();
void showDealerHand();
int HandSize();
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
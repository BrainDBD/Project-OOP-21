#ifndef TGAME_H
#define TGAME_H

#include "NumPlayer.h"
#include "NumDeck.h"
#include "TrumpPlayer.h"
#include "TrumpDeck.h"
#include "Exceptions.h"

class TrumpGame
{
private:
    std::vector<TrumpPlayer> players;
    NumDeck maindeck;
    TrumpDeck maintdeck;
public:
    TrumpGame(std::vector<TrumpPlayer> &players_, NumDeck maindeck_, TrumpDeck maintdeck_);
    TrumpGame(const TrumpGame &other);
    void Match(int targetscore);
    void showHand(int playernumber, int &choice);
    void showTrumpHand(int playernumber, int &choice);
    TrumpGame &operator=(const TrumpGame &other);
    friend std::ostream &operator<<(std::ostream &os, const TrumpGame &tgame);
    ~TrumpGame();
};

#endif  //TGAME_H
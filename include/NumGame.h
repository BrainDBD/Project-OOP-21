#ifndef NGAME_H
#define NGAME_H

#include "NumPlayer.h"
#include "NumDeck.h"
#include "Exceptions.h"

class NumGame 
{
private:
    std::vector<NumPlayer> players;
    NumDeck maindeck;
public:
    NumGame(std::vector<NumPlayer> &players_, NumDeck maindeck_);
    NumGame(const NumGame &other);
    void Match(int targetscore);
    NumGame &operator=(const NumGame &other);
    friend std::ostream &operator<<(std::ostream &os, const NumGame &game);
    ~NumGame();
};

#endif  //NGAME_H
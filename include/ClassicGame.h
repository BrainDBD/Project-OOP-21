#ifndef CGAME_H
#define CGAME_H

#include "ClassicPlayer.h"
#include "FullDeck.h"
#include "Exceptions.h"

class ClassicGame
{
private:
    std::vector<ClassicPlayer> players;
    FullDeck maindeck;
public:
    ClassicGame(std::vector<ClassicPlayer> &players_, FullDeck maindeck_);
    ClassicGame(const ClassicGame &other);
    void Match();
    void showHand(int playernumber, int &choice);
    void increaseBet(int &Betsy, int Score);
    ClassicGame &operator=(const ClassicGame &other);
    friend std::ostream &operator<<(std::ostream &os, const ClassicGame &cgame);
    ~ClassicGame();
};


#endif  //CGAME_H
#ifndef CGAME_H
#define CGAME_H

#include "ClassicPlayer.h"
#include "ClassicDeck.h"
#include "Exceptions.h"

class ClassicGame
{
private:
    std::vector<ClassicPlayer> players;
    ClassicDeck maindeck;
public:
    ClassicGame(std::vector<ClassicPlayer> &players_, ClassicDeck maindeck_);
    ClassicGame(const ClassicGame &other);
    void Match();
    void showHand(int playernumber, int &choice);
    void increaseBet(int &Betsy, int Score);
    ClassicGame &operator=(const ClassicGame &other);
    friend std::ostream &operator<<(std::ostream &os, const ClassicGame &cgame);
    ~ClassicGame();
};


#endif  //CGAME_H
#ifndef CGAME_H
#define CGAME_H

#include "ClassicPlayer.h"
#include "ClassicDeck.h"
#include "Exceptions.h"

class ClassicGame 
{
private:
    int playercount;
    std::vector<ClassicPlayer> players;
    ClassicDeck maindeck;
public:
    ClassicGame(int playercount_, std::vector<ClassicPlayer> &players, ClassicDeck maindeck_);
    ClassicGame(const ClassicGame &other);
    bool isGameOver(int targetscore);
    void assignDealer();
    void DisplayScores();
    void CleanUp();
    void BettingTime();
    void Turn(int i, ClassicDeck &gamedeck);
    void showHand(int playernumber, int &choice);
    void showDealerHand(int playernumber, int &choice);
    void Match(int targetscore);
    ClassicGame &operator=(const ClassicGame &other);
    friend std::ostream &operator<<(std::ostream &os, const ClassicGame &cgame);
    ~ClassicGame();
};


#endif  //CGAME_H
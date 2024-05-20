#ifndef SPLAYER_H
#define SPLAYER_H

#include <iostream>
#include "HowToPlay.h"

class StarterPlayer : protected HowToPlay
{
private:
    static int IdGenerator;
protected:
    std::string name;
    int points;
    int score;
    int Id;
    StarterPlayer(std::string name_ = "Hoffman", int points_ = 0, int score_ = 0);
public:
    int getId() const;
    std::string getName() const;
    void addtoPoints(int add);
    int getPoints() const;
    void resetPoints();
    int getScore() const;
    void increaseScore(int betsy);
    virtual ~StarterPlayer();
};

#endif  // SPLAYER_H
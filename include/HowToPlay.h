#ifndef PLAY_H
#define PLAY_H

#include <iostream>

class HowToPlay
{
public:
    virtual int getId() const = 0;
    virtual std::string getName() const = 0;
    virtual void showHand() = 0;
    virtual int HandSize() = 0;
    virtual void clearHand() = 0;
    virtual void addtoPoints(int add) = 0;
    virtual int getPoints() const = 0;
    virtual void resetPoints() = 0;
    virtual int getScore() const = 0;
    virtual void increaseScore(int betsy) = 0;
    virtual void Display(std::ostream &os) const = 0;
};

#endif  // PLAY_H
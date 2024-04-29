#ifndef GAME_H
#define GAME_H
#include "Player.h"
class Game
{
private:
    std::vector<Player> players;
    Deck maindeck;
    TrumpDeck maintdeck;
public:
    Game(std::vector<Player> &players_, Deck maindeck_, TrumpDeck maintdeck_);
    Game(const Game &other);
    void showHand(int playernumber, int &choice);
    void showTrumpHand(int playernumber, int &choice);
    void Match(int targetscore);
    Game &operator=(const Game &other);
    friend std::ostream &operator<<(std::ostream &os, const Game &game);
    ~Game() = default;
};
#endif  //GAME_H
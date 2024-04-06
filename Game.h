#ifndef GAME_H
#define GAME_H
#include "Player.h"
class Game
{
private:
    std::vector<Player> players;
    Deck maindeck;

public:
    Game(std::vector<Player> &players_, Deck maindeck_);
    Game(const Game &other);
    void Match();
    Game &operator=(const Game &other);
    friend std::ostream &operator<<(std::ostream &os, const Game &game);
    ~Game() = default;
};
#endif  //GAME_H
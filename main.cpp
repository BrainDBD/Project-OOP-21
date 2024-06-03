#include "./include/GameMaster.h"

int main()
{
    GameMaster* Lucas = GameMaster::getInstance();
    Lucas->startGame();
    delete Lucas;
    return 0;
}
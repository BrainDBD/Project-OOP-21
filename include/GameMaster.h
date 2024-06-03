#ifndef GAMEMASTER_H
#define GAMEMASTER_H

#include "NumGame.h"
#include "ClassicGame.h"
#include "TrumpGame.h"
#include "./enums/GameType.h"

class GameMaster
{
private:
    static GameMaster* instance;
    GameType currentGameType;
    void* activeGame;
    GameMaster();
public:
    static GameMaster* getInstance();
    void startGame();
    void startNumGame();
    void startClassicGame();
    void startTrumpGame();
    void endCurrentGame();
    void replayGame();
    ~GameMaster();
};

#endif  // GAMEMASTER_H
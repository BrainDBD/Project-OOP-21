#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include "NumPlayer.h"
#include "ClassicPlayer.h"
#include "TrumpPlayer.h"
#include <memory>

class PlayerFactory
{
public:
    std::unique_ptr<NumPlayer> createNPlayer(const std::string& name, int points = 0, int score = 0, NumHand hand = {});
    std::unique_ptr<ClassicPlayer> createCPlayer(const std::string& name, int points = 0, int score = 0, int bet = 0, ClassicHand hand = {}, Role role = Role::None);
    std::unique_ptr<TrumpPlayer> createTPlayer(const std::string& name, int points = 0, int score = 0, NumHand hand = {}, TrumpHand trumphand = {});
    ~PlayerFactory() {}
};

#endif // PLAYERFACTORY_H
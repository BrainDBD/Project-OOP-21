#include "../include/PlayerFactory.h"

std::unique_ptr<NumPlayer> PlayerFactory::createNPlayer(const std::string& name, int points, int score, NumHand hand)
{
    return std::make_unique<NumPlayer>(name, points, score, hand);
}

std::unique_ptr<ClassicPlayer> PlayerFactory::createCPlayer(const std::string& name, int points, int score, int bet, ClassicHand hand, Role role)
{
    return std::make_unique<ClassicPlayer>(name, points, score, bet, hand, role);
}

std::unique_ptr<TrumpPlayer> PlayerFactory::createTPlayer(const std::string& name, int points, int score, NumHand hand, TrumpHand trumphand)
{
    return std::make_unique<TrumpPlayer>(name, points, score, hand, trumphand);
}
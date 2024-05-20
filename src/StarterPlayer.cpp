#include "../include/StarterPlayer.h"

int StarterPlayer::IdGenerator = 1;

StarterPlayer::StarterPlayer(std::string name_, int points_, int score_) : name{name_}, points{points_}, score{score_}, Id{IdGenerator++} {}

int StarterPlayer::getId() const { return Id; }

std::string StarterPlayer::getName() const  { return name; }

void StarterPlayer::addtoPoints(int add) { points = points + add; }

int StarterPlayer::getPoints() const { return points; }

void StarterPlayer::resetPoints() { points = 0; }

int StarterPlayer::getScore() const { return score; }

void StarterPlayer::increaseScore(int betsy) { score = score + betsy; }

StarterPlayer::~StarterPlayer() = default;
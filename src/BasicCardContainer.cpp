#include "../include/BasicCardContainer.h"

BasicCardContainer::BasicCardContainer(const std::vector<AnyCard*> &cards_) : cards{cards_} {}

bool BasicCardContainer::checkEmpty()
{
    if (!cards.empty())
        return 0;
    return 1;
}
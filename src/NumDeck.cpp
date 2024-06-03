#include "../include/NumDeck.h"

NumDeck::NumDeck(const std::vector<AnyCard*> &cards_) : NumCardContainer(cards_) {}
NumDeck::NumDeck(const NumDeck &other) : NumCardContainer(other) {}
NumDeck::NumDeck(NumDeck&& other) noexcept : NumCardContainer()
{
    //cards.swap(other.cards);
    cards = std::move(other.cards);
    other.cards.clear();
}
void NumDeck::createDeck()
{
    for (int type = static_cast<int>(NumType::One); type <= static_cast<int>(NumType::Eleven); ++type)
    {
        NumType cardType = static_cast<NumType>(type);
        AnyCard *auxcard = new NumCard{cardType};
        cards.emplace_back(auxcard);
    }
}
void NumDeck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}
NumCard NumDeck::dealCard()
{
    if (!cards.empty())
    {
        NumCard dealtcard = *dynamic_cast<NumCard*>(cards.back());
        cards.pop_back();
        return dealtcard;
    }
    else
    {
        NumCard errorcard{NumType::Error};
        return errorcard;
    }
}
NumCard NumDeck::drawCard(NumCard card_)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        if (cards[i]->getType() == card_.getType())
        {
            NumCard drawncard = *dynamic_cast<NumCard*>(cards[i]);
            removefromDeck(*dynamic_cast<NumCard*>(cards[i]));
            return drawncard;
        }
    NumCard drawncard = {NumType::Error};
    return drawncard;
}
NumDeck &NumDeck::operator=(const NumDeck &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
NumDeck &NumDeck::operator=(NumDeck&& other) noexcept
{
    if (this != &other)
    {
        for (auto& card : cards)
        {
            delete card;
        }
        cards.clear();
        cards = std::move(other.cards);
        other.cards.clear();
    }
    return *this;
}
void NumDeck::Afisare(std::ostream &os)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " ";
    std::cout << '\n';
}
NumDeck::~NumDeck() = default;
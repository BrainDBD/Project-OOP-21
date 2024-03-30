#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
class Card{
private:
    int value;
public:

    Card();
    Card(const int value_) : value{value_} {}
    int getValue() const { return value; }
    friend std::ostream& operator<<(std::ostream& os, const Card& card) {
        os << "Cardul are valoarea: "<< card.value << "\n";
        return os;
    }
    ~Card() = default;
};
class Deck{
private:
    std::vector<Card> cards;
public:
    Deck();
    Deck(vector<Card> cards_): cards{cards_}{}
    void shuffle(){};
    ~Deck() = default;
};

class TrumpCard{

};
class TrumpDeck{
private:
    std::vector<TrumpCard> tcards;
public:
    TrumpDeck();
    TrumpDeck(vector<TrumpCard> tcards_): tcards{tcards_}{}
    ~TrumpDeck() = default;
};
int main()
{
    Card card{2};
    std::cout<<card;
    return 0;
}
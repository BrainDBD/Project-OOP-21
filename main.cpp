#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
class Card
{
private:
    int rank;

public:
    Card();
    Card(const int rank_) : rank{rank_} {}
    int getValue() const { return rank; }
    friend std::ostream &operator<<(std::ostream &os, const Card &card)
    {
        os << "Cardul are valoarea: " << card.rank << '\n';
        return os;
    }
    ~Card() = default;
};
class Deck
{
private:
    std::vector<Card> cards;

public:
    Deck();
    ~Deck() = default;
};

class TrumpCard{
private:
    std::string type;
};
class TrumpDeck{
private:
    std::vector<TrumpCard> tcards;

public:
    TrumpDeck();
    ~TrumpDeck() = default;
};
class Player
{
private:
    std::string name;
    int score;
    int hp;

public:
    explicit Player(std::string initial_name = "Lucas", int initial_score = 0, int player_hp = 5) : name(std::move(initial_name)), score(initial_score), hp(player_hp) {}

    Player &operator=(const Player &other)
    {
        if (this != &other)
        {
            name = other.name;
            score = other.score;
            hp = other.hp;
        }
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Name: " << player.name << std::endl;
        os << "Score: " << player.score << std::endl;
        os << "Health: " << player.hp << std::endl;
        return os;
    }

    ~Player();
};
int main()
{
    Card card1{1}, card2{2}, card3{3}, card4{4}, card5{5}, card6{6}, card7{7}, card8{8}, card9{9}, card10{10}, card11{11};
    std::cout << card2 << " " << card4;
    return 0;
}
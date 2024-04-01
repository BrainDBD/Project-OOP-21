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
        os << card.rank << " ";
        return os;
    }
    Card &operator=(const Card &other)
    {
        rank = other.rank;
        return *this;
    }
    ~Card() = default;
};
class Deck
{
private:
    std::vector<Card> cards;

public:
    void addToDeck(Card card_)
    {
        cards.push_back(card_);
    }
    /*Deck(vector<Card> cards_): cards{cards_}{}*/
    void shuffleDeck()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(cards.begin(), cards.end(), g);
    }
    Card dealCard()
    {
        if (!cards.empty())
        {
            Card dealtcard = cards.back(); // pretend that the deck is bottom-up
            cards.pop_back();
            return dealtcard;
        }
        else
        {
            Card errorcard{12};
            return errorcard; // will serve as a tell that the deck is empty
        }
    }
    ~Deck() = default;
    friend std::ostream &operator<<(std::ostream &os, const Deck &deck)
    {
        for (unsigned int i = 0; i < deck.cards.size(); i++)
            std::cout << deck.cards[i] << " ";
        return os;
    }
    Deck &operator=(const Deck &other)
    {
        for (unsigned int i = 0; i < other.cards.size(); i++)
            cards[i] = other.cards[i];
        return *this;
    }
};

class TrumpCard
{
private:
    std::string type;
};
class TrumpDeck
{
private:
    std::vector<TrumpCard> tcards;

public:
    void addToDeck(TrumpCard tcard_)
    {
        tcards.push_back(tcard_);
    }
    /*Deck(vector<Card> cards_): cards{cards_}{}*/
    void shuffleDeck()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(tcards.begin(), tcards.end(), g);
    }
    ~TrumpDeck() = default;
    /*friend std::ostream &operator<<(std::ostream &os, const TrumpDeck &tdeck)
    {
        for (unsigned int i = 0; i < tdeck.tcards.size(); i++)
            std::cout << tdeck.tcards[i] << " ";
        return os;
    }*/
    TrumpDeck &operator=(const TrumpDeck &other)
    {
        for (unsigned int i = 0; i < other.tcards.size(); i++)
            tcards[i] = other.tcards[i];
        return *this;
    }
};
class Player
{
private:
    std::string name;
    int score;
    int hp;

public:
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
    friend std::ostream &operator<<(std::ostream &os, const Player &player)
    {
        os << "Name: " << player.name << std::endl;
        os << "Score: " << player.score << std::endl;
        os << "Health: " << player.hp << std::endl;
        return os;
    }

    ~Player();
};
int main()
{
    Card vcard[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Deck deck1;
    for (int i = 0; i < 11; i++)
        deck1.addToDeck(vcard[i]);
    deck1.shuffleDeck();
    std::cout << deck1;
    std::cout << '\n'
              << deck1.dealCard();
    return 0;
}
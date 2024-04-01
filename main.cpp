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
    void addToDeck(Card card_) { cards.push_back(card_); }
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
    friend std::ostream &operator<<(std::ostream &os, const Deck &deck)
    {
        for (unsigned int i = 0; i < deck.cards.size(); i++)
            std::cout << deck.cards[i] << " ";
        std::cout << '\n';
        return os;
    }
    Deck &operator=(const Deck &other)
    {
        for (unsigned int i = 0; i < other.cards.size(); i++)
            cards[i] = other.cards[i];
        return *this;
    }
    ~Deck() = default;
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
    Deck hand;

public:
    Player(std::string name_ = "", int score_ = -99, int hp_ = -1, Deck hand_ = {}) : name{name_}, score{score_}, hp{hp_}, hand(hand_) {}
    Player &operator=(const Player &other)
    {
        if (this != &other)
        {
            name = other.name;
            score = other.score;
            hp = other.hp;
            hand = other.hand;
        }
        return *this;
    }
    std::string getName() const { return name; }
    int getScore() const { return score; }
    int getHealth() const { return hp; }
    void addToHand(Card card_) { hand.addToDeck(card_); }
    void showHand() { std::cout << hand << '\n'; }
    friend std::ostream &operator<<(std::ostream &os, const Player &player)
    {
        os << "Name: " << player.name << '\n';
        os << "Score: " << player.score << '\n';
        os << "Health: " << player.hp << '\n';
        os << "Hand: " << player.hand << '\n';
        return os;
    }
    ~Player() = default;
};
int main()
{
    Card vcard[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Deck deck1;
    for (int i = 0; i < 10; i++)
        deck1.addToDeck(vcard[i]);
    deck1.shuffleDeck();
    std::cout << deck1;
    Player jucator1{"Ioan", 100, 5, deck1};
    Card card2 = {11};
    jucator1.addToHand(card2);
    jucator1.showHand();
    return 0;
}
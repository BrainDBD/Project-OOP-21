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
    Deck(const std::vector<Card> &cards_ = {}) : cards{cards_} {}
    Deck(const Deck &other) : cards{other.cards} {}
    void addToDeck(Card card_) { cards.push_back(card_); }
    void createDeck(Deck &deck)
    {
        Card vcard[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        for (int i = 0; i < 11; i++)
            deck.addToDeck(vcard[i]);
    }
    void emptyDeck()
    {
        while (!cards.empty())
        {
            Card dealtcard = cards.back();
            cards.pop_back();
        }
    }
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
    int type;

public:
    TrumpCard();
    TrumpCard(const int type_) : type{type_} {}
    int getValue() const { return type; }
    friend std::ostream &operator<<(std::ostream &os, const TrumpCard &card)
    {
        os << card.type << " ";
        return os;
    }
    TrumpCard &operator=(const TrumpCard &other)
    {
        type = other.type;
        return *this;
    }
    ~TrumpCard() = default;
};
class Player
{
private:
    std::string name;
    int score;
    int hp;
    Deck hand;

public:
    Player(std::string name_ = "", int score_ = -1, int hp_ = -1, Deck hand_ = {}) : name{name_}, score{score_}, hp{hp_}, hand(hand_) {}
    Player(const Player &other) : name{other.name}, score{other.score}, hp{other.hp}, hand{other.hand} {}
    std::string getName() const { return name; }
    int getScore() const { return score; }
    int getHealth() const { return hp; }
    void addToHand(Card card_) { hand.addToDeck(card_); }
    void showHand() { std::cout << hand; }
    void clearHand() { hand.emptyDeck(); }
    void resetScore() { score = 0; }
    void addtoScore(int add) { score = score + add; }
    void lowerHealth() { hp = hp - 1; }
    void damageHealth(int betsy) { hp = hp - betsy; }
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
class Game
{
private:
    std::vector<Player> players;
    Deck maindeck;

public:
    Game(std::vector<Player> &players_, Deck maindeck_) : players{players_}, maindeck{maindeck_} {}
    void Match()
    {
        bool gaming = true;
        int round = 1;
        while (gaming && (players[0].getHealth() > 0 && players[1].getHealth() > 0))
        {
            std::cout << "\n\n"
                      << "Round " << round << " begins."
                      << "\n";
            std::cout << players[0].getName() << " has " << players[0].getHealth() << " health." << '\n';
            std::cout << players[1].getName() << " has " << players[1].getHealth() << " health." << '\n';
            players[0].clearHand();
            players[0].resetScore();
            players[1].clearHand();
            players[1].resetScore();
            Deck rounddeck = maindeck;
            rounddeck.shuffleDeck();
            int staying = 0;
            int choice;
            int target = 21;
            while (staying < 2)
            {
                std::cout << players[0].getName() << ", it's your turn."
                          << "\n\n";
                std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2]"
                          << "\n\n";
                std::cin >> choice;
                if (choice == 2)
                {
                    std::cout << '\n'
                              << "Your current hand: ";
                    players[0].showHand();
                    std::cout << "Opponent's current hand: ";
                    players[1].showHand();
                    std::cout << "\n\n";
                    std::cout << "Available actions: Stay[0], Hit[1]"
                              << "\n\n";
                    std::cin >> choice;
                    std::cout << '\n';
                }
                if (choice == 1)
                {
                    Card hitcard = rounddeck.dealCard();
                    if (hitcard.getValue() == 12)
                    {
                        std::cout << "No more cards in the deck!"
                                  << "\n\n";
                        if (staying < 2)
                            staying++;
                    }
                    else
                    {
                        players[0].addToHand(hitcard);
                        players[0].addtoScore(hitcard.getValue());
                        std::cout << players[0].getName() << ", you drew the " << hitcard.getValue() << " card."
                                  << "\n\n";
                        if (staying > 0)
                            staying--;
                    }
                }
                else if (choice == 0)
                {
                    if (staying < 2)
                        staying++;
                }
                else
                {
                    gaming = false;
                    break;
                }
                std::cout << players[1].getName() << ", it's your turn."
                          << "\n\n";
                std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2]"
                          << "\n\n";
                std::cin >> choice;
                std::cout << '\n';
                if (choice == 2)
                {
                    std::cout << '\n'
                              << "Your current hand: ";
                    players[1].showHand();
                    std::cout << "Opponent's current hand: ";
                    players[0].showHand();
                    std::cout << "Available actions: Stay[0], Hit[1]"
                              << "\n\n";
                    std::cin >> choice;
                }
                if (choice == 1)
                {
                    Card hitcard = rounddeck.dealCard();
                    if (hitcard.getValue() == 12)
                    {
                        std::cout << "No more cards in the deck!"
                                  << "\n\n";
                        if (staying < 2)
                            staying++;
                    }
                    else
                    {
                        players[1].addToHand(hitcard);
                        players[1].addtoScore(hitcard.getValue());
                        std::cout << players[1].getName() << ", you drew the " << hitcard.getValue() << " card."
                                  << "\n\n";
                        if (staying > 0)
                            staying--;
                    }
                }
                else if (choice == 0)
                {
                    if (staying < 2)
                        staying++;
                }
                else
                {
                    gaming = false;
                    break;
                }
            }
            int s1, s2;
            s1 = players[0].getScore();
            s2 = players[1].getScore();
            std::cout << players[0].getName() << " has " << s1 << " total points, while " << players[1].getName() << " has " << s2 << " total points"
                      << "\n\n";
            if (s1 > s2 && s1 <= 21)
            {
                std::cout << players[0].getName() << " wins this round!"
                          << "\n\n";
                players[1].lowerHealth();
            }
            else if (s2 > target && s1 <= target)
            {
                std::cout << players[0].getName() << " wins this round!"
                          << "\n\n";
                players[1].lowerHealth();
            }
            else if (s2 > target && s1 > target && s1 < s2)
            {
                std::cout << players[0].getName() << " wins this round!"
                          << "\n\n";
                players[1].lowerHealth();
            }
            else if (s1 == s2)
            {
                std::cout << "It's a draw!"
                          << "\n\n";
            }
            else
            {
                std::cout << players[1].getName() << " wins this round!"
                          << "\n\n";
                players[0].lowerHealth();
            }
            if (players[0].getHealth() * players[1].getHealth() > 0)
            {
                std::cout << "Continue? Yes[1], No[0] ";
                std::cin >> choice;
                if (choice == 0)
                    gaming = 0;
            }
            round++;
        }
        if (players[0].getHealth() > players[1].getHealth())
            std::cout << players[0].getName() << " wins the match!"
                      << "\n\n";
        else if (players[0].getHealth() < players[1].getHealth())
            std::cout << players[1].getName() << " wins the match!"
                      << "\n\n";
        else
            std::cout << "It's a tie!"
                      << "\n\n";
    }
    ~Game() = default;
};

int main()
{
    int n;
    std::vector<Player> jucatori;
    Card vcard[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    Deck deck1;
    for (int i = 0; i < 11; i++)
        deck1.addToDeck(vcard[i]);
    deck1.shuffleDeck();
    n = 2;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        Player jucatornou{nume, 0, 1, deck1};
        jucatori.push_back(jucatornou);
    }
    Game joc1 = {jucatori, deck1};
    joc1.Match();

    return 0;
}
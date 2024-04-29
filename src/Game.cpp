#include "../include/Game.h"

Game::Game(std::vector<Player> &players_, Deck maindeck_, TrumpDeck maintdeck_) : players{players_}, maindeck{maindeck_}, maintdeck{maintdeck_} {}
Game::Game(const Game &other) : players{other.players}, maindeck{other.maindeck}, maintdeck{other.maintdeck} {};
void Game::showHand(int playernumber, int &choice)
{
    std::cout << "Your current hand: ";
    players[playernumber].showHand();
    std::cout << players[1].getName() << "'s current hand: ";
    players[abs(playernumber - 1)].showHand();
    std::cout << "\n\n";
    std::cout << "Available actions: Stay[0], Hit[1], Show Trump Cards[3]"
                << "\n\n";
    std::cin >> choice;
    while (choice != 0 && choice != 1 && choice != 3)
    {
        std::cout << "Invalid input. Available actions: Stay[0], Hit[1], Show Trump Cards[3]";
        std::cin >> choice;
    }
    std::cout << '\n';
    if (choice == 3)
        showTrumpHand(playernumber, choice);
}
void Game::showTrumpHand(int playernumber, int &choice)
{
    std::cout << "Your Trump Cards: ";
    players[playernumber].showTrumpHand();
    std::cout << "Available actions: Stay[0], Hit[1], Show Hand[2]"
                << "\n\n";
    std::cin >> choice;
    while (choice != 0 && choice != 1 && choice != 2)
    {
        std::cout << "Invalid input. Available actions: Stay[0], Hit[1], Show Hand[2]";
        std::cin >> choice;
    }
    std::cout << '\n';
    if (choice == 2)
        showHand(playernumber, choice);
}
void Game::Match(int targetscore)
{
    bool gaming = true;
    int round = 1;
    int bet = 1;
    int staying = 0;
    int choice;
    int target = 21;
    players[0].clearTrumpHand();
    players[1].clearTrumpHand();
    TrumpDeck roundtdeck = maintdeck;
    roundtdeck.shuffleTrumpDeck();
    while (gaming && players[0].getScore() < targetscore && players[1].getScore() < targetscore)
    {
        std::cout << "\n\n"
                    << "Round " << round << " begins."
                    << "\n\n";
        std::cout << players[0].getName() << "'s Score: " << players[0].getScore() << '\n';
        std::cout << players[1].getName() << "'s Score: " << players[1].getScore()
                    << "\n\n";
        players[0].clearHand();
        players[0].resetPoints();
        players[1].clearHand();
        players[1].resetPoints();
        Deck rounddeck = maindeck;
        rounddeck.shuffleDeck();
        staying = 0;
        target = 21;
        Card hitcard = rounddeck.dealCard();
        players[0].addToHand(hitcard);
        players[0].addtoPoints(hitcard.getValue());
        if (players[0].getTrumpHandSize() < 5)
        {
            if (roundtdeck.checkEmpty() == 1)
            {
                roundtdeck = maintdeck;
                roundtdeck.shuffleTrumpDeck();
            }
            TrumpCard hittcard = roundtdeck.dealTrumpCard();
            players[0].addToTrumpHand(hittcard);
            std::cout << players[0].getName() << ", you drew the " << hitcard.getValue() << " card and " << hittcard.getString() << "." << '\n';
        }
        else
            std::cout << players[0].getName() << ", you drew the " << hitcard.getValue() << " card." << '\n';
        hitcard = rounddeck.dealCard();
        players[1].addToHand(hitcard);
        players[1].addtoPoints(hitcard.getValue());
        if (players[1].getTrumpHandSize() < 5)
        {
            if (roundtdeck.checkEmpty() == 1)
            {
                roundtdeck = maintdeck;
                roundtdeck.shuffleTrumpDeck();
            }
            TrumpCard hittcard = roundtdeck.dealTrumpCard();
            players[1].addToTrumpHand(hittcard);
            std::cout << players[1].getName() << ", you drew the " << hitcard.getValue() << " card and " << hittcard.getString() << "." << '\n';
        }
        else
            std::cout << players[1].getName() << ", you drew the " << hitcard.getValue() << " card." << '\n';
        while (staying < 2)
        {
            std::cout << '\n'
                        << players[0].getName() << ", it's your turn."
                        << "\n\n";
            std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2], Show Trump Cards[3] "
                        << "\n\n";
            std::cin >> choice;
            while (choice != 0 && choice != 1 && choice != 2 && choice != 3)
            {
                std::cout << "Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2], Show Trump Cards[3] ";
                std::cin >> choice;
            }
            std::cout << '\n';
            if (choice == 2)
                showHand(0, choice);
            if (choice == 3)
                showTrumpHand(0, choice);
            if (choice == 1)
            {
                hitcard = rounddeck.dealCard();
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
                    players[0].addtoPoints(hitcard.getValue());
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
            std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2], Show Trump Cards[3] "
                        << "\n\n";
            std::cin >> choice;
            while (choice != 0 && choice != 1 && choice != 2 && choice != 3)
            {
                std::cout << "Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2], Show Trump Cards[3] ";
                std::cin >> choice;
            }
            std::cout << '\n';
            if (choice == 2)
                showHand(1, choice);
            if (choice == 3)
                showTrumpHand(1, choice);
            if (choice == 1)
            {
                hitcard = rounddeck.dealCard();
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
                    players[1].addtoPoints(hitcard.getValue());
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
        s1 = players[0].getPoints();
        s2 = players[1].getPoints();
        std::cout << players[0].getName() << " has " << s1 << " total points, while " << players[1].getName() << " has " << s2 << " total points"
                    << "\n\n";
        if (s1 > s2 && s1 <= target)
        {
            std::cout << players[0].getName() << " wins this round!"
                        << "\n\n";
            players[0].increaseScore(bet);
        }
        else if (s2 > target && s1 <= target)
        {
            std::cout << players[0].getName() << " wins this round!"
                        << "\n\n";
            players[0].increaseScore(bet);
        }
        else if (s2 > target && s1 > target && s1 < s2)
        {
            std::cout << players[0].getName() << " wins this round!"
                        << "\n\n";
            players[0].increaseScore(bet);
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
            players[1].increaseScore(bet);
        }
        if (players[0].getScore() < targetscore && players[1].getScore() < targetscore)
        {
            std::cout << "Continue? Yes[1], No[0] ";
            std::cin >> choice;
            while (choice != 0 && choice != 1)
            {
                std::cout << "Invalid input. Choose [1] for Yes and [0] for No. ";
                std::cin >> choice;
            }
            if (choice == 0)
                gaming = 0;
        }
        round++;
    }
    std::cout<<'\n';
    if (players[0].getScore() > players[1].getScore())
        std::cout << players[0].getName() << " wins the match!"
                    << "\n\n";
    else if (players[0].getScore() < players[1].getScore())
        std::cout << players[1].getName() << " wins the match!"
                    << "\n\n";
    else
        std::cout << "It's a tie!"
                    << "\n\n";
}

Game &Game::operator=(const Game &other)
{
    if (this != &other)
    {
        players = other.players;
        maindeck = other.maindeck;
        maintdeck = other.maintdeck;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const Game &game)
{
    for (unsigned int i = 0; i < game.players.size(); i++)
        std::cout << game.players[i] << " ";
    std::cout << '\n';
    return os;
}

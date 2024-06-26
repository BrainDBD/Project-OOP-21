#include "../include/NumGame.h"

NumGame::NumGame(std::vector<NumPlayer> &players_, NumDeck maindeck_) : players{players_}, maindeck{maindeck_} {}
NumGame::NumGame(const NumGame &other) : players{other.players}, maindeck{other.maindeck} {};
void NumGame::Match(int targetscore)
{
    bool gaming = true;
    int round = 1;
    int bet = 1;
    int staying = 0;
    int choice;
    int target = 21;
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
        NumDeck* rounddeck = maindeck.clone();
        rounddeck->shuffleDeck();
        staying = 0;
        target = 21;
        NumCard hitcard = rounddeck->dealCard();
        players[0].addToHand(hitcard);
        players[0].addtoPoints(hitcard.getValue());
        std::cout << players[0].getName() << ", you drew the " << hitcard.getType() << " card." << '\n';
        hitcard = rounddeck->dealCard();
        players[1].addToHand(hitcard);
        players[1].addtoPoints(hitcard.getValue());
        std::cout << players[1].getName() << ", you drew the " << hitcard.getType() << " card." << '\n';
        while (staying < 2)
        {
            std::cout << '\n'
                        << players[0].getName() << ", it's your turn."
                        << "\n\n";
            std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2] "
                        << "\n\n";
            std::cin >> choice;
            while (choice != 0 && choice != 1 && choice != 2)
            {
                std::cout << "Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2] ";
                std::cin >> choice;
            }
            std::cout << '\n';
            if (choice == 2)
            {
                std::cout << '\n'
                            << players[0].getName() << "'s current hand: ";
                players[0].showHand();
                std::cout << players[1].getName() << "'s current hand: ";
                players[1].showHand();
                std::cout << "\n\n";
                std::cout << "Available actions: Stay[0], Hit[1]"
                            << "\n\n";
                std::cin >> choice;
                std::cout << '\n';
            }
            if (choice == 1)
            {
                hitcard = rounddeck->dealCard();
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
                    std::cout << players[0].getName() << ", you drew the " << hitcard.getType() << " card."
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
            std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2] "
                        << "\n\n";
            std::cin >> choice;
            while (choice != 0 && choice != 1 && choice != 2)
            {
                std::cout << "Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2] ";
                std::cin >> choice;
            }
            std::cout << '\n';
            if (choice == 2)
            {
                std::cout << '\n'
                            << players[0].getName() << "'s current hand: ";
                players[0].showHand();
                std::cout << players[1].getName() << "'s current hand: ";
                players[1].showHand();
                std::cout << "\n\n";
                std::cout << "Available actions: Stay[0], Hit[1]"
                            << "\n\n";
                std::cin >> choice;
                std::cout << '\n';
            }
            if (choice == 1)
            {
                hitcard = rounddeck->dealCard();
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
                    std::cout << players[1].getName() << ", you drew the " << hitcard.getType() << " card."
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
            bool ok = false;
            while (!ok)
            {   
                ok = true;
                try
                {
                    if (!(std::cin >> choice))
                    {
                        ok = false;
                        throw std::invalid_argument("Invalid input. Not an integer.");
                    }
                    if (choice != 0 && choice != 1)
                    {
                        ok = false;
                        throw InvalidChoice("Invalid input. Choose Yes[1] or No[0] ");
                    }
                }
                catch (const AnyException &e)
                {
                    std::cerr << e.what() << '\n';
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << e.what() << '\n';
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }
            if (choice == 0)
                gaming = 0;
        }
        round++;
    }
    std::cout << '\n';
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
NumGame &NumGame::operator=(const NumGame &other)
{
    if (this != &other)
    {
        players = other.players;
        maindeck = other.maindeck;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const NumGame &game)
{
    std::for_each(game.players.begin(), game.players.end(), [](const auto &player)
    {
        std::cout << player << " ";
    });
    std::cout << '\n';
    return os;
}
NumGame::~NumGame() = default;
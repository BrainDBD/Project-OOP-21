#include "../include/ClassicGame.h"

ClassicGame::ClassicGame(int playercount_, std::vector<ClassicPlayer> &players_, ClassicDeck maindeck_) : playercount{playercount_}, players{players_}, maindeck{maindeck_} {}
ClassicGame::ClassicGame(const ClassicGame &other) : playercount{other.playercount}, players{other.players}, maindeck{other.maindeck} {};
bool ClassicGame::isGameOver(int targetscore)
{
    bool ok = false;
    int i = 0;
    int p = 0;
    while (!ok && i < playercount)
    {
        int aux = players[i].getScore();
        if (aux >= targetscore)
        {
            ok = true;
            break;
        }
        if (aux <= 0)
            p++;
        i++;
    }
    if (p == playercount)
        ok = true;
    return ok;
}
void ClassicGame::assignDealer()
{
    for (int i = 0; i < playercount; i++)
    {
        players[i].setRole(Role::Player);
    }
    ClassicPlayer dealer = {"Dealer", 0, 2000, 0, {}, Role::Dealer};
    players.push_back(dealer);
}
void ClassicGame::DisplayScores()
{
    for (int i = 0; i < playercount; i++)
        std::cout << players[i].getName() << "'s Score: " << players[i].getScore() << '\n';
    std::cout << "\n\n";
}
void ClassicGame::CleanUp()
{
    for (int i = 0; i <= playercount; i++)
    {
        players[i].clearHand();
        players[i].resetPoints();
    }
}
void ClassicGame::BettingTime()
{
    for (int i = 0; i < playercount; i++)
        if (players[i].getScore() > 0)
            players[i].Bet();
}
void ClassicGame::Turn(int i, ClassicDeck &gamedeck)
{
    std::cout << '\n'
              << players[i].getName() << ", it's your turn."
              << "\n\n";
    bool staying = false;
    int choice;
    while (!staying && players[i].calculatePoints() <= 21)
    {
        std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2], Show Dealer's Hand[3] ";
        choice = -1;
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
                if (choice != 0 && choice != 1 && choice != 2 && choice != 3)
                {
                    ok = false;
                    throw InvalidChoice("Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2], Show Dealer's Hand[3] ");
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
        std::cout << '\n';
        if (choice == 3)
            showDealerHand(i, choice);
        if (choice == 2)
            showHand(i, choice);
        if (choice == 1)
        {
            ClassicCard hitcard = gamedeck.dealCard();
            players[i].addToHand(hitcard);
            players[i].addtoPoints(hitcard.getValue());
            std::cout << players[i].getName() << ", you drew the " << hitcard.getType() << " of " << hitcard.getSuit() << " card."
                      << "\n";
        }
        else if (choice == 0)
            staying = true;
    }
}
void ClassicGame::showHand(int playernumber, int &choice)
{
    std::cout << "Your current hand: ";
    players[playernumber].showHand();
    std::cout << "\n\n";
    std::cout << "Available actions: Stay[0], Hit[1], Show Dealer's Hand[3]"
              << "\n\n";
    choice = -1;
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
            if (choice != 0 && choice != 1 && choice != 3)
            {
                ok = false;
                throw InvalidChoice("Invalid input. Available actions: Stay[0], Hit[1], Show Dealer's Hand[3]");
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
    std::cout << '\n';
    if (choice == 3)
        showDealerHand(playernumber, choice);
}
void ClassicGame::showDealerHand(int playernumber, int &choice)
{
    std::cout << "Dealer's hand: ";
    players[playercount].showDealerHand();
    std::cout << "Available actions: Stay[0], Hit[1], Show Hand[2]"
              << "\n\n";
    choice = -1;
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
            if (choice != 0 && choice != 1 && choice != 2)
            {
                ok = false;
                throw InvalidChoice("Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2]");
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
    std::cout << '\n';
    if (choice == 2)
        showHand(playernumber, choice);
}
void ClassicGame::Match(int targetscore)
{
    bool gaming = true;
    bool ok;
    int round = 1;
    int staying = 0;
    int choice;
    int target = 21;
    ClassicDeck rounddeck = maindeck;
    assignDealer();
    while (!isGameOver(targetscore) && gaming)
    {
        std::cout << "\n\n"
                  << "Round " << round << " begins."
                  << "\n\n";
        DisplayScores();
        CleanUp();
        rounddeck.shuffleDeck();
        staying = 0;
        target = 21;
        BettingTime();
        ClassicCard hitcard;
        for (int i = 0; i < playercount; i++)
        {
            if (players[i].getScore() > 0)
                for (int k = 0; k < 2; k++)
                {
                    hitcard = rounddeck.dealCard();
                    players[i].addToHand(hitcard);
                    players[i].addtoPoints(hitcard.getValue());
                    std::cout << players[i].getName() << ", you drew the " << hitcard.getType() << " of " << hitcard.getSuit() << " card." << '\n'
                              << '\n';
                }
        }
        for (int k = 0; k < 2; k++)
        {
            hitcard = rounddeck.dealCard();
            players[playercount].addToHand(hitcard);
            players[playercount].addtoPoints(hitcard.getValue());
        }
        for (int i = 0; i < playercount; i++)
            if (players[i].getScore() > 0)
                Turn(i, rounddeck);
        while (players[playercount].calculatePoints() < 17)
        {
            hitcard = rounddeck.dealCard();
            players[playercount].addToHand(hitcard);
            players[playercount].addtoPoints(hitcard.getValue());
        }
        std::cout << "Dealer's hand: ";
        players[playercount].showHand();
        for (int i = 0; i < playercount; i++)
            if (players[i].getScore() > 0)
            {
                std::cout << players[i].getName() << " has " << players[i].calculatePoints() << " total points, while " << players[playercount].getName() << " has " << players[playercount].calculatePoints() << " total points"
                          << "\n\n";
                if (players[playercount].calculatePoints() > 21 && players[i].calculatePoints() > 21 && players[playercount].calculatePoints() > players[i].calculatePoints())
                {
                    std::cout << players[i].getName() << " wins." << '\n';
                    players[i].increaseScore(players[i].getBet());
                }
                else if (players[playercount].calculatePoints() > 21 && players[i].calculatePoints() <= 21 )
                {
                    std::cout << players[i].getName() << " wins." << '\n';
                    players[i].increaseScore(players[i].getBet());
                }
                else if (players[i].calculatePoints() > 21 && players[playercount].calculatePoints() <= 21)
                {
                    std::cout << players[i].getName() << " loses." << '\n';
                    players[i].increaseScore(players[i].getBet());
                }
                else if (players[i].calculatePoints() < players[playercount].calculatePoints())
                {
                    std::cout << players[i].getName() << " loses." << '\n';
                    players[i].decreaseScore(players[i].getBet());
                }
                else
                    std::cout << players[i].getName() << " is tied with the Dealer" << '\n';
                std::cout << '\n';
            }
        round++;
    }
    std::cout << "\n\n";
    for (int i = 0; i < playercount; i++)
        if (players[i].getScore() > targetscore)
            std::cout << players[i].getName() << " is a winner!" << '\n';
}
ClassicGame &ClassicGame::operator=(const ClassicGame &other)
{
    if (this != &other)
    {
        players = other.players;
        maindeck = other.maindeck;
    }
    return *this;
}
std::ostream &operator<<(std::ostream &os, const ClassicGame &cgame)
{
    for (unsigned int i = 0; i < cgame.players.size(); i++)
        std::cout << cgame.players[i] << " ";
    std::cout << '\n';
    return os;
}
ClassicGame::~ClassicGame() = default;
#include "Game.h"

    Game::Game(std::vector<Player> &players_, Deck maindeck_) : players{players_}, maindeck{maindeck_} {}
    Game::Game(const Game &other):players{other.players},maindeck{other.maindeck}{};
    void Game::Match()
    {
        bool gaming = true;
        int round = 1;
        int bet = 1;
        int staying = 0;
        int choice;
        int target = 21;
        while (gaming && (players[0].getHealth() > 0 && players[1].getHealth() > 0))
        {
            std::cout << "\n\n"
                      << "Round " << round << " begins."
                      << "\n";
            std::cout << players[0].getName() << " has " << players[0].getHealth() << " health." << '\n';
            std::cout << players[1].getName() << " has " << players[1].getHealth() << " health." << "\n\n";
            players[0].clearHand();
            players[0].resetScore();
            players[1].clearHand();
            players[1].resetScore();
            Deck rounddeck = maindeck;
            rounddeck.shuffleDeck();
            staying = 0;
            target = 21;
            while (staying < 2)
            {
                std::cout << players[0].getName() << ", it's your turn."
                          << "\n\n";
                std::cout << "Available actions: Stay[0], Hit[1], Show Hands[2]"
                          << "\n\n";
                std::cin >> choice;
                while(choice!=0 && choice!=1 && choice!=2)
                {
                    std::cout<<"Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2] ";
                    std::cin>>choice;
                }
                std::cout << '\n';
                if (choice == 2)
                {
                    std::cout << '\n'
                              << players[0].getName()<<"'s current hand: ";
                    players[0].showHand();
                    std::cout << players[1].getName()<<"'s current hand: ";
                    players[1].showHand();
                    std::cout << "\n\n";
                    std::cout << "Available actions: Stay[0], Hit[1]"
                              << "\n\n";
                    std::cin >> choice;
                    while(choice!=0 && choice!=1)
                {
                    std::cout<<"Invalid input. Available actions: Stay[0], Hit[1] ";
                    std::cin>>choice;
                }
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
                while(choice!=0 && choice!=1 && choice!=2)
                {
                    std::cout<<"Invalid input. Available actions: Stay[0], Hit[1], Show Hands[2] ";
                    std::cin>>choice;
                }
                std::cout << '\n';
                if (choice == 2)
                {
                    std::cout << '\n'
                              << players[1].getName()<<"'s current hand: ";
                    players[1].showHand();
                    std::cout << players[0].getName()<<"'s current hand: ";
                    players[0].showHand();
                    std::cout << "\n\n";
                    std::cout << "Available actions: Stay[0], Hit[1]"
                              << "\n\n";
                    std::cin >> choice;
                    while(choice!=0 && choice!=1)
                {
                    std::cout<<"Invalid input. Available actions: Stay[0], Hit[1] ";
                    std::cin>>choice;
                }
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
                players[1].lowerHealth(bet);
            }
            else if (s2 > target && s1 <= target)
            {
                std::cout << players[0].getName() << " wins this round!"
                          << "\n\n";
                players[1].lowerHealth(bet);
            }
            else if (s2 > target && s1 > target && s1 < s2)
            {
                std::cout << players[0].getName() << " wins this round!"
                          << "\n\n";
                players[1].lowerHealth(bet);
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
                players[0].lowerHealth(bet);
            }
            if (players[0].getHealth() * players[1].getHealth() > 0)
            {
                std::cout << "Continue? Yes[1], No[0] ";
                std::cin >> choice;
            while(choice!=0 && choice!=1)
            {
                std::cout<<"Invalid input. Choose [1] for Yes and [0] for No. ";
                std::cin>>choice;
            }
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
    Game &Game::operator=(const Game &other)
    {
        if (this != &other)
        {
            players = other.players;
            maindeck = other.maindeck;
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

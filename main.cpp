#include "./include/Game.h"

void newMatch()
{
    Deck newhand;
    newhand.createDeck(newhand);
    std::vector<Player> jucatori;
    int n = 2;
    int health;
    std::cout << "How much health do the players have? ";
    std::cin >> health;
    while (health < 1)
    {
        std::cout << "Invalid health input. Give a value that is at least 1. ";
        std::cin >> health;
    }
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        Player jucatornou{nume, 0, health, newhand};
        jucatori.push_back(jucatornou);
    }
    Game joc = {jucatori, newhand};
    joc.Match();
    std::cout << "Play again? Yes[1], No[0] ";
    std::cin >> n;
    while (n != 0 && n != 1)
    {
        std::cout << "Invalid input. Choose [1] for Yes and [0] for No. ";
        std::cin >> n;
    }
    while (n == 1)
    {
        Game newjoc = {jucatori, newhand};
        newjoc.Match();
        std::cout << "Play again? Yes[1], No[0] ";
        std::cin >> n;
        while (n != 0 && n != 1)
        {
            std::cout << "Invalid input. Choose [1] for Yes and [0] for No. ";
            std::cin >> n;
        }
    }
}
int main()
{
    newMatch();
    return 0;
}
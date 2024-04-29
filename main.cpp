#include "./include/Game.h"

void newMatch()
{
    Deck newhand;
    newhand.createDeck();
    TrumpDeck newthand;
    newthand.createTrumpDeck();
    newthand.shuffleTrumpDeck();
    std::vector<Player> jucatori;
    int n = 2;
    int maxscore;
    std::cout << "What score must a Player have to win? ";
    std::cin >> maxscore;
    while (maxscore < 1)
    {
        std::cout << "Invalid score input. Give a value that is at least 1. ";
        std::cin >> maxscore;
    }
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        Player jucatornou{nume, 0, 0, newhand, newthand};
        jucatori.push_back(jucatornou);
    }
    Game joc = {jucatori, newhand, newthand};
    joc.Match(maxscore);
    std::cout << "Play again? Yes[1], No[0] ";
    std::cin >> n;
    while (n != 0 && n != 1)
    {
        std::cout << "Invalid input. Choose [1] for Yes and [0] for No. ";
        std::cin >> n;
    }
    while (n == 1)
    {
        Game newjoc = {jucatori, newhand, newthand};
        newjoc.Match(maxscore);
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
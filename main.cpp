#include "Game.h"

int main()
{
    int n;
    std::vector<Player> jucatori;
    Deck deck1;
    deck1.createDeck(deck1);
    n = 2;
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        Player jucatornou{nume, 0, 5, deck1};
        jucatori.push_back(jucatornou);
    }
    Game joc1 = {jucatori, deck1};
    joc1.Match();

    /*Deck deck1,deck2;
    deck1.createDeck(deck1);
    deck2.createDeck(deck2);
    deck1.shuffleDeck();
    deck2.shuffleDeck();
    std::cout<<deck1<<'\n'<<deck2<<'\n';
    Player jucatornou{"Joe", 10, 5, deck1};
    Player jucatornou2{"Bill", 0, 5, deck2};
    jucatornou.swapHand(jucatornou2);
    jucatornou.showHand();
    /*
    Card vcard[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Deck deck1;
    for (int i = 0; i < 10; i++)
        deck1.addToDeck(vcard[i]);
    deck1.shuffleDeck();
    std::cout << deck1;
    Player jucator1{"Ioan", 100, 5, deck1};
    Card card2 = {11};
    jucator1.addToHand(card2);
    std::cout<<jucator1;*/
    return 0;
}
#include "./include/NumGame.h"
#include "./include/ClassicGame.h"
#include "./include/TrumpGame.h"

void newTrumpMatch()
{
    NumHand newhand;
    TrumpHand newthand;
    std::vector<TrumpPlayer> jucatori;
    int n = 2;
    int maxscore;
    std::cout << "What score must a Player have to win? ";
    bool ok = false;
    while (!ok)
    {   
        ok = true;
        try
        {
            if (!(std::cin >> maxscore))
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Not an integer.");
            }
            if (maxscore < 1)
            {
                ok = false;
                throw std::out_of_range("Invalid score input. Give a value that is at least 1. ");
            }
        }
        catch (const std::out_of_range &e)
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
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        TrumpPlayer jucatornou{nume, 0, 0, newhand, newthand};
        jucatori.push_back(jucatornou);
    }
    NumDeck newdeck;
    TrumpDeck newtdeck;
    newdeck.createDeck();
    newtdeck.createDeck();
    TrumpGame joc = {jucatori, newdeck, newtdeck};
    joc.Match(maxscore);
    std::cout << "Play again? Yes[1], No[0] ";
    ok = false;
    while (!ok)
    {   
        ok = true;
        try
        {
            if (!(std::cin >> n))
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Not an integer.");
            }
            if (n != 0 && n != 1)
            {
                ok = false;
                throw InvalidChoice("Invalid input. Choose [1] for Yes and [0] for No. ");
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
    while (n == 1)
    {
        TrumpGame newjoc = {jucatori, newdeck, newtdeck};
        newjoc.Match(maxscore);
        std::cout << "Play again? Yes[1], No[0] ";
        ok = false;
        while (!ok)
        {   
            ok = true;
            try
            {
                if (!(std::cin >> n))
                {
                    ok = false;
                    throw std::invalid_argument("Invalid input. Not an integer.");
                }
                if (n != 0 && n != 1)
                {
                    ok = false;
                    throw InvalidChoice("Invalid input. Choose [1] for Yes and [0] for No. ");
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
    }
}

void newNumMatch()
{
    NumHand newhand;
    std::vector<NumPlayer> jucatori;
    int n = 2;
    int maxscore;
    std::cout << "What score must a Player have to win? ";
    bool ok = false;
    while (!ok)
    {   
        ok = true;
        try
        {
            if (!(std::cin >> maxscore))
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Not an integer.");
            }
            if (maxscore < 1)
            {
                ok = false;
                throw std::out_of_range("Invalid score input. Give a value that is at least 1. ");
            }
        }
        catch (const std::out_of_range &e)
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
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        NumPlayer jucatornou{nume, 0, 0, newhand};
        jucatori.push_back(jucatornou);
    }
    NumDeck newdeck;
    newdeck.createDeck();
    NumGame joc = {jucatori, newdeck};
    joc.Match(maxscore);
    std::cout << "Play again? Yes[1], No[0] ";
    ok = false;
    while (!ok)
    {   
        ok = true;
        try
        {
            if (!(std::cin >> n))
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Not an integer.");
            }
            if (n != 0 && n != 1)
            {
                ok = false;
                throw InvalidChoice("Invalid input. Choose [1] for Yes and [0] for No. ");
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
    while (n == 1)
    {
        NumGame newjoc = {jucatori, newdeck};
        newjoc.Match(maxscore);
        std::cout << "Play again? Yes[1], No[0] ";
        ok = false;
        while (!ok)
        {   
            ok = true;
            try
            {
                if (!(std::cin >> n))
                {
                    ok = false;
                    throw std::invalid_argument("Invalid input. Not an integer.");
                }
                if (n != 0 && n != 1)
                {
                    ok = false;
                    throw InvalidChoice("Invalid input. Choose [1] for Yes and [0] for No. ");
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
    }
}

void newClassicMatch()
{
    ClassicHand newhand;
    std::vector<ClassicPlayer> jucatori;
    int n = 2;
    int maxscore;
    std::cout << "What score must a Player have to win? ";
    bool ok = false;
    while (!ok)
    {   
        ok = true;
        try
        {
            if (!(std::cin >> maxscore))
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Not an integer.");
            }
            if (maxscore < 1)
            {
                ok = false;
                throw std::out_of_range("Invalid score input. Give a value that is at least 1. ");
            }
        }
        catch (const std::out_of_range &e)
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
    std::cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        std::cout << "Player " << i << " what is your name?" << '\n';
        std::string nume;
        std::cin >> nume;
        ClassicPlayer jucatornou{nume, 0, 1000, newhand};
        jucatori.push_back(jucatornou);
    }
    ClassicDeck newdeck;
    newdeck.createDeck();
    ClassicGame joc = {jucatori, newdeck};
    joc.Match();
    std::cout << "Play again? Yes[1], No[0] ";
    ok = false;
    while (!ok)
    {   
        ok = true;
        try
        {
            if (!(std::cin >> n))
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Not an integer.");
            }
            if (n != 0 && n != 1)
            {
                ok = false;
                throw InvalidChoice("Invalid input. Choose [1] for Yes and [0] for No. ");
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
    while (n == 1)
    {
        ClassicGame newjoc = {jucatori, newdeck};
        newjoc.Match();
        std::cout << "Play again? Yes[1], No[0] ";
        ok = false;
        while (!ok)
        {   
            ok = true;
            try
            {
                if (!(std::cin >> n))
                {
                    ok = false;
                    throw std::invalid_argument("Invalid input. Not an integer.");
                }
                if (n != 0 && n != 1)
                {
                    ok = false;
                    throw InvalidChoice("Invalid input. Choose [1] for Yes and [0] for No. ");
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
    }
}

void newMatch()
{
    std::cout << "What mode would you like to play? Normal[1], Classic[2], Trump[3] ";
    int choice = -1;
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
                throw InvalidChoice("Invalid input. Choose Game Mode: Normal[1], Classic[2], Trump[3] ");
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
    if (choice == 1)
        newNumMatch();
    else if (choice == 2)
        newClassicMatch();
    else
        newTrumpMatch();
    std::cout << "\n";
}

int main()
{
    newMatch();
    return 0;
}
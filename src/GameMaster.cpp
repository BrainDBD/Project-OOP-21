#include "../include/GameMaster.h"

GameMaster* GameMaster::instance = nullptr;

GameMaster::GameMaster() : currentGameType(GameType::Unknown), activeGame(nullptr) {}

GameMaster* GameMaster::getInstance()
{
    if (!instance)
        instance = new GameMaster();
    return instance;
}

void GameMaster::startGame()
{
    std::cout << "Welcome! You may choose from one of three different 21 game modes:"<<'\n';
    std::cout << "Normal - Play against one other player while attempting to reach 21. Both of you share the same deck, made out of 11 cards, numbered 1-11."<<'\n';
    std::cout << "Trump - Same rules as Normal, but you will both also get special cards that do something that affects the board when played."<<'\n';
    std::cout << "Classic - The classic ruleset that is used in Casinos. Many players bet against the Dealer, trying to reach a target score."<<'\n';
    std::cout << "What mode would you like to play? Normal[1], Trump[2], Classic[3] ";
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
                throw InvalidChoice("Invalid input. Choose Game Mode: Normal[1], Trump[2], Trump[3] ");
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
    switch (choice)
    {
        case 1:
            startNumGame();
            break;
        case 2:
            startTrumpGame();
            break;
        case 3:
            startClassicGame();
            break;
        default:
            throw std::invalid_argument("Invalid input");
            break;
    }
    replayGame();
}

void GameMaster::startNumGame()
{
    if (currentGameType != GameType::Unknown)
        endCurrentGame();
    currentGameType = GameType::Num;
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
    activeGame = new NumGame(jucatori,newdeck);
    NumGame* numActiveGame = static_cast<NumGame*>(activeGame);
    numActiveGame->Match(maxscore);
}

void GameMaster::startClassicGame()
{
    if (currentGameType != GameType::Unknown)
    {
        endCurrentGame();
    }
    currentGameType = GameType::Classic;
    ClassicHand newhand;
    std::vector<ClassicPlayer> jucatori;
    int n;
    std::cout << "How many Players? ";
    std::cin >> n;
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
            if (maxscore < 1001)
            {
                ok = false;
                throw std::out_of_range("Invalid score input. Give a value that is at least 1001. ");
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
        ClassicPlayer jucatornou{nume, 0, 1000, 0, newhand, Role::None};
        jucatori.push_back(jucatornou);
    }
    ClassicDeck newdeck;
    newdeck.createDeck();
    activeGame = new ClassicGame(n, jucatori, newdeck);
    ClassicGame* classicActiveGame = static_cast<ClassicGame*>(activeGame);
    classicActiveGame->Match(maxscore);
}

void GameMaster::startTrumpGame()
{
    if (currentGameType != GameType::Unknown)
        endCurrentGame();
    currentGameType = GameType::Trump;
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
    activeGame = new TrumpGame(jucatori, newdeck, newtdeck);
    TrumpGame* trumpActiveGame = static_cast<TrumpGame*>(activeGame);
    trumpActiveGame->Match(maxscore);
}

void GameMaster::endCurrentGame()
{
    switch (currentGameType)
    {
        case GameType::Num:
            delete static_cast<NumGame*>(activeGame);
            break;
        case GameType::Classic:
            delete static_cast<ClassicGame*>(activeGame);
            break;
        case GameType::Trump:
            delete static_cast<TrumpGame*>(activeGame);
            break;
        default:
            break;
    }
    currentGameType = GameType::Unknown;
    activeGame = nullptr;
}

void GameMaster::replayGame()
{
    endCurrentGame();
    std::cout << "Play again? Yes[1], No[0] ";
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
                if (choice != 0 && choice != 1)
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
    switch(choice)
    {
        case 1:
            {
                std::cout << "What mode would you like to play? Normal[1], Trump[2], Classic[3] ";
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
                            throw InvalidChoice("Invalid input. Choose Game Mode: Normal[1], Trump[2], Trump[3] ");
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
                switch (choice)
                {
                    case 1:
                        startNumGame();
                        break;
                    case 2:
                        startTrumpGame();
                        break;
                    case 3:
                        startClassicGame();
                        break;
                    default:
                        throw std::invalid_argument("Invalid input");
                        break;
                }
                replayGame();  
                break;              
            }
        default:
            break;
    }
}

GameMaster::~GameMaster()
{
    endCurrentGame();
}
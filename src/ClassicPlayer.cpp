#include "../include/ClassicPlayer.h"

ClassicPlayer::ClassicPlayer(std::string name_, int points_, int score_, int bet_, ClassicHand hand_, Role role_) : StarterPlayer(name_, points_, score_), hand{hand_}, bet{bet_}, role{role_} {}
ClassicPlayer::ClassicPlayer(const ClassicPlayer &other) : StarterPlayer(other), hand{other.hand} {}
Role ClassicPlayer::getRole() { return role; }
void ClassicPlayer::setRole(Role newRole) { role = newRole; }
int ClassicPlayer::getBet() { return bet; }
void ClassicPlayer::Bet()
{
    std::cout << getName() <<", how much do you wanna bet? ";
    int choice;
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
            if (choice > score)
            {
                ok = false;
                throw InvalidBet();
            }
            if (choice < 1)
            {
                ok = false;
                throw std::invalid_argument("Invalid input. Your best must be at least $1");
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
    std::cout<<'\n';
    bet = choice;
}
void ClassicPlayer::showHand() { std::cout << hand << calculatePoints() << '\n'; }
void ClassicPlayer::showDealerHand() { hand.getDealerHand(); }
int ClassicPlayer::HandSize()
{
    int s = hand.DeckSize();
    return s;
}
void ClassicPlayer::addToHand(ClassicCard card_) { hand.addToDeck(card_); }
void ClassicPlayer::exchangeHands(ClassicPlayer &other) { hand.exchange(other.hand); }
void ClassicPlayer::returnHand(ClassicHand &deck)
{
    ClassicCard lastcard = hand.lastCard();
    hand.removeLastCard();
    deck.addToDeck(lastcard);
}
void ClassicPlayer::clearHand() { hand.emptyDeck(); }
int ClassicPlayer::calculatePoints()
{
    int aux = points;
    if (aux > 21)
    {
        int n = hand.getnAces();
        while (n)
        {
            aux -= 10;
            n--;
        }
    }
    return aux;
}

void ClassicPlayer::decreaseScore(int betsy) { score = score - betsy; }
ClassicPlayer &ClassicPlayer::operator=(const ClassicPlayer &other)
{
    if (this != &other)
    {
        name = other.name;
        points = other.points;
        score = other.score;
        hand = other.hand;
    }
    return *this;
}
void ClassicPlayer::Display(std::ostream &os) const
{
    os << "Printing all data for NumPlayer with Id: " << Id << '\n';
}
std::ostream &operator<<(std::ostream &os, const ClassicPlayer &player)
{
    player.Display(os);
    os << "Name: " << player.name << '\n';
    os << "Points: " << player.points << '\n';
    os << "Score: " << player.score << '\n';
    os << "Hand: " << player.hand << '\n';
    return os;
}
ClassicPlayer::~ClassicPlayer() = default;
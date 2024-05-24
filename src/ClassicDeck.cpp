#include "../include/ClassicDeck.h"

ClassicDeck::ClassicDeck(const std::vector<AnyCard*> &cards_) : ClassicCardContainer(cards_) {}
ClassicDeck::ClassicDeck(const ClassicDeck &other) : ClassicCardContainer(other) {}
ClassicDeck::ClassicDeck(ClassicDeck&& other) noexcept : ClassicCardContainer()
{
    cards.swap(other.cards);
    //cards = std::move(other.cards);
    other.cards.clear();
}
void ClassicDeck::createDeck()
{
    for (int type = static_cast<int>(ClassicType::Two); type <= static_cast<int>(ClassicType::King); ++type)
    {
        for (int suit = static_cast<int>(Suit::Spades); suit <= static_cast<int>(Suit::Diamonds); ++suit)
        {
            ClassicType cardType = static_cast<ClassicType>(type);
            Suit cardSuit = static_cast<Suit>(suit);
            AnyCard *auxcard = new ClassicCard{cardType,cardSuit};
            cards.emplace_back(auxcard);
        }
    }
}
void ClassicDeck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}
ClassicCard ClassicDeck::dealCard()
{
    if (!cards.empty())
    {
        ClassicCard dealtcard = *dynamic_cast<ClassicCard*>(cards.back());
        cards.pop_back();
        return dealtcard;
    }
    else
    {
        ClassicCard errorcard{ClassicType::Error, Suit::Error};
        return errorcard;
    }
}
ClassicCard ClassicDeck::drawCard(ClassicCard card_)
{
    for (auto newfullCard = cards.begin(); newfullCard != cards.end(); ++newfullCard)
        {
        ClassicCard* fullCard = dynamic_cast<ClassicCard*>(*newfullCard);
        if (fullCard && fullCard->getType() == card_.getType() && fullCard->getSuit() == card_.getSuit())
        {
            ClassicCard drawncard = *fullCard;
            removefromDeck(*fullCard);
            return drawncard;          
        }                
        }
    ClassicCard drawncard = {ClassicType::Error, Suit::Error};
    return drawncard;
}
ClassicDeck &ClassicDeck::operator=(const ClassicDeck &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
ClassicDeck &ClassicDeck::operator=(ClassicDeck&& other) noexcept
{
    if (this != &other)
    {
        for (auto& card : cards)
        {
            delete card;
        }
        cards.clear();
        cards = std::move(other.cards);
        other.cards.clear();
    }
    return *this;
}
void ClassicDeck::Afisare(std::ostream &os)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " ";
    std::cout << '\n';
}
ClassicDeck::~ClassicDeck() = default;
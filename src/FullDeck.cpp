#include "../include/FullDeck.h"

FullDeck::FullDeck(const std::vector<AnyCard*> &cards_) : FullCardContainer(cards_) {}
FullDeck::FullDeck(const FullDeck &other) : FullCardContainer(other) {}
void FullDeck::createDeck()
{
    for (int type = static_cast<int>(FullType::Two); type <= static_cast<int>(FullType::King); ++type)
    {
        for (int suit = static_cast<int>(Suit::Spades); suit <= static_cast<int>(Suit::Diamonds); ++suit)
        {
            FullType cardType = static_cast<FullType>(type);
            Suit cardSuit = static_cast<Suit>(suit);
            AnyCard *auxcard = new FullCard{cardType,cardSuit};
            cards.emplace_back(auxcard);
        }
    }
}
void FullDeck::shuffleDeck()
{
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(cards.begin(), cards.end(), g);
}
FullCard FullDeck::dealCard()
{
    if (!cards.empty())
    {
        FullCard dealtcard = *dynamic_cast<FullCard*>(cards.back());
        cards.pop_back();
        return dealtcard;
    }
    else
    {
        FullCard errorcard{FullType::Error};
        return errorcard;
    }
}
FullCard FullDeck::drawCard(FullCard card_)
{
    for (auto newfullCard = cards.begin(); newfullCard != cards.end(); ++newfullCard)
        {
        FullCard* fullCard = dynamic_cast<FullCard*>(*newfullCard);
        if (fullCard && fullCard->getType() == card_.getType() && fullCard->getSuit() == card_.getSuit())
        {
            FullCard drawncard = *fullCard;
            removefromDeck(*fullCard);
            return drawncard;          
        }                
        }
    FullCard drawncard = {FullType::Error, Suit::Error};
    return drawncard;
}
FullDeck &FullDeck::operator=(const FullDeck &other)
{
    for (unsigned int i = 0; i < other.cards.size(); i++)
        cards[i] = other.cards[i];
    return *this;
}
void FullDeck::Afisare(std::ostream &os)
{
    for (unsigned int i = 0; i < cards.size(); i++)
        std::cout << cards[i] << " ";
    std::cout << '\n';
}
FullDeck::~FullDeck() = default;
#include <iostream>
#include <algorithm>
#include "BlackJack.h"

Card::Card():name(two){};

Card::Card(cardsuit s, cardname n): suit(s), name(n){};

void Card::flip()
{
    isUpsideDown = !isUpsideDown;
}

int Card::getValue()
{
    if(name<11) return (int)name;
    else return 10;
}

ostream& operator<<(ostream &stream, const Card &card)
{
    if(card.isUpsideDown == true) stream << "XX";
    else stream << card.suit << " " << card.name;
    return stream;
}

int Hand::getValue() const
    {
        int value = 0; bool haveAce = false;
        for(int i=0; i<Cards.size(); i++)
        {
            if(Cards[i]->getValue()==1) haveAce = true;
            value = value + Cards[i]->getValue();
        }
        if(value<=21 && haveAce==true) value = value + 10;
        return value;
    }
ostream& operator <<(ostream& stream, const Hand &hand)
{
    stream << "Cards: ";
    for(int i=0; i<hand.Cards.size(); i++)
    {
        stream << hand.Cards[i];
    }
}
ostream& operator <<(ostream& stream, GenericPlayer &player)
{
    stream << "Player: " << player.name << "Cards: " << Hand();
}

bool Player::isHitting() const
{
    do
    {
    char answer;
    cout << "Would you like to take another card?(y/n)" << endl;
    cin >> answer;
    if(answer == 'y') return true;
    else if(answer == 'n') return false;
    } while (true);
}

void Player::Win() const
{
    cout << "Unfortunately, " << name << ", you win.." << endl;
}


void Player::Lose() const
{
    cout << "Congratulations! Player " << name << "is loser!!! (it means you loser c:)" << endl;
}

void Player::Push() const
{
    cout << "Uncommonly, game is tied, " << name << "!" << endl;
}

bool House::IsHitting() const
{
    if(getValue()<=16) return true;
    else return false;
}

void House::FlipFirstCard()
{
    if (!(Cards.empty()))
    {
        Cards[0]->flip();
    }
    else
    {
        cout << "No card to flip!\n";
    }
}

void Deck::Populate()
{

    clear();
    for (int s = cardsuit::clubs; s <= cardsuit::spades; ++s)
    {
        for (int r = cardname::ace; r <= cardname::king; ++r)
        {
            add(new Card((cardsuit)s, (cardname)r));
        }
    }

}

void Deck::Shuffle()
{
    random_shuffle(Cards.begin(), Cards.end());
}

void Deck::Deal(Hand& aHand)
{
    if (!Cards.empty())
    {
        aHand.add(Cards.back());
        Cards.pop_back();
    }
    else
    {
        cout << "Sorry, out of cards. Unable to deal";
    }
}


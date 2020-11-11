#ifndef BLACKJACK_H_INCLUDED
#define BLACKJACK_H_INCLUDED
#include <vector>

using namespace std;

enum cardsuit
{
    diamonds,
    hearts,
    spades,
    clubs
};
enum cardname
{
    ace = 1,
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king
};

class Card
{
private:
    cardsuit suit;
    cardname name;
    bool isUpsideDown;
public:
    Card();
    Card(cardname n);

    void flip();
    int getValue();
};

class Hand
{
private:
    vector<Card*> Cards;
public:
    Hand(){};

    void add(Card* newCard){ Cards.push_back(newCard); }
    void clear()
    {
        Cards.clear();
        delete [] &Cards;
    }
    int getValue();
};

class GenericPlayer : public Hand
{
private:
    string name;
public:
    GenericPlayer(): name("Player"){};
    GenericPlayer(string n): name(n){};

    virtual bool IsHitting();
    bool IsBoosted()
    {
        if(getValue()>21) Bust();
    }
    void Bust()
    {
        cout << "Player " << name << " boosted!" << endl;
    }
};

#endif // BLACKJACK_H_INCLUDED

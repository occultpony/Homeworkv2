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

    friend ostream& operator<<(ostream &stream, const Card &card);
};

class Hand
{
public:
    vector<Card*> Cards;
public:
    Hand(){};

    void add(Card* newCard){ Cards.push_back(newCard); }
    void clear()
    {
        Cards.clear();
        delete [] &Cards;
    }
    int getValue() const;

    friend ostream& operator <<(ostream& stream, const Hand &hand);
};

class GenericPlayer : public Hand
{
public:
    string name;
    GenericPlayer(): name("Player"){};
    GenericPlayer(string n): name(n){};

    virtual bool IsHitting() const = 0;
    bool IsBoosted()
    {
        bool boosted = getValue()>21;
        if(boosted) Bust();
        return(boosted);
    }
    void Bust()
    {
        cout << "Player " << name << " boosted!" << endl;
    }

    friend ostream& operator <<(ostream& stream, const GenericPlayer &player);
};

class Player : public GenericPlayer
{
public:
    Player():GenericPlayer(){};
    Player(string n):GenericPlayer(n){};

    virtual bool isHitting() const;
    void Win() const;
    void Lose() const;
    void Push() const;

};

class House : public GenericPlayer
{
public:
    House():GenericPlayer(){};
    House(string n):GenericPlayer(n){};

    virtual bool IsHitting() const;
    void FlipFirstCard();
};

#endif // BLACKJACK_H_INCLUDED

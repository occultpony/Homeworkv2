#include <iostream>
#include "BlackJack.h"

Card::Card():name(two){};

Card::Card(cardname n): name(n){};

void Card::flip()
{
    isUpsideDown = !isUpsideDown;
}

/*int Card::getValue()
{
    return value;
}*/

int Card::getValue()
{
    if(name<11) return (int)name;
    else return 10;
}

int Hand::getValue()
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

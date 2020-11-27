#include <iostream>
#include <sstream>
#include <string>

using namespace std;

//Homework №5

//TASK 1

bool isInteger(string s)
{
    if(!isdigit(s[0]) && s[0]!='-') return false;
    for (int i = 1; i < s.length(); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}

//TASK 2
ostream &endll(ostream &stream)
{
    //stream << endl;
    //stream << endl;

    stream << "\n\n" << flush;

    return stream;
}


int main()
{
    //TASK 1
    string answer;
    cout << "  1. ";
    do
    {
        cout << "Enter integer:" << endl;
        cin >> answer;
        if(isInteger(answer)==false) cout << "ERROR!!! Invalid input. Try again" << endl;
    } while(isInteger(answer)==false);
    cout << "is integer" << endl;

    //TASK 2
    cout << "  2. Using endll:" << endll;

    return 0;
}

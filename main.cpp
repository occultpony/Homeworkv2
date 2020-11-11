#include <iostream>

using namespace std;

//Homework №5

//TASK 1
template <class T>
class Pair1
{
private:
    T t1;
    T t2;
public:
    Pair1(T tt1, T tt2):t1(tt1), t2(tt2){};

    T first()const{return t1;}
    T second()const{return t2;}
};

//TASK 2
template<class T1, class T2>
class Pair
{
private:
    T1 t1;
    T2 t2;
public:
    Pair(T1 tt1, T2 tt2):t1(tt1), t2(tt2){};

    T1 first()const{return t1;}
    T2 second()const{return t2;}
};

//TASK 3
template<class T>
class StringValuePair : public Pair<string, T>
{
public:
    StringValuePair(string s, T v): Pair<string, T>(s, v){};
};

int main()
{
    //TASK 1
    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    //TASK 2
    Pair<int, double> p3(6, 7.8);
    cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    //TASK 3
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}

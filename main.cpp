#include <iostream>
#include <vector>
//#include <set>
#include <cassert>

//#include "BlackJack.h"

using namespace std;

//#define PI 3.14159265

//Homework №4


//TASK 1
class ArrayInt
{
private:
    int m_length;
    int *m_data;
public:
    ArrayInt():m_length(0), m_data(nullptr){}
    ArrayInt(int length):m_length(length)
    {
        assert(length>=0);
        if(length>0) m_data = new int[length];
        else m_data = nullptr;
    }
    ~ArrayInt() {delete [] m_data;}

    void print()
    {
        for(int i=0; i<m_length; i++) cout << m_data[i] <<(i==m_length-1 ? "\n" : ", ");
    }

    void erase()
    {
        delete [] m_data;
        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const {return m_length;}

    int& operator[](int index)
    {
        assert(index>=0 && index<m_length);
        return m_data[index];
    }

    void resize(int newLength)
    {
        if(newLength==m_length) return;
        if(newLength<=0)
        {
            erase(); return;
        }
        int *data = new int[newLength];
        if(m_length>0)
        {
            int elementsToCopy = (newLength>m_length) ? m_length : newLength;
            for(int i=0; i<elementsToCopy; i++)
            {
                data[i]=m_data[i];
            }
        }
        delete [] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        assert(index>=0 && index<=m_length);
        int *data = new int[m_length+1];
        for(int before=0; before<index; ++before)
        {
            data[before]=m_data[before];
        }
        data[index] = value;
        for(int after=index; after<m_length; ++after)
        {
            data[after+1]=m_data[after];
        }
        delete [] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value){insertBefore(value, m_length);}

    void pop_back(){resize(m_length-1);}

    void pop_front()
    {
        for(int i=0; i<m_length; ++i)
        {
            m_data[i]=m_data[i+1];
        }
        resize(m_length-1);
    }

    void sort()
    {
        quicksort(m_data, m_length);
    }

    void quicksort(int* data, const int length)
    {
        const int len=length;
        int pivot=0;
        int i, i_r, i_l =0;
        int index=len/2;
        if(len>1)
        {
            int* left = new int[len];
            int* right = new int[len];
            pivot=data[index];
            for(i=0; i<len; i++)
            {
                if(i!=index)
                {
                    if(data[i]<pivot)
                    {
                        left[i_l]=data[i];
                        i_l++;
                    }
                    else
                    {
                        right[i_r]=data[i];
                        i_r++;
                    }
                }
            }
            quicksort(left, i_l);
            quicksort(right, i_r);
            for(int cnt=0; cnt<len; cnt++)
            {
                if(cnt<i_l) data[cnt]=left[cnt];
                else if(cnt==i_l)data[cnt]=pivot;
                else data[cnt]=right[cnt-(i_l+1)];
            }

        }
    }
};

//TASK 2

int getDifferNumsCount(vector<int>* arr)
{
    vector<int> differarr; bool haveDublicate=false;
    for(int i=0; i<arr->size(); i++)
    {
        for(int j=0; j<differarr.size(); j++)
        {
            if(differarr.at(j)==(*arr).at(i)) haveDublicate=true;
        }
        if(!haveDublicate) differarr.push_back((*arr).at(i));
        haveDublicate=false;
    }
    return differarr.size();

}

int main()
{
    //TASK 1

    ArrayInt M;
    M.push_back(1);
    M.push_back(2);
    M.push_back(3);
    M.print();

    M.pop_back();
    M.print();

    M.push_back(3);
    M.pop_front();
    M.print();

    M.push_back(40);
    M.push_back(-8);
    M.push_back(7);
    M.print();

    //M.sort();
    //M.print();

    vector<int> v = {0, 1, 2, 5, 1, 7 ,18 ,8 , 7, 0};

    cout << "Count of different numbers in vector:" << endl;
    cout << getDifferNumsCount(&v) << endl;



    /*Hand hand;
    Card c1(diamonds, seven);
    Card c2(clubs, queen);
    Card c3(hearts, four);
    Card c4(spades, ace);
    hand.add(&c1);
    hand.add(&c2);
    hand.add(&c3);
    hand.add(&c4);
    cout << "value: " << hand.getValue() << endl;*/

    return 0;
}

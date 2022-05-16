#include"Stack.h"
#include<iostream>
#include<vector>
#define Size 10
using namespace std;


Stack::Stack() {}
Stack::~Stack() {}
bool Stack::empty()
{
    return top == -1;
}
bool Stack::full()
{
    return top == Size - 1;
}
int Stack::size()
{
    return top + 1;
}
int Stack::showtop()
{
    if (empty())
        cout << "Empty" << endl;
    return stackArr[top];
}
void Stack::push(int elem)
{
    if (full())
        cout << "Full" << endl;
    else
    {
        cout << "Push: " << elem << endl;
        ++top;
        stackArr[top] = elem;
    }
}
void Stack::pop()
{
    if (empty())
        cout << "Empty" << endl;
    else
        cout << "Pop: " << stackArr[top] << endl;
    --top;
}

void Stack::swap(int arr[])
{
    int temp[Size];
    for (int i = 0; i < Size; ++i)
    {
        temp[i] = arr[i];
        arr[i] = stackArr[i];
        stackArr[i] = temp[i];
    }
}



void Stack::print()
{
    cout << "Stack: " << endl;
    for (int i = 0; i <= top; ++i)
        cout << stackArr[i] << endl;
    cout << endl;
}


Set::Set()
{
    arr.push_back(new Stack());
}
Set::Set(int n) : size(n)
{
    arr.push_back(new Stack());
}
Set::~Set() {}
void Set::push(int a)
{
    if (count < size)
    {
        arr.back()->push(a);
        count++;
    }
    else
    {
        arr.push_back(new Stack());
        arr.back()->push(a);
        count = 1;
    }
}
void Set::pop()
{
    if (count == 1)
    {
        arr.back()->pop();
        arr.pop_back();
        count = size;
    }
    else if (count > 1)
    {
        arr.back()->pop();
        --count;
    }
    else
    {
        arr.pop_back();
        arr.back()->pop();
        count = size - 1;
    }
}
void Set::popAt(int index)
{
    arr[index]->pop();
}
void Set::printSet()
{
    cout << endl << "Start of the set : " << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i]->print();
        cout << endl;

    }
    cout << "End of the set" << endl << endl;
}
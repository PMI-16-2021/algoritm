#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack() //constructor
{
    top =-1;
}

int Stack::isEmpty() //check whether stack is empty
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        //cout << "Stack is empty\n";
        return 0;
    }
}

int Stack::size() // return the size of the stack
{
    return top + 1;
}

int Stack::topElement() //finding the last added element 
{
    if (isEmpty()) 
    {
        //cout << "Stack is empty\n";
    }
    return num[top];
}

int Stack::isFull() //check whether stack is full
{
    if (top == (SIZE - 1))
    {
        return 1;
    }
    else
    {
        //cout << "Stack is not full\n";
        return 0;
    }
}

int Stack::push(int n) //inserting the element
{
    if (isFull())
    {
        cout << "Stack is full\n";
        return 0;
    }
    ++top;
    num[top] = n;
    return n;
}

int Stack::pop() //deleting the top element
{
    int temp; //to store and print which number is deleted
    if (isEmpty())
    {
        return 0;
    }
    temp = num[top];
    --top;
    return temp;
}

void Stack::printElements()
{
    int i;
    cout << "Stack contains: ";
    for (i = top; i >= 0; i--)
    {
        cout << num[i] << " ";
    }
    cout <<"\n";
}

int Stack::emplace(int n) //inserting the element
{
    if (isFull()) 
    {
        return 0;
    }
    ++top;
    num[top] = n;
    return n;
}

void Stack::swap(int a, int b) //swaping contents
{
    if (a > top || a < 0 || b > top || b < 0)
    {
        cout << "Error\n";
    }
    int temp = num[a];
    num[a] = num[b];
    num[b] = temp;
}
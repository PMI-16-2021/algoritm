#pragma once
#define SIZE 5 //size of stack
class Stack
{
private:
    int num[SIZE];
    int top;   

public:
    Stack();    //defualt constructor
    int isEmpty();
    int size();
    int topElement();
    int push(int n);
    int pop();
    void printElements();
    int isFull();
    int emplace(int n);
    void swap(int a, int b);
};
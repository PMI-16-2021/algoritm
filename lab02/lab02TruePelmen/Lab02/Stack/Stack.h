#pragma once
#include<iostream>
#include<vector>
#define Size 10
using namespace std;


class Stack
{
private:
    int stackArr[Size] = {0, 0, 0, 0, 0, 0, 0, 0};
    int top = -1;
public:
    Stack();
    ~Stack();
    bool empty();
    bool full();
    int size();
    int showtop();
    void push(int elem);
    void pop();
    void swap(int arr[]);
    void print();
};
class Set
{
    vector<Stack*> arr;
    int size = 10;
    int count = 0;
public:
    Set();
    Set(int n);
    ~Set();
    void push(int a);
    void pop();
    void popAt(int index);
    void printSet();
};
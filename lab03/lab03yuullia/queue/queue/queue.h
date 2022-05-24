#pragma once
#include <iostream>

struct Pair
{
	int value;
	int priority;
    Pair* next;

    Pair(int v, int pr);
    ~Pair();
};

class PriorityQ 
{
private:
	Pair* head;
public:
    PriorityQ();
    ~PriorityQ();

    void enqueue(int v, int pr);
    void dequeue();
    bool isEmpty();
    int size();
    int top();

    void printQ();
};

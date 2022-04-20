#pragma once

struct Pair
{
	int value;
	int priority; 
	Pair* next;
};

class PrQueue
{
private:
	Pair* head;

public:
	PrQueue();
	bool isEmpty();
	int size();
	int top();
	void enQueue(int, int);
	int deQueue();
	void printQueue() const;
};


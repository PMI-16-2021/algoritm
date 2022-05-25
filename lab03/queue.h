#pragma once
#include <iostream>
using namespace std;

struct Pair {
	int value;
	int priority;
	Pair* next;
	Pair() :
		value(0),
		priority(0),
		next(nullptr)
	{}
	Pair(int v, int p) :
		value(v),
		priority(p),
		next(nullptr)
	{}

};

class PriorityQueue {
private:
	Pair* tail;
public:
	PriorityQueue();
	PriorityQueue(int value, int prior);
	void enqueue(int va, int p);
	bool isEmpty();
	void printPriorityQueue();
	int size();
	void dequeue();
	int taill();
	int head();
};

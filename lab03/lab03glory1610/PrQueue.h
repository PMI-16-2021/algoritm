#pragma once
#include<iostream>

struct Pair {
	int value;
	int priority;
	Pair* next;

	Pair(int val, int prior)
		: value(val), priority(prior), next(nullptr) {}
};

class PriorityQueue {
private:
	Pair* head;
public:
	PriorityQueue();
	~PriorityQueue();
	int size();
	int top();
	bool isEmpty();
	void enqueue(int val, int prior);
	int dequeue();
	void print();
};

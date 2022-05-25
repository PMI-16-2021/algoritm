#pragma once
#include <vector>
#include "Stack.h"

class SetOfStacks {
private:
	std::vector<Stack*> stackArr;
	int max;
	int size;

public:
	SetOfStacks();
	SetOfStacks(int s);
	~SetOfStacks();

	void push(int val);
	void printSetOfStacks();
	void pop();
	void popAt(int);
};
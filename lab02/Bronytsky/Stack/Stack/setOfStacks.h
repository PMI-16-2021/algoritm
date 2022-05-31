#pragma once
#include <vector>
#include "Stack.h"

class SetOfStacks {
private:
	std::vector<Stack*> arr;
	int max;
	int size;

public:
	SetOfStacks(int);
	~SetOfStacks();

	void push(int);
	void pop();
	void popAt(int);
	void printSetOfStacks();
};

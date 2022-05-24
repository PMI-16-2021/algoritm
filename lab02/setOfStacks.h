#pragma once
#include "stack.h"
#include <vector>

class SetOfStacks {
    std::vector<Stack*> arr;
    int size = 4;
    int count = 0;
public:
	SetOfStacks();
	SetOfStacks(int n);
    ~SetOfStacks();

	void push(int a);
	void pop();
	void popAt(int pos);
	void printSetOfStacks();
};

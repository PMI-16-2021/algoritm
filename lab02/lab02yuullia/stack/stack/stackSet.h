#pragma once
#include "stack.h"
#include <vector>

class SetOfStacks {
private:
	std::vector<Stack*> setArr;
	int element_max;
	int stack_size;
public:
	SetOfStacks(int size);
	~SetOfStacks();

	void popAt(int index);
	void pop();
	void push(int value);
	
	void printSet();
};


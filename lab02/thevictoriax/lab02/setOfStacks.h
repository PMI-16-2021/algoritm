#pragma once
#include "stack.h"
#include <vector>

class SetOfStacks
{
private:
	std::vector <Stack*> arr;
	int set_size;
	int set_max;

public:
	SetOfStacks(int value);
	~SetOfStacks();
	void printSetElements();
	void push(int temp);
	void pop();
	void popAt(int index);
};
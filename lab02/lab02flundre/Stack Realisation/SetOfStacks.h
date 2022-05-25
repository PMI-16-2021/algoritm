#pragma once
#include "Stack.h"
#include <vector>


class SetOfStacks {
public:
	/*Stack** set_of_stacks;*/
	std::vector<Stack*> set_of_stacks;
	int max_amount_of_stacks;
	int used_stacks;
	int ceil;
public:
	SetOfStacks();
	SetOfStacks(int s, int c);
	~SetOfStacks();
	void push(int elem); 
	int pop();
	int popAt(int index);
	void print();
};
	
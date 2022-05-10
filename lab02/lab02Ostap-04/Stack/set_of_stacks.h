#pragma once
#include "stack.h"
class SetOfStacks {
private:
	Stack* memory_;
	int max_size_;
	int set_size_;
	int full_set_counter_;
public:
	SetOfStacks();
	SetOfStacks(int _max_size, int _set_size);
	~SetOfStacks();
	void Push(int value);
	void Pop();
	void PopAt(int index);
	void Print();
};
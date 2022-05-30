#pragma once
#include"Stack.h"
class SetOfStacks
{
private:
	Stack* pointer;
	int max_Size;
	int sizeOfSet;
public:
	SetOfStacks();
	SetOfStacks(Stack* ptr, int max);
	SetOfStacks(int val,int max);

	void push(int val);
	void pop();
	void popAt(int index);
	void printSet();
	int getSize()const;
	

};
#pragma once
#include"stack.h"

class SetOfStacks
{
private:
	Stack* s_arr;					// масив стеків
	int s_max;						// максимальний розмір стеку
	int s_size;						// кількість стеків в сеті

public:
	SetOfStacks();
	SetOfStacks( Stack* pNext, int max);
	SetOfStacks(int val, int max);
	~SetOfStacks() {}

	int getSize() const;				// розмір Сету
	void push(int val);					// додає значення в стек
	void pop();							// видаляє значення з 'голови'
	void popAt(int index);				// видаляє значення за індексом
	void printSet();					// друкує
};
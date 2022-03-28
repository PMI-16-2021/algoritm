#pragma once
#include "Stack.h"


template <typename T>
class SetOfStacks
{
private:
	Stack<T>& operator[](int index); //private operator
	enum {MAX = 5};
	Stack<T> memory[MAX]; // pointer to  Stack array 
	int filledLists; // number of full Stacks inside Set
public:
	SetOfStacks<T>();
	virtual ~SetOfStacks<T>();
	virtual T pop(); //override from class Stack
	virtual void push(T); //override from class Stack
};



template<typename T>
SetOfStacks<T>::~SetOfStacks()
{
	//~Stack => method clear for each one
}

template <typename T>
T SetOfStacks<T>::pop()
{
	if (filledLists == 0 && memory[filledLists].empty())
	{
		throw "\nThis Set of Stacks is empty\n";
	}
	else if (filledLists > 0 && memory[filledLists].empty())
	{
		--filledLists;
		std::cout << "\nSize decreased. -- filled size and pop successful\n";
		return memory[filledLists].pop();
	}
	else if (!memory[filledLists].empty())
	{
		std::cout << "\nDefault succesfull pop.\n";
		return memory[filledLists].pop();
	}
}

template<typename T>
SetOfStacks<T>::SetOfStacks(): filledLists(0)
{
}

template <typename T>
void SetOfStacks<T>::push(T _item_to_push)
{
	if (memory[filledLists].size() >= MAX && filledLists >= MAX - 1)
	{
		std::cout << "\nSet of Stacks is completely full!\n";
		return;
	}
	else if (memory[filledLists].size() >= MAX  && filledLists < MAX - 1)
	{
		++filledLists;
		std::cout << "\nEnlarged: ++filledlists.\n";
		memory[filledLists].push(_item_to_push);
		return;
	}
	else if (memory[filledLists].size() < MAX)
	{
		memory[filledLists].push(_item_to_push);
		std::cout << "\nDefaultly pushed.\n";
		return;
	}

}

template<typename T>
Stack<T>& SetOfStacks<T>::operator[](int index)
{
	return memory[index];
}

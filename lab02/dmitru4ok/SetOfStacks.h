#pragma once
#include "Stack.h"

template <typename T>
class SetOfStacks
{
private:
	enum {MAX = 5};
	Stack<T> memory[MAX]; // pointer to  Stack array 
	int filledLists; // number of full Stacks inside Set
public:
	SetOfStacks<T>();
	~SetOfStacks<T>();
	T pop(); //override from class Stack
	void push(T); //override from class Stack
	T popAt(int);
	int getFilledLists()const; //return number of full stacks
};

template<typename T>
SetOfStacks<T>::~SetOfStacks()
{
	//~Stack => calls method clear for each elem of array
}

template <typename T>
T SetOfStacks<T>::pop()
{
	if (filledLists == 0 && memory[filledLists].empty()) //if 0 filled and number 0 is empty => exception: nothing to pop
	{
		throw "\nThis Set of Stacks is empty\n";
	}
	else if (filledLists > 0 && memory[filledLists].empty()) //if possible to move to previous Stack and current is empty
	{
		--filledLists;                                       //reduce filled to pop from previous!
		//std::cout << "\nSize decreased. -- filled size and pop successful\n";
	}
	return memory[filledLists].pop(); // pop
}

template<typename T>
SetOfStacks<T>::SetOfStacks(): filledLists(0) //filled = 0 and every stack is empty
{

}

template <typename T>
void SetOfStacks<T>::push(T _item_to_push)        // push item ( works with Stack::push() ) 
{
	if (memory[filledLists].size() >= MAX && filledLists >= MAX - 1)      //if size of current Stack >= MAX and filled more Stacks than MAX 
	{                                                                     //nothing to push: return
		//std::cout << "\nNot successfull. Set of Stacks is completely full!\n";
		return;                                                
	}
	else if (memory[filledLists].size() >= MAX  && filledLists < MAX - 1) //if current Stack is full and IS POSSIBLE to fill in next
	{
		++filledLists;                                                    //current Stack is next one in array
		//std::cout << "\nEnlarged: ++filledlists.\n";
		memory[filledLists].push(_item_to_push);                          //push 
		return;
	}
	else if (memory[filledLists].size() < MAX)                           //if possible pu push in current Stack
	{
		memory[filledLists].push(_item_to_push);                         //push in current Stack
		//std::cout << "\nDefaultly pushed.\n";
		return;
	}
}

template<typename T>
T SetOfStacks<T>::popAt(int index)
{
	if (index >= MAX || index < 0) //if incorrect index => exception
	{
		throw "Invalid index.\n";
	}
	if (memory[index].empty())    //if Stack with this index is empty => exception 
	{
		throw "Stack with this index is empty.\n";
	}
	return memory[index].pop(); //else pop
}

template<typename T>
inline int SetOfStacks<T>::getFilledLists() const // get number of filled Stacks in Set
{                                                 //==index of current operating array
	return filledLists; 
}

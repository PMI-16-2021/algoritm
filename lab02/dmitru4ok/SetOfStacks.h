#pragma once
#include "Stack.h"

template <typename T>
class SetOfStacks
{
private:
	int size_of_each; // number of max elements in each Stack
	int MAX;          //size of arr 
	Stack<T>* memory; // pointer to  Stack array 
	int current;  // number of full Stacks inside Set
public:
	SetOfStacks<T>();
	SetOfStacks<T>(int _MAX, int _size_of_Stacks);
	~SetOfStacks<T>(); 
	T pop(); //override from class Stack
	void push(T); //override from class Stack
	T popAt(int);        //remove at certain index
	int getCurrent()const; //return number of full stacks
	T top()const;          //acess top element
	T topAt(int index)const; //acess top element at ceratin Stack
	bool completelyEmpty() const; //true if 0 elements indsied
	bool completelyFull()const; //true if all Stacks have no free space
	void clearSet();            //delete all elements
};

template<typename T>
SetOfStacks<T>::~SetOfStacks()
{
	delete[] memory; //~Stack => calls method clear for each elem of array
}

template <typename T>
T SetOfStacks<T>::pop()
{
	if (current == 0 && memory[current].empty()) //if 0 filled and number 0 is empty => exception: nothing to pop
	{
		throw "\nThis Set of Stacks is empty\n";
	}
	else if (current > 0 && memory[current].empty())   //if possible to move to previous Stack and current is empty
	{
		while (memory[current].empty() && current > 0) //while not empty Stack is found
		{
			--current;                                     //moving back
		}
	}
	return memory[current].pop();
}


template<typename T>
SetOfStacks<T>::SetOfStacks()  //filled = 0 and every stack is empty
{
	size_of_each = 5; //default 5 
	current = 0;      //0 Stacks filled
	MAX = size_of_each;//5 as well
	memory = new Stack<T>[MAX]; // init mem
}

template<typename T>
SetOfStacks<T>::SetOfStacks(int _MAX, int _size_of_Stacks)
{
	MAX = (_MAX > 0) ? _MAX : 5;      //if _MAX > 0 the n param; else - 5;
	size_of_each = (_size_of_Stacks > 0) ? _size_of_Stacks : 5; //if _param > 0 then param; else - 5;
	memory = new Stack<T>[MAX]; //init memory
	current = 0; 
}

template <typename T>
void SetOfStacks<T>::push(T _item_to_push)                                         // push item ( works with Stack::push() ) 
{
	if (memory[current].size() >= size_of_each && current >= MAX - 1)      //if size of current Stack >= size of Stack and filled more Stacks than MAX 
	{                                                                              //nothing to push: return                   
		//std::cout << "\nNot successfull. Set of Stacks is completely full!\n";
		return;                                                
	}
	else if (memory[current].size() >= size_of_each  && current < MAX - 1) //if current Stack is full and IS POSSIBLE to fill in next
	{
		++current;                                                    //current Stack is next one in array
		//std::cout << "\nEnlarged: ++current.\n";
		memory[current].push(_item_to_push);                          //push 
		return;
	}
	else if (memory[current].size() < size_of_each)                           //if possible pu push in current Stack
	{
		memory[current].push(_item_to_push);                                  //push in current Stack
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
inline int SetOfStacks<T>::getCurrent() const // get number of filled Stacks in Set
{                                                 //==index of current operating array
	return current;
}

template<typename T>
inline T SetOfStacks<T>::top() const
{
	if (completelyEmpty())
	{
		throw "This Set of Stacks is completely empty."; 
	}
	return memory[current].top();
}

template<typename T>
T SetOfStacks<T>::topAt(int index) const //top at index
{
	if (memory[index].empty()) // *memory* Stack with index is empty
	{
		throw "No elements in stack with this index.\n";
	}
	else if (index < 0 || index >= MAX - 1) //if invalid memory index
	{
		throw "Invalid index.\n";
	}

	return memory[index].top();
}

template<typename T>
bool SetOfStacks<T>::completelyEmpty() const // if curr is empty and nowhere to move back => completelyEmpty
{
	return(current == 0 && memory[current].empty());
}

template<typename T>
inline bool SetOfStacks<T>::completelyFull() const
{
	for (int i = 0; i < MAX; ++i)
	{
		if (memory[i].size() < size_of_each) // if less than size elems in at least one Stack
		{
			return false;               // return false
		}
	}
	return true; //else return true
}

template<typename T>
void SetOfStacks<T>::clearSet()
{
	for ( int i = 0; i < MAX; ++i)
	{
		memory[i].clear();
	}
	current = 0;
}

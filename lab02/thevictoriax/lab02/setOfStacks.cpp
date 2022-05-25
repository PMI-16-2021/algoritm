#include <iostream>
#include "setOfStacks.h"
using namespace std;

SetOfStacks::SetOfStacks(int value) //constructor
{
	set_max = value;
	arr.push_back(new Stack()); //adding stack to the end of array
	this->set_size = 1;
}

SetOfStacks::~SetOfStacks() //destructor
{

}

void SetOfStacks::printSetElements()
{
	for (int i = 0; i < arr.size(); ++i)
	{
		cout << "Index: " << i + 1 << "\n";
		arr[i]->printElements();
	}
}

void SetOfStacks::push(int temp) //inserting the element
{
	if (set_size <= set_max)
	{
		arr.back()->push(temp); //accessing the top element
		++set_size;
    }
	else
	{
		arr.push_back(new Stack); //adding new stack to the end of array
		arr.back()->push(temp);
		set_size = 2;
	}
}

void SetOfStacks::pop() //deleting the top element
{
	if (set_size <= 0)
	{
		arr.pop_back(); //deleting the last stack
		set_size = set_max;
	}
	else
	{
		arr.back()->pop(); //accessing the last stack and delete it's top element
		--set_size;
	}
}

void SetOfStacks::popAt(int index) //deleting stack by index from array
{
	arr.erase(arr.begin() + index - 1); 
}
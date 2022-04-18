#pragma once
#include "List.h"


<<<<<<< Updated upstream
template<template<template<typename T> class Holder, typename T>class Cont = List, template<typename T> class Holder = Pair, typename T = int>
class PriorityQueue //template params: <Container, Holder, Type>.             
{                   //e.g.PriorityQueue<List, Pair, double> A;
	
private:
	Cont<Holder, T> object; //container (default = List) 

public:

	PriorityQueue(): object(Cont<Holder, T>()){}
	~PriorityQueue(){}
=======
template<typename T>
class PriorityQueue //template params: <Container, Holder, Type>.             
{                   //e.g.PriorityQueue<List, Pair, double> A;

private:
	List<T> object; //container (default = List) 

public:

	PriorityQueue() : object(List<T>()) {}
	~PriorityQueue() {}
>>>>>>> Stashed changes

	void enqueue(T elem, int prior) //prior 0 - MAX; 1,2,3,4 ...... bigger - lower
	{
		if (prior < 0) // prior > 0
		{
<<<<<<< Updated upstream
			throw "Bad priority. Can't be < than 0.\n";
		}
		if (isEmpty()) //if empty - addFront
		{
			object.addFront(Holder<T>(elem, prior)); //construct Pair(elem, prior)
=======
			throw"Invalid priority";
		}
		if (isEmpty()) //if empty - addFront
		{
			object.addFront(elem, prior); //construct Pair(elem, prior)
>>>>>>> Stashed changes
			return;
		}

		if (prior < object.top()->field.priority) //if prior is bigger than in head itemp - make new itemm head
		{
<<<<<<< Updated upstream
			object.addFront(Holder<T>(elem, prior));
=======
			object.addFront(elem, prior);
>>>>>>> Stashed changes
			return;
		}

		if (prior >= object.end()->field.priority) //if prior is less than in the tail - make new item tail
		{
<<<<<<< Updated upstream
			object.addBack(Holder<T>(elem, prior));
=======
			object.addBack(elem, prior);
>>>>>>> Stashed changes
			return;
		}
		else
		{
<<<<<<< Updated upstream
			ListNode<Holder<T>>* temp = object.top(); //temp = head of list
=======
			ListNode<T>* temp = object.top(); //temp = head of list
>>>>>>> Stashed changes
			while (prior >= temp->next->field.priority) //find borded of priorities (find as temp ptr to ListNode)
			{
				temp = temp->next;
			}
<<<<<<< Updated upstream
			object.add(Holder<T>(elem, prior), temp);//add to specific found place
=======
			object.add(elem, prior, temp);//add to specific found place
>>>>>>> Stashed changes
			temp = nullptr;
			return;
		}
	}

	bool isEmpty()const
	{
		return object.isEmpty();
	}

<<<<<<< Updated upstream
	void print()const
	{
		std::cout << "PRIORITY QUEUE: \n";
		object.printList();
		std::cout << '\n';
	}
=======
	void print()const;
>>>>>>> Stashed changes

	const T& dequeue()
	{
		if (isEmpty())
		{
			throw "The Queue is empty: nothing to deQueue!\n";
		}
		T return_val = object.top()->field.value;
		object.delFirst();
		return return_val;
	}
<<<<<<< Updated upstream
	
=======

>>>>>>> Stashed changes
	const T& top()const
	{
		if (isEmpty())
		{
			throw "The Queue is empty: nothing to peek!\n";
		}
		return object.top()->field.value;
	}

	int size()const
	{
		return object.size();
	}
};

<<<<<<< Updated upstream

=======
template<typename T>
void PriorityQueue<T>::print() const
{
	std::cout << "PRIORITY QUEUE: \n";
	object.printList();
	std::cout << '\n';
}
>>>>>>> Stashed changes

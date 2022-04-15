#pragma once
#include "List.h"


template<template<template<typename T> class Holder, typename T>class Cont = List, template<typename T> class Holder = Pair, typename T = int>
class PriorityQueue //template params: <Container, Holder, Type>.             
{                   //e.g.PriorityQueue<List, Pair, double> A;
	
private:
	Cont<Holder, T> object; //container (default = List) 

public:

	PriorityQueue(): object(Cont<Holder, T>()){}
	~PriorityQueue(){}

	void enqueue(T elem, int prior) //prior 0 - MAX; 1,2,3,4 ...... bigger - lower
	{
		if (prior < 0) // prior > 0
		{
			throw "Bad priority. Can't be < than 0.\n";
		}
		if (isEmpty()) //if empty - addFront
		{
			object.addFront(Holder<T>(elem, prior)); //construct Pair(elem, prior)
			return;
		}

		if (prior < object.top()->field.priority) //if prior is bigger than in head itemp - make new itemm head
		{
			object.addFront(Holder<T>(elem, prior));
			return;
		}

		if (prior >= object.end()->field.priority) //if prior is less than in the tail - make new item tail
		{
			object.addBack(Holder<T>(elem, prior));
			return;
		}
		else
		{
			ListNode<Holder<T>>* temp = object.top(); //temp = head of list
			while (prior >= temp->next->field.priority) //find borded of priorities (find as temp ptr to ListNode)
			{
				temp = temp->next;
			}
			object.add(Holder<T>(elem, prior), temp);//add to specific found place
			temp = nullptr;
			return;
		}
	}

	bool isEmpty()const
	{
		return object.isEmpty();
	}

	void print()const
	{
		std::cout << "PRIORITY QUEUE: \n";
		object.printList();
		std::cout << '\n';
	}

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



#pragma once
#include "List.h"


template<typename T>
class PriorityQueue //template params: <Container, Holder, Type>.             
{                   //e.g.PriorityQueue<List, Pair, double> A;

private:
	List<T> object; //container (default = List) 

public:

	PriorityQueue() : object(List<T>()) {}
	~PriorityQueue() {}

	void enqueue(T elem, int prior) //prior 0 - MAX; 1,2,3,4 ...... bigger - lower
	{
		if (prior < 0) // prior > 0
		{
			throw"Invalid priority";
		}
		if (isEmpty()) //if empty - addFront
		{
			object.addFront(elem, prior); //construct Pair(elem, prior)
			return;
		}

		if (prior < object.top()->field.priority) //if prior is bigger than in head itemp - make new itemm head
		{
			object.addFront(elem, prior);
			return;
		}

		if (prior >= object.end()->field.priority) //if prior is less than in the tail - make new item tail
		{
			object.addBack(elem, prior);
			return;
		}
		else
		{
			ListNode<T>* temp = object.top(); //temp = head of list
			while (prior >= temp->next->field.priority) //find borded of priorities (find as temp ptr to ListNode)
			{
				temp = temp->next;
			}
			object.add(elem, prior, temp);//add to specific found place
			temp = nullptr;
			return;
		}
	}

	bool isEmpty()const
	{
		return object.isEmpty();
	}

	void print()const;

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

template<typename T>
void PriorityQueue<T>::print() const
{
	std::cout << "PRIORITY QUEUE: \n";
	object.printList();
	std::cout << '\n';
}

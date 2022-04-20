#include "prQueue.h"
#include <iostream>
using namespace std;

//constructor
PrQueue::PrQueue()
{
	head = nullptr;
}

//check whether the queue is empty
bool PrQueue::isEmpty()
{
	if (!head)
	{
		return true;
	}
	else return false;
}


int PrQueue::size()
{
	if (head == nullptr) 
	{
		cout << "Size is 0\n";
	}
	Pair* x;
	x = head;
	int temp = 0;
	while (x != nullptr)
	{
		++temp;
		x = x->next;
	}
	return temp;
}

//to retrieve the highest priority element, without removing it from the queue.
int PrQueue::top()
{
	// head of the linked list contains the maximum priority element
	return head->value;
}

//to insert a new element into the queue
void PrQueue::enQueue(int val, int prior)
{
	Pair* x = new Pair;
	x->value = val;
	x->priority = prior;
	if (head == nullptr || prior < head->priority)
	{
		x->next = head;
		head = x;
	}
	else {
		Pair* q = head;
		while (q->next != nullptr && q->next->priority <= prior)
			q = q->next;
		x->next = q->next;
		q->next = x;
	}
}
	
//to remove the highest priority element from the queue
int PrQueue::deQueue()
{
	// head of the linked list contains the maximum priority element
	if (head != nullptr) 
	{
		int data = head->value;
		// removing the highest priority element
		head = head->next;
		return data;
	}
}

void PrQueue::printQueue() const
{
	if (head == nullptr)
	{
		cout << "Priority Queue is empty!\n";
		return;
	}
	cout << "Queue: ";
	Pair* x = head;
	while (x)
	{
		cout << x->value << "  ";
		x = x->next;
	}
}
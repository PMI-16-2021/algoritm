#pragma once
#include <iostream>
template<typename T>
struct Pair
{
	T value;
	int priority; //0 - MAX; 1,2,3,4 ...... bigger - lower

	Pair(T val = T(), int prior = 0): value(val), priority(prior){}
};

template<typename T>
struct ListNode
{
	T field;
	ListNode<T>* next;


	ListNode(T _field,  ListNode<T>* _next = nullptr) : field(_field), next(_next) { /*std::cout << "LIST NODE OF PAIRS OF INT.\n"; */ }
};


template<template<typename T> class Holder, typename T>
class List
{
protected:
	
	ListNode<Holder<T>>* head;
	ListNode<Holder<T>>* tail;
	void delFirst()
	{
		if (isEmpty()) //nothing to delete
		{
			return;
		}                
		ListNode<Holder<T>>* victim = head;  //set victim
		head = head->next;             // move head pointer to the next
		delete victim;
	}

	void delLast()
	{
		if (isEmpty())
		{
			return;
		}
		ListNode<Holder<T>>* victim = tail;
		ListNode<Holder<T>>* temp = head;
		while (temp->next != victim)
		{
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
		delete victim;
	}

public:
	List(): head(nullptr), tail(nullptr){ /*std::cout << "LIST OF LIST NODES OF PAIRS OF INT.\n"; */ }
	
	~List()
	{
		this->clear();
	}

	bool isEmpty()const { return head == nullptr; }

	void clear() {
		while (!isEmpty())
		{
			this->delFirst();  //while head != nullptr delete ListNode
		}
	}

	void addFront(Holder<T> A)
	{
		ListNode<Holder<T>>* tmporary = new ListNode<Holder<T>>(A, head);//has item of copy of parameter
		
		if (isEmpty())
		{
			tail = tmporary;
		}
		head = tmporary;
		tmporary = nullptr;
	}

	void addBack(Holder<T> A)
	{
		ListNode<Holder<T>>* temp = new ListNode<Holder<T>>(A);
		if (isEmpty())
		{
			head = temp;
			tail = temp;
			temp = nullptr;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	void add(Holder<T> A, ListNode<Holder<T>>* node)
	{
		ListNode<Holder<T>>* temp = node->next;
		node->next = new ListNode<Holder<T>>(A, temp);
		temp = nullptr;
	}

	int size()const
	{
		if (isEmpty())
		{
			return 0;
		}
		int return_size = 1;
		ListNode<Holder<T>>* temp = head;
		while (temp != tail)
		{
			temp = temp->next;
			++return_size;
		}
		return return_size;
	}

	void printList()const
	{
		if (isEmpty())         //nothing to print
		{
			std::cout << "This Stack is empty.\n";
			return;
		}
		std::cout << "My LIST: \n";
		ListNode<Holder<T>>* current = head;
		int counter = 1;           //temporary pointer
		while (current != nullptr)    // while there is no nodes
		{
			std::cout << '#' << counter << ": " << current->field.value << " \n"; //print inem
			current = current->next;  
			++counter; //move forward
		}
		std::cout << '\n';
	}

	ListNode<Holder<T>>* getHead()const
	{
		return head;
	}


	
};








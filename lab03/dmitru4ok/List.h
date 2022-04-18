#pragma once
#include <iostream>
template<typename T>
struct Pair
{
	T value;
	int priority; //0 - MAX; 1,2,3,4 ...... bigger - lower
	Pair(T val = T(), int prior = 0) : value(val), priority(prior) {}
	Pair& operator =(const Pair& other)
	{
		this->priority = other.priority;
		this->value = other.value;
		return *this;
	}
};

template<typename T>
struct ListNode
{
	Pair<T> field; //here - holds Pair structures (must have priority and value fields)
	ListNode<T>* next;
	ListNode(T data, int prior,  ListNode<T>* _next = nullptr): next(_next)
	{
		field = Pair<T>(data, (prior > 0) ? prior : 0);
	}
};


template<typename T>//List<Pair,int> A;
class List
{
private:

	ListNode<T>* head;
	ListNode<T>* tail;
public:
	List() : head(nullptr), tail(nullptr) { /*std::cout << "LIST OF LIST NODES OF PAIRS OF INT.\n"; */ }

	~List() // uses clear method
	{
		this->clear();
	}

	bool isEmpty()const { return head == nullptr; }//check if empty

	void clear(); //while head not empty delete ListNodes
	

	void addFront(T A, int prior) //add as first node
	{
		ListNode<T>* tmporary = new ListNode<T>(A, prior, head);

		if (isEmpty())
		{
			tail = tmporary;
		}
		head = tmporary;
		tmporary = nullptr;
	}

	void addBack(T A, int prior) //add as last node
	{
		ListNode<T>* temp = new ListNode<T>(A, prior);
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

	void add(T A, int prior, ListNode<T>* node) //add AFTER specific node (mainly used in Prior Queue class)
	{
		
		ListNode<T>* temp = node->next;
		node->next = new ListNode<T>(A, prior, temp);
		temp = nullptr;
	}

	int size()const //return number of elements
	{
		if (isEmpty())
		{
			return 0;
		}
		int return_size = 1;
		ListNode<T>* temp = head;
		while (temp != tail)
		{
			temp = temp->next;
			++return_size;
		}
		return return_size;
	}

	void printList()const //prints value field from all Holders ListNodes
	{
		if (isEmpty()) //nothing to print        
		{
			std::cout << "This is empty.\n";
			return;
		}

		ListNode<T>* current = head; //temp pointer
		int counter = 1;  //for numeration         
		while (current != nullptr)
		{
			std::cout << '#' << counter << ": " << current->field.value << " \n"; //print inem
			current = current->next;
			++counter;
		}
		std::cout << '\n';
	}

	ListNode<T>* top()const //return head
	{
		return head;
	}

	ListNode<T>* end()const //return last node
	{
		return tail;
	}

	void delFirst() //delete first node
	{
		if (isEmpty()) //nothing to delete
		{
			return;
		}
		ListNode<T>* victim = head;  //set victim
		head = head->next;                   // move head pointer to the next
		delete victim;
	}

	void delLast() //delete last Node
	{
		if (isEmpty())
		{
			return;
		}
		ListNode<Pair<T>>* victim = tail;
		ListNode<Pair<T>>* temp = head;
		while (temp->next != victim)
		{
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
		delete victim;
	}
};

template<typename T>
inline void List<T>::clear()
{
	while (!isEmpty())
	{
		this->delFirst();
	}
}

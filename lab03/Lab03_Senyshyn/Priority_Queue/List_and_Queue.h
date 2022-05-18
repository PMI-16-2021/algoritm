#pragma once
#include<iostream>

using namespace std;

struct Pair
{
	int value;
	int priority;
	Pair(int val, int prior = 0) : value(val), priority(prior) {}
	Pair& operator =(const Pair& other)
	{
		this->priority = other.priority;
		this->value = other.value;
		return *this;
	}
};
struct Node
{
	Pair field;                                        
	Node* next;                                    
	Node(int value, int prior, Node* next = nullptr) : next(next), field(value, prior){}
};
class List
{
private:
	Node* head;
	Node* tail;
	int size;                         
public:
	List() : head(nullptr), tail(nullptr), size(0) {}
	~List() 
	{ 
		this->clear();
	}

	int getSize() const
	{ 
		return size; 
	}             
	bool empty()const
	{
		return head == nullptr;
	}   
	void clear()
	{
		while (size > 0)      
		{
			this->delFirst(); 
		}
	}
	void addFirst(int value, int prior)
	{
		Node* temp = new Node(value, prior, head);

		if (empty())
		{
			tail = temp;
		}
		head = temp;
		temp = nullptr;
		size++;
	}
	void addLast(int A, int prior)
	{
		Node* temp = new Node(A, prior); 
		if (empty())
		{                                            
			head = temp;                               
			tail = temp;                               
			temp = nullptr;
			size++;                                  
			return;
		}
		else                                      
		{
			tail->next = temp;                             
			tail = temp;                              
			++size;                                
		}
	}
	void addAfterNode(int A, int prior, Node* node)
	{
		Node* temp = node->next;              
		node->next = new Node(A, prior, temp);   
		temp = nullptr;                             
		size++;                                    
	}
	void printList()const
	{
		if (empty())
		{
			cout << "Empty" << endl;
			return;
		}

		Node* current = head;                                        
		int counter = 1;                                                            
		while (current != nullptr)                                            
		{
			cout << '(' << counter << ") : " << current->field.value << endl; 
			current = current->next;                                             
			counter++;                                                          
		}
		cout << endl;                                              
	}
	Node* top()const 
	{ 
		return head;
	}        
	Node* end()const 
	{ 
		return tail; 
	}           
	void delFirst()
	{
		if (empty())
		{
			return;
		}
		Node* first = head; 
		head = head->next;          
		delete first;
		size--;                  
	}
	void delLast()
	{
		if (empty())
		{
			return;
		}
		else if (size == 1)
		{
			delFirst(); 
		}
		else
		{
			Node* last = tail;
			Node* temp = head;  
			while (temp->next != last)
			{
				temp = temp->next;   
			}
			tail = temp;              
			tail->next = nullptr;       
			delete last;              
		}
		size--;             
	}
};

class PriorityQueue          
{                   

private:
	List queue; 

public:

	PriorityQueue() : queue(List()) {}
	~PriorityQueue() {}

	void enqueue(int element, int prior)
	{
		if (prior < 0)                                   
		{
			cout << "Priority can`t be less than 0" << endl;
		}
		else if (isEmpty())                                
		{
			queue.addFirst(element, prior);
			return;
		}
		else if (prior < queue.top()->field.priority)       
		{
			queue.addFirst(element, prior);               
			return;
		}
		if (prior >= queue.end()->field.priority)   
		{
			queue.addLast(element, prior);              
			return;
		}
		else                                           
		{
			Node* temp = queue.top();         
			while (prior >= temp->next->field.priority) 
			{                                           
				temp = temp->next;                      
			}
			queue.addAfterNode(element, prior, temp);         
			temp = nullptr;                          
			return;
		}
	}
	int dequeue()
	{
		if (isEmpty()) 
		{
			cout << "Empty" << endl;
		}
		int value = queue.top()->field.value; 
		queue.delFirst();                        
		return value;                      
	}
	const int& top()const
	{
		if (isEmpty())                   
		{
			throw "Empty";
			cout << endl;
		}
		return queue.top()->field.value; 
	}
	void print()const
	{
		cout << "Prioriy Queue: " << endl; 
		queue.printList();               
		cout << endl;      
	}
	bool isEmpty()const
	{ 
		return queue.empty();
	} 
	int size()const
	{ 
		return queue.getSize();
	}     
	void clear()
	{
		queue.clear();
	}
};
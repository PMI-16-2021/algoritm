#pragma once
#include <iostream>
//structure template to be stored in ListNodes
template<typename T>
struct Pair 
{
	T value;
	int priority; //0 - MAX; 1,2,3,4 ...... bigger - lower
	Pair(T val = T(), int prior = 0) : value(val), priority(prior) {}
	Pair& operator =(const Pair& other);
};

//operator = for Pair structures
template<typename T>
Pair<T>& Pair<T>::operator=(const Pair<T>& other)
{
	this->priority = other.priority;
	this->value = other.value;
	return *this;
}


//struct to be the main unit of ListNode
template<typename T>
struct ListNode
{
	Pair<T> field;                                       //Pair: T value and int priority
	ListNode<T>* next;                                    //pointer to next

	ListNode(T data, int prior,  ListNode<T>* _next = nullptr): next(_next)
	{
		field = Pair<T>(data, (prior >= 0) ? prior : 0); //field = Pair of data
	}                                                    //if prior param >= 0 than then prior, else - 0 
};

//tempate class List
//List operates with ListNodes, that stores Pairs: values with prioriries
template<typename T> //List<int> A;
class List
{
private:

	ListNode<T>* head;                                //pointer to first node
	ListNode<T>* tail;                                //pointer to last node
	int _size;                                        //number of nodes
public:
	List() : head(nullptr), tail(nullptr), _size(0) {}
	~List() { this->clear(); }                        // uses clear method
	
	int getSize() const { return _size; }             //number of nodes                                            - const
	bool isEmpty()const { return head == nullptr; }   //check if empty                                             - const
	void clear();                                     //while head not empty delete ListNodes                      - O(n)!!!
	void addFront(T A, int prior);                    //add as first node                                          - const
	void addBack(T A, int prior);                     //add as last node                                           - const
	void addAfter(T A, int prior, ListNode<T>* node); //add AFTER specific node (mainly used in Prior Queue class) - O(n)!!!
	void printList()const;                            //prints value field from all Holders ListNodes              - O(n)!!!
	ListNode<T>* top()const { return head; }          //return head                                                - const
	ListNode<T>* end()const { return tail;}           //return last node                                           - const
	void delFirst();                                  //delete first node                                          - const
	void delLast();                                   //delete last Node                                           - O(n)!!!
};

//clear List
template<typename T>
inline void List<T>::clear()
{
	while (_size > 0)      //while there are nodes
	{
		this->delFirst();  //delete first ListNode
	}
}

//create new ListNode as head
template<typename T>
void List<T>::addFront(T data, int prior)      
{                                                              //tmporary ListNode with Pair of data and prior params
	ListNode<T>* tmporary = new ListNode<T>(data, prior, head);//points to head

	if (isEmpty()) //if is empty 
	{
		tail = tmporary; //tail also points to tmporary
	}
	head = tmporary;     //head points to tmporary
	tmporary = nullptr;  //revove bond 
	++_size;             //incerement size
}

//deletes last ListNode (is not in STL!) 
template<typename T>
void List<T>::delLast()
{
	if(isEmpty()) //nothing to delete
	{
		return;
	}
	if (_size == 1) //if only one
	{
		delFirst(); //delete
	}
	else 
	{
		ListNode<T>* victim = tail; //tail is victim
		ListNode<T>* temp = head;   //temp pointer = head
		while (temp->next != victim)//while next to temp is not victim
		{
			temp = temp->next;      //move forward
		}
		tail = temp;                //tail points at that ListNode, whic used to point on tail
		tail->next = nullptr;       //make new tail end by removing bond
		delete victim;              //delete victim (last node)
	}
	--_size;                        //decrement size
}

//add as last node
template<typename T>
void List<T>::addBack(T A, int prior)
{
	ListNode<T>* temp = new ListNode<T>(A, prior); //temporary List Node
	if (isEmpty())                                 //(last param == nullptr by default)
	{                                              //if empty
		head = temp;                               //head 
		tail = temp;                               //and tail point at temp
		temp = nullptr;                            //temp doesn't point anymore 
		++_size;                                   //increment size
		return;                                    
	}
	else                                           //if there are elements
	{                                
		tail->next = temp;                         //next of tail is created ListNode                  
		tail = temp;                               //move tail to it
		++_size;                                   //increment size
	}
	
}

//add AFTER specific node
template<typename T>
void List<T>::addAfter(T A, int prior, ListNode<T>* node) 
{
	ListNode<T>* temp = node->next;                 //create temp, whic points at next
	node->next = new ListNode<T>(A, prior, temp);   //existing node points at new ListNode, which points at temp
	temp = nullptr;                                 //temp doesn't point
	++_size;                                        //increment size
}

//print all Values
template<typename T>
void List<T>::printList() const
{
	if (isEmpty()) //nothing to print        
	{
		std::cout << "This is empty.\n";
		return;
	}

	ListNode<T>* current = head;                                              //temp pointer at head
	int counter = 1;                                                          //variable for numeration         
	while (current != nullptr)                                                //while temp is not nullptr
	{
		std::cout << '#' << counter << ": " << current->field.value << " \n"; //print number and item
		current = current->next;                                              //move forward
		++counter;                                                            //add one
	}
	std::cout << '\n';                                                        //empty line 
}

//deletes first Node
template<typename T>
void List<T>::delFirst()
{
	if (isEmpty())               //nothing to delete
	{
		return;
	}
	ListNode<T>* victim = head; //set victim
	head = head->next;          // move head pointer to the next
	delete victim;              //delete marked ListNode
	--_size;                    //decrement size
}


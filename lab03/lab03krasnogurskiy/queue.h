#pragma once
#include "list.h"
using namespace std;

template <typename T>
struct Pair {
	T value;
	int priority;
	Pair();
	Pair(T value_, int priority_);
	~Pair();
	void writeTo(ostream& out) const;
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& P) {
	P.writeTo(out);
	return out;
}

template<typename T>
inline Pair<T>::Pair():value(), priority(0){}

template<typename T>
inline Pair<T>::Pair(T value_, int priority_):value(value_), priority(priority_){}

template<typename T>
inline Pair<T>::~Pair(){}

template<typename T>
inline void Pair<T>::writeTo(ostream& out) const {
	out << value;
}

template <typename T>
class PriorityQueue
{
private:
	List<Pair<T>> element;
public:
	PriorityQueue();
	~PriorityQueue();

	T top();
	int size();
	bool isEmpty();
	void enQueue(T value, int priority);
	T deQueue(); 
	void emptyQueue();
	void printQueue();
};

template<typename T>
inline PriorityQueue<T>::PriorityQueue():element(){}

template<typename T>
inline PriorityQueue<T>::~PriorityQueue(){
	emptyQueue();
}

template<typename T>
inline T PriorityQueue<T>::top()
{
	if (isEmpty()) {
		throw "Queue is empty";
	}
	return element.begin()->value.value;
}

template<typename T>
inline int PriorityQueue<T>::size()
{
	return element.sizeList();
}

template<typename T>
inline bool PriorityQueue<T>::isEmpty()
{
	return element.isEmpty();
}

template<typename T>
inline void PriorityQueue<T>::enQueue(T value, int priority)
{
	if (element.isEmpty()) {
		element.addFront(Pair<T>(value, priority));
	}
	else if (priority<element.begin()->value.priority) {
		element.addFront(Pair<T>(value, priority));

	}
	else if (priority > element.end()->value.priority || priority == element.end()->value.priority) {
		element.addFront(Pair<T>(value, priority));
	}
	else {
		Node<Pair<T>>* temp = element.begin();
		int i = 0;
		while (temp->link != nullptr && priority >= temp->value.priority) {
			temp = element.move(i);
			++i;
		}
		element.insert(Pair<T>(value, priority), temp);
		temp = nullptr;
	}
}

template<typename T>
inline T PriorityQueue<T>::deQueue()
{
	if (isEmpty()) {
		throw "Queue is empty!";
	}
	else {
		return element.del(0)->value.value; //
	}
}

template<typename T>
inline void PriorityQueue<T>::emptyQueue()
{
	element.emptyList(); 
}

template<typename T>
inline void PriorityQueue<T>::printQueue()
{
	element.print();
}
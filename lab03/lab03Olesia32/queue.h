#pragma once
#include "list.h"

template <typename T>
struct Pair {
	T value;
	int priority;
	Pair();
	Pair(T _value, int _priority);
	~Pair();
	void WriteTo(std::ostream& out) const;
};

template <typename T>
void Pair<T>::WriteTo(std::ostream& out) const {
	out << value;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& P) {
	P.WriteTo(out);
	return out;
}

template <typename T>
Pair<T>::Pair() : value(), priority(0) {}

template <typename T>
Pair<T>::Pair(T _value, int _priority) : value(_value), priority(_priority) {}

template <typename T>
Pair<T>::~Pair() {}

template <typename T>
class PriorityQueue {
private:
	List<Pair<T>> element;
public:
	PriorityQueue();
	~PriorityQueue();
	int Size();
	T Top();
	bool IsEmpty();
	void Enqueue(T value, int priority);
	void PrintQueue();
	T Dequeue();
	void EmptyQueue();

};

template <typename T>
PriorityQueue<T>::PriorityQueue() : element() {};

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
	EmptyQueue();
}

template <typename T>
int PriorityQueue<T>::Size() {
	return element.SizeList();
}
template <typename T>
T PriorityQueue<T>::Top() {
	if (IsEmpty()) {
		throw "Queue is empty";
	}
	return element.Begin()->value.value;
}
template <typename T>
bool PriorityQueue<T>::IsEmpty() {
	return element.IsEmpty();
}
template <typename T>
void PriorityQueue<T>::Enqueue(T value, int priority) {
	if (element.IsEmpty()) {
		element.AddFront(Pair<T>(value, priority));
	}
	else if (priority < element.Begin()->value.priority) {
		element.AddFront(Pair<T>(value, priority));
	}
	else if (priority > element.End()->value.priority || priority == element.End()->value.priority) {
		element.AddBack(Pair<T>(value, priority));
	}
	else {
		Node<Pair<T>>* temp = element.Begin();
		int i = 0;
		while (temp->link != nullptr && priority >= temp->value.priority) {
			temp = element.Move(i);
			++i;
		}
		element.Insert(Pair<T>(value, priority), temp);
		temp = nullptr;
	}
}

template<typename T>
void PriorityQueue<T>::PrintQueue() {
	element.Print();
}

template<typename T>
T PriorityQueue<T>::Dequeue() {
	if (IsEmpty()) {
		throw "Queue is empty";
	}
	else {
		return element.Del(0)->value.value;
	}
}

template<typename T>
void PriorityQueue<T>::EmptyQueue() {
	element.EmptyList();
}




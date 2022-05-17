#pragma once
#include "list.h"

template <typename T>
struct Pair {
	T data;
	int priority;
	Pair();
	Pair(T val, int prio);
	~Pair();
	void WriteTo(std::ostream& out) const;
};

template <typename T>
void Pair<T>::WriteTo(std::ostream& out) const {
	out << data;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& P) {
	P.WriteTo(out);
	return out;
}

template <typename T>
Pair<T>::Pair() : data(), priority(0) {}

template <typename T>
Pair<T>::Pair(T val, int prio) : data(val), priority(prio) {}

template <typename T>
Pair<T>::~Pair() {}

template <typename T>
class PriorityQueue {
private:
	List<Pair<T>> element;
public:
	PriorityQueue();
	~PriorityQueue();

	T top();
	int size();
	bool isEmpty();
	void enqueue(T val, int prio);
	void dequeue();
	void emptyQueue();
	void printQueue();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() : element() {}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
	emptyQueue();
}

template <typename T>
T PriorityQueue<T>::top() {
	if (isEmpty()) {
		throw "Queue is empty";
	}
	return element.showTop()->value.data;
}

template <typename T>
int PriorityQueue<T>::size() {
	return element.sizeList();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
	return element.isEmpty();
}

template <typename T>
void PriorityQueue<T>::enqueue(T val, int prio) {
	if (element.isEmpty()) {
		element.pushFront(Pair<T>(val, prio));
	}
	else if (prio < element.showTop()->value.priority) {
		element.pushFront(Pair<T>(val, prio));
	}
	else if (prio > element.showEnd()->value.priority || prio == element.showEnd()->value.priority) {
		element.pushBack(Pair<T>(val, prio));
	}
	else {
		Node<Pair<T>>* temp = element.showTop();
		int i = 0;
		while (temp->next != nullptr && prio >= temp->value.priority) {
			temp = element.move(i);
			++i;
		}
		element.insert(Pair<T>(val, prio), temp);
		temp = nullptr;
	}
}

template<typename T>
void PriorityQueue<T>::printQueue() {
	element.printList();
}

template<typename T>
void PriorityQueue<T>::dequeue() {
	if (isEmpty()) {
		std::cout << "Queue is empty";
	}
	else {
		element.popFront();//.data
	}
}

template<typename T>
void PriorityQueue<T>::emptyQueue() {
	element.emptyList();
}
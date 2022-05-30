#include "priorityqueue.h"
#include <iostream>

int main() {
	PriorityQueue<int> PQ;
	std::cout << "Return 1 if queue is empty, else return 0: " << PQ.isEmpty() << "\n";
	PQ.enqueue(5, 2);
	PQ.enqueue(4, 3);
	PQ.enqueue(9, 0);
	PQ.enqueue(2, 0);
	PQ.enqueue(10, 1);
	PQ.enqueue(7, 4);
	PQ.print();
	std::cout << '\n';

	std::cout << "Size: " << PQ.size() << "\n\n";
	std::cout << "Top: " << PQ.top() << "\n\n";
	std::cout << "Return 1 if queue is empty, else return 0: " << PQ.isEmpty() << "\n";

	PQ.dequeue();
	PQ.dequeue();
	PQ.dequeue();
	PQ.dequeue();

	PQ.empty();
	PQ.print();
}
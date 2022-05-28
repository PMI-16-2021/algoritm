#include "list.h"
#include "priorityQueue.h"
#include <iostream>

int main() {
	PriorQueue<double> PQ;
	PQ.enqueue(-2, 2);
	PQ.enqueue(11, 1);
	PQ.enqueue(4.1, 2);
	PQ.enqueue(4.2, 2);
	PQ.enqueue(0.6, 1);
	PQ.enqueue(1.5, 3);
	PQ.enqueue(0, 0);
	PQ.enqueue(5.13, 1);
	PQ.enqueue(7, 0);
	PQ.print();
	PQ.dequeue();
	PQ.print();
	system("pause");
	return 0;
}
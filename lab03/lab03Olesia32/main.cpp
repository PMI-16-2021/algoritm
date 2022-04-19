#include "list.h"
#include "queue.h"
#include <iostream>

int main() {
	PriorityQueue<int> P1;
	P1.Enqueue(3, 1);
	P1.Enqueue(4, 2);
	P1.Enqueue(6, 1);
	P1.Enqueue(7, 1);
	P1.Enqueue(1, 2);
	P1.Enqueue(9, 0);
	P1.Enqueue(8, 1);
	P1.Enqueue(5, 0);
	P1.PrintQueue();
	system("pause");
	return 0;
}
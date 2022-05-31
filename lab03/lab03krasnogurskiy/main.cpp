#include<iostream>
#include "list.h"
#include"queue.h"
using namespace std;

int main() {

	PriorityQueue<int> P;
	std::cout << "1 - queue is empty, else - 0: \t" << P.isEmpty() << "\n\n";
	P.enQueue(9, 1);
	P.enQueue(7, 2);
	P.enQueue(4, 1);
	P.enQueue(5, 1);
	P.enQueue(2, 2);
	P.enQueue(7, 0);
	P.enQueue(6, 1);
	P.enQueue(3, 0);
	P.printQueue();
	std::cout << "\n\n1 - queue is empty, else - 0: \t" << P.isEmpty() << "\n\n";

	system("pause");
	return 0;
}
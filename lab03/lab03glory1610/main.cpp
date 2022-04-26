#include<iostream>
#include "PrQueue.h"
using namespace std;

int main() 
{
	PriorityQueue PQ;
	PQ.enqueue(3, 2);
	PQ.enqueue(7, 5);
	PQ.enqueue(9, 11);
	PQ.enqueue(10, 1);
	PQ.enqueue(4, 2);
	PQ.enqueue(1, 4);
	PQ.enqueue(5, 3);
	PQ.dequeue();
	cout << "Size is " << PQ.size() << "\n";
	cout << "Top element is " << PQ.top() << "\n";
	PQ.print();



	system("pause");
	return 0;
}
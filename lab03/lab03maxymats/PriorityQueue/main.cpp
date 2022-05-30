#include<iostream>
#include "PriorityQueue.h"
using namespace std;

int main() 
{
	PriorQueue<int> P1;
	P1.enqueue(2, 3);
	P1.enqueue(3, 1);
	P1.enqueue(4, 5);
	P1.enqueue(7, 2);
	P1.enqueue(1, 4);
	P1.dequeue();
	cout << "Size: " << P1.size() << "\n";
	cout << "Top: " << P1.top() << "\n";
	P1.print();

	system("pause");
	return 0;
}
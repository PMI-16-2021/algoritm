#include<iostream>
#include"list.h"
#include"priority_queue.h"
using namespace std;
int main() {
	PriorityQueue<int> A;
	A.Enqueue(3, 5);
	A.Enqueue(1, 0);
	A.Enqueue(4, 3);
	A.Enqueue(7, 1);
	A.Enqueue(-9, 2);
	A.Enqueue(6, 0);
	A.PrintQueue();
	cout << "Top is: " << A.Top() << endl;
	cout << "Size of Queue = " << A.Size() << "\n\n";
	cout << "Dequeue element: " << A.Dequeue() << endl;	
	A.PrintQueue();
	while (!A.IsEmpty()) {
		A.Dequeue();
	}
	if (A.IsEmpty()) {
		cout << "Queue is empty\n";
	}
	try {
		A.Top();
	}
	catch (const char* msg) {
		cerr << msg << endl;
	}
	system("pause");
	return 0;
}
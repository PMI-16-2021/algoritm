#include <iostream>
#include "queue.h"
using namespace std;

int main() {

	PriorityQueue p;
	p.dequeue();
	p.enqueue(5, 1);
	p.enqueue(4, 3);
	p.enqueue(2, 2);
	p.enqueue(6, 3);
	p.printPriorityQueue();
	cout << "size: " << p.size() << endl;
	cout << "head: " << p.head() << endl;
	p.dequeue();
	p.printPriorityQueue();
	cout << "tail: " << p.taill() << endl;
	cout << "head: " << p.head() << endl;

	system("pause");
	return 0;

}
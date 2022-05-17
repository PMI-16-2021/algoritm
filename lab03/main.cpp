#include "queue.h"
using namespace std;

int main() {
	PriorityQueue<double> Queue;
	cout << "Queue is empty(1), if not(0): " << Queue.isEmpty() << "\n";
	cout << "\n" << "Size: " << Queue.size() << "\n\n";
	Queue.enqueue(14.5, 4);
	Queue.enqueue(4.7, 0);
	Queue.enqueue(11, 2);
	Queue.dequeue();
	Queue.printQueue();
	cout << "\n";
	Queue.enqueue(3.3, 0);
	Queue.enqueue(9.8, 1);
	Queue.enqueue(7.8, 3);
	Queue.printQueue();
	cout << "\n" << "Size: " << Queue.size() << "\n\n";
	cout << "Top: " << Queue.top() << "\n\n";
	cout << "Queue is empty(1), if not(0): " << Queue.isEmpty() << "\n\n";
	Queue.dequeue();
	Queue.dequeue();
	Queue.printQueue();
	cout << "\n";
	Queue.emptyQueue();
	Queue.printQueue();


	return 0;
}
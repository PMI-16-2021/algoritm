#include <iostream>
#include "queue.h"

using namespace std;

int main() {
	QueueP<int> a;
	a.enqueue(44, 4);
	a.enqueue(11, 1);
	a.enqueue(12, 1);
	a.enqueue(21, 2);
	a.enqueue(22, 2);
	a.enqueue(33, 3);
	a.print();
	cout <<'\n' << a.size() << '\n';
	cout << a.dequeue() << '\n';
	a.print();
	
	system("pause");
	return 0;
}
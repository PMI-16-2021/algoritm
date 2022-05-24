#include <iostream>
#include "queue.h"
using namespace std;

int main() {

    PriorityQ prQueue;
    prQueue.enqueue(5, 4);
    prQueue.enqueue(4, 5);
    prQueue.enqueue(3, 3);
    prQueue.enqueue(2, 1);
    prQueue.enqueue(1, 2);

    prQueue.printQ();

    prQueue.dequeue();
    prQueue.dequeue();

    prQueue.printQ();

	system("pause");
	return 0;
}
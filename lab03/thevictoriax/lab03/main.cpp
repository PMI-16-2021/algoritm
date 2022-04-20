#include <iostream>
#include "prQueue.h";
using namespace std;

int main()
{
	PrQueue Q;
	Q.enQueue(5,1);
	Q.enQueue(7,5);
	Q.enQueue(3,2);
	Q.enQueue(11,9);
	Q.enQueue(1,6);
	Q.printQueue();

	Q.deQueue();
	Q.deQueue();
	Q.printQueue();

	system("pause");
	return 0;
}
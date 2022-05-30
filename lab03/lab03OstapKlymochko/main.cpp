#include <iostream>
#include"PriorityQueue.h"
using namespace std;

int main()
{
	PriorityQueue myQ;
	myQ.enqueue(2, 2);
	myQ.enqueue(1, 1);
	cout << myQ.top()<<' '<<myQ.size() << '\n';
	myQ.dequeue();
	cout << myQ.top() << ' ' << myQ.size() << '\n';
	myQ.enqueue(1, 2);
	

}

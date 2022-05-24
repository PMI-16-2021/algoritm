#include<iostream>
#include"List_and_Queue.h"


using namespace std;

int main()
{
	PriorityQueue a;
	cout << a.isEmpty() << endl;
	cout << a.size() << endl;
	for (int i = 0; i < 10; i++)
	{
		a.enqueue(rand(), rand());
	}
	a.print();
	cout << a.isEmpty() << endl;
	cout << a.size() << endl;
	cout << endl << a.dequeue() << endl;
	a.print();
	a.clear();








	system("pause");
	return 0;
}
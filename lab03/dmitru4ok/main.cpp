#include "List.h"
#include "PriorityQueue.h"

using std::cin;
using std::cout;

int main()
{

	PriorityQueue<double> B;
	B.print();
	
	B.enqueue(2.5, 4);
	B.dequeue();

	B.enqueue(3.1, 5);
	B.enqueue(1.33, 3);
	B.enqueue(0.9, 2);
	B.enqueue(1, 0);
	B.enqueue(17.543, 0);
	B.enqueue(-10, 1);
	B.enqueue(3.1, 6);

	cout << "SIZE: " << B.size() << '\n';
	B.print();
	cout << "TOP: " << B.top() << '\n';
	B.print();

	cout << '\n';
	while (!B.isEmpty())
	{
		cout << B.dequeue() << ": ";
		cout << "SIZE: " << B.size() << '\n';
	}

	cout << '\n';
	B.print();




	system("pause");
	return 0;
}

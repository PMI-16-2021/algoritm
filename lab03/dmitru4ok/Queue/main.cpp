#include "List.h"
#include "PriorityQueue.h"

using std::cin;
using std::cout;

int main()
{
	List<Pair,int> A;
	A.addBack(Pair<int>(1));
	if (A.isEmpty()) cout << "OK";

	A.addFront(Pair<int>(3));
	A.addFront(Pair<int>(5));
	A.addFront(Pair<int>(7));
	A.addBack(Pair<int>(2));
	

	A.add(Pair<int>(2), A.getHead());

	A.printList();


	A.printList();
	PriorityQueue<int, Pair> B;

	//Pair<int> a = int(3);
	//cout << a.value;
















	system("pause");
	return 0;
}
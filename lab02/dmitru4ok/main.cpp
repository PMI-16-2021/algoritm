#include <iostream>
#include "SetOfStacks.h"

using std::cout;


int main()
{
	SetOfStacks<char> A(2, 13);
	if (A.completelyEmpty()) cout << "NO ELEMENTS(constructor).\n"; // must work


	A.push('a'); //zero five [0] Stack
	A.push('b');
	A.push('c');
	A.push('d');
	A.push('e');

	A.push('f'); //first five [1] Stack
	A.push('g');
	A.push('h');
	if (A.completelyEmpty()) cout << "NO ELEMENTS.(middle)\n"; //must not work
	A.push('i');
	A.push('e');

	A.push('e');
	A.push('k');

	A.clearSet();
	if (A.completelyEmpty()) cout << "NO ELEMENTS.\n";
	char a = 'z';
	
	while (!A.completelyFull())
	{
		A.push(a);
		--a;
	}
	while (!A.completelyEmpty())
	{
		cout << A.pop() << ' ';
	}
	
	

	




	system("pause");
	return 0;
}
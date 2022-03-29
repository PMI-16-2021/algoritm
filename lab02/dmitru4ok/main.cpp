#include <iostream>
#include "SetOfStacks.h"

using std::cout;


int main()
{
	SetOfStacks<char> A(13, 2);


	//A.push('a'); //zero five [0] Stack
	//A.push('b');
	//A.push('c');
	//A.push('d');
	//A.push('e');

	//A.push('f'); //first five [1] Stack
	//A.push('g');
	//A.push('h');
	//A.push('i');
	//A.push('e');

	//A.push('e');
	//cout << "A.topAt(2): " << A.topAt(2) << '\n';
	//if (A.topAt(1) == A.topAt(2)) cout << "success.\n";

	//A.push('k');
	char a = 'a';
	
	while (!A.completelyFull())
	{
		A.push(a);
		++a;
	}
	while (!A.completelyEmpty())
	{
		cout << A.pop() << ' ';
	}
	
	

	




	system("pause");
	return 0;
}
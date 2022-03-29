#include <iostream>
#include "SetOfStacks.h"

using std::cout;


int main()
{
	SetOfStacks<char> A;


	A.push('a'); //zero five [0] Stack
	A.push('b');
	A.push('c');
	A.push('d');
	A.push('e');

	A.push('f'); //first five [1] Stack
	A.push('g');
	A.push('h');
	A.push('i');
	A.push('j');

	

	A.push('k'); //second five [2] Stack
	A.push('l'); 
	cout << A.popAt(1); //expect j
	cout << A.popAt(1); //expect i
	cout << A.pop();    //expect l
	
	
		
	

	




	system("pause");
	return 0;
}
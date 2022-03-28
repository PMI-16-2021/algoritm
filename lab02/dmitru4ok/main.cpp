#include <iostream>
#include "SetOfStacks.h"

using std::cout;


int main()
{
	SetOfStacks<int> A;

	A.push(5);
	A.push(4);
	A.push(3);
	A.push(2);
	A.push(1);
	A.push(0);
	A.push(-1);
	A.push(-2);
	A.push(-3);
	A.push(-4);
	A.push(-5);

	cout << A.pop(); 
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	cout << A.pop();
	
	try
	{
		cout << A.pop(); //7-th pop
	}
	catch (const char* b)
	{
		cout << b;
	}
	








	


	system("pause");
	return 0;
}
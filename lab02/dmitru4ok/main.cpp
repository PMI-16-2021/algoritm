#include <iostream>
#include "Stack.h";

using std::cout;


int main()
{
	Stack myStack;
	for (int i = 0; i < 6; ++i)
	{
		myStack.push(i);
	}
	cout << "Size: " << myStack.size() << "Top element:" << myStack.top() << '\n';

	while (!myStack.empty())
	{
		cout << myStack.pop() << '\n';
	}
	cout << "Size: " << myStack.size() << '\n';
	
	













	system("pause");
	return 0;
}
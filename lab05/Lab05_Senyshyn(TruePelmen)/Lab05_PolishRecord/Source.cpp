#include<iostream>
#include"stack.h"
#include"PolishNotation.h"

using namespace std;

int main()
{
	/*
	Stack<int> a;
	cout << a.IsEmpty() << endl;
	a.Push(1);
	cout << a.Top() << endl;
	cout << a.IsEmpty();
	*/
	string exp1;
	cout << "Your expression: " << endl;
	cin >> exp1;
	string example = "28+9*(44-2)-6^2"; 
	cout << "Your expression in reverse polish notation " << toPostFix(exp1) << '\n';
	cout << "Your result : " << Counting(toPostFix(exp1)) << "\n";











	system("pause");
	return 0;
}
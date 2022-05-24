#include <iostream>
#include "polish.h"
#include "Stack.h"
using namespace std;

int main() {
	
	string expression = "(3+4)*5-6/2+7";
	string reverse = reversePolish(expression);
	
	cout << "Reverse polish notation: " << reverse << endl;
	cout << "Result: " << calculate(reverse) << endl;


	system("pause");
	return 0;
}
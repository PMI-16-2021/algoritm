#include <iostream>
#include "PolishRecord.h"
#include "Stack.h"
using namespace std;

int main() {

	string expression = "(6+9)*5-3/2+5";
	string reverse = reversePolish(expression);

	cout << "Reverse polish notation: " << reverse << endl;
	cout << "Result: " << calculate(reverse) << endl;


	system("pause");
	return 0;
}
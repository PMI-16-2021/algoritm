#include <iostream>
#include "polish.h"
#include <stack>
#include <string>
using namespace std;

int main() {
	char input[100];
	cout << "Enter an expression: ";
	cin >> input;
	string postfix = to_postfix(input);
	cout << "Postfix is: " << postfix << endl;
	cout << "Result: " << calc(postfix);
	cout << endl;
	std::string p = "26+89*+";
	size_t u=calc(p);
	cout << u <<endl;
	system("pause");
	return 0;
}
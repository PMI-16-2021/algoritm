#include <iostream>
#include<string>
#include "Function.h"
using namespace std;

int main() {
	string exp = "(22-5)*10+5";
	cout << "Expression:  " << ReversePN(exp) << '\n';
	cout << "Answer:  " << calculate(ReversePN(exp)) << "\n\n";

	string ex = "(15+5)/2*3-5";
	cout << "Expression:  " << ReversePN(ex) << '\n';
	cout << "Answer:  " << calculate(ReversePN(ex)) << "\n";
	system("pause");
	return 0;
}
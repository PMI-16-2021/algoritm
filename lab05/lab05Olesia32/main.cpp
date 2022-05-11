#include "stack.h"
#include "functions.h"
#include <string>
#include <iostream>

int main() { 
	std::string example = "(12*(9-3)-3*(5+6))/3+2^3";
	std::cout << ReversePolishNotation(example) << '\n';
	std::cout << Calculate(ReversePolishNotation(example));
	system("pause");
	return 0;
}
#include "functions.h"
#include "stack.h"
#include <string>
#include <cmath>

bool IsDigit(char c) {
	switch (c) {
	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
		return true;
	default:
		return false;
	}
}
bool IsOperator(char c) {
	switch (c) {
	case '+': case '-': case '*': case '/': case '^':
		return true;
	default:
		return false;
	}
}

int Priority(char c) {
	switch (c) {
	case '^': 
		return 3;
	case '*': case '/':
		return 2;
	case '+': case '-':
		return 1;
	default:
		return -1;
	}
}

std::string ReversePolishNotation(std::string expression) {
	Stack<char> stack;
	std::string result;
	for (int i = 0; i < expression.length(); ++i) {
		char temp = expression[i];
		if (IsDigit(temp)) {
			result += temp;
			if (!IsDigit(expression[i + 1])) {
				result += ' ';
			}
		}
		else if (temp == '(') {
			stack.Push(temp);
		}
		else if (temp == ')') {
			while (stack.Top() != '(') {
				result += stack.Top();
				stack.Pop();
				result += ' ';
			}
			stack.Pop();
		}
		else {
			while (!stack.IsEmpty() && Priority(expression[i]) <= Priority(stack.Top())) {
				result += stack.Pop();
				result += ' ';
			}
			stack.Push(temp);
		}
	}
	while (!stack.IsEmpty()) {
		result += stack.Pop();
	}
	return result;
}

double Calculate(std::string expression) {
	double first, second;
	double result;
	first = second = result = 0;
	std::string tok = "";
	Stack<std::string> stack;
	for (int i = 0; i < expression.length(); ++i) {
		while (expression[i] == ' ') {
			++i;
		}
		if (IsDigit(expression[i])) {
			while (IsDigit(expression[i])) {
				tok += expression[i];
				++i;
			}
			stack.Push(tok.c_str());
			tok = "";
		}
		else if (IsOperator(expression[i])) {
			first = std::stod(stack.Pop());
			second = std::stod(stack.Pop());
			if (expression[i] == '+') {
				result = (first + second);
			}
			if (expression[i] == '-') {
				result = second - first;
			}
			if (expression[i] == '*') {
				result = (first * second);
			}
			if (expression[i] == '/') {
				if (first == 0) {
					throw "Division by 0 is not possible";
				}
				result = (second / first);
			}
			if (expression[i] == '^') {
				result = pow(second, first);
			}
			stack.Push(std::to_string(result));
		}
		else {
			std::cout << "Invaild Expression." << '\n';
			break;
		}
	}
	return std::stod(stack.Pop());
}
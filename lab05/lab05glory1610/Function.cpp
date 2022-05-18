#include "Function.h"

bool isOperator(char c) {
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
		return true;
	default:
		return false;
	}
}
bool isDigit(char c) {
	switch (c) {
	case '0': 
	case '1': 
	case '2': 
	case '3': 
	case '4': 
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return true;
	default:
		return false;
	}
}
int priority(char c) {
	switch (c) {
	case '*': 
	case '/': 
		return 2;
	case '+': 
	case '-': 
		return 1;
	case '(': 
	case ')': 
		return 0;
	default:
		return -1;
	}
}
std::string ReversePN(std::string expression) {
	Stack stack; 
	std::string result;
    for (int i = 0; i < expression.length(); ++i) {
		if (isDigit(expression[i])) {
			result += expression[i];
			if (!isDigit(expression[i + 1])) {
				result += ' ';
			}
		}
		else if (expression[i] == '(') {
			stack.push(expression[i]);
		}
		else if (expression[i] == ')') {
			while (stack.top() != '(') {
				result += stack.top();
				stack.pop();
				result += ' ';
			}
			stack.pop();
		}
		else {
			while (!stack.empty() && priority(expression[i]) <= priority(stack.top())) {
					result += stack.pop();
					result += ' ';
			}
			stack.push(expression[i]);
		}
	}
	while (!stack.empty()) {
		result += stack.pop();
	}
	return result;
}

double calculate(std::string expression) {
	Stack stack;
	int left, right;
	for (int i = 0; i < expression.length(); ++i) {
		if (isdigit(expression[i])) {
			int temp = expression[i] - '0';
			if (isdigit(expression[i + 1])) {
				int b = i + 1;
				while (isdigit(expression[b])) {
					temp = temp * 10 + (expression[i + 1] - '0');
					++b;
				}
				stack.push(temp);
				++i;
			}
			else {
				stack.push(temp);
			}
			++i;
		}
		else if (expression[i] == '+') {
			left = stack.top();
			stack.pop();
			right = stack.top();
			stack.push(left + right);
			++i;
		}
		else if (expression[i] == '-') {
			left = stack.top();
			stack.pop();
			right = stack.top();
			stack.push(right - left);
			++i;
		}
		else if (expression[i] == '*') {
			left = stack.top();
			stack.pop();
			right = stack.top();
			stack.push(left * right);
			++i;
		}
		else if (expression[i] == '/') {
			left = stack.top();
			stack.pop();
			right = stack.top();
			if (left == 0)
			{
				break;
			}
			else
				stack.push(right / left);
			++i;
		}
		else if (expression[i] == ' ') {
		    ++i;
		}
	}
	return stack.top();
}

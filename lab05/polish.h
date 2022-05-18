#pragma once
#include <string>
#include "stack.h"
using namespace std;

bool isOperator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

bool isNumber(char n) {
	return n >= '0' && n <= '9';
}

int priority(char pr) {
	switch (pr) {
	case '(':
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}
}

std::string polishRecord(std::string expression) {
	Stack<char> stack;
	std::string res;
	for (int i = 0; i < expression.length(); ++i) {
		char temp = expression[i];
		if (isNumber(temp)) {
			res += temp;
			if (!isNumber(expression[i + 1])) {
				res += ' ';
			}
		}
		else if (temp == '(') {
			stack.push(temp);
		}
		else if (temp == ')') {
			while (stack.showTop() != '(') {
				res += stack.showTop();
				stack.pop();
				res += ' ';
			}
			stack.pop();
		}
		else {
			while (!stack.isEmpty() && priority(expression[i]) <= priority(stack.showTop())) {
				res += stack.showTop();
				stack.pop();
				res += ' ';
			}
			stack.push(temp);
		}
	}
	while (!stack.isEmpty()) {
		res += stack.showTop();
		stack.pop();
	}
	return res;
}

double calculate(std::string expression) {
	double right, left;
	double res;
	left = right = res = 0;
	std::string tok = "";
	Stack<std::string> stack;
	for (int i = 0; i < expression.length(); ++i) {
		while (expression[i] == ' ') {
			++i;
		}
		if (isNumber(expression[i])) {
			while (isNumber(expression[i])) {
				tok += expression[i];
				++i;
			}
			stack.push(tok.c_str());
			tok = "";
		}
		else if (isOperator(expression[i])) {
			right = std::stod(stack.showTop());
			stack.pop();
			left = std::stod(stack.showTop());
			stack.pop();
			if (expression[i] == '+') {
				res = (left + right);
			}
			if (expression[i] == '-') {
				res = left - right;
			}
			if (expression[i] == '*') {
				res = (left * right);
			}
			if (expression[i] == '/') {
				if (right == 0) {
					throw "Error, incorrect division";
				}
				res = (left / right);
			}
			stack.push(std::to_string(res));
		}
		else {
			std::cout << "Fail calculate expression" << '\n';
			break;
		}
	}
	return std::stod(stack.showTop());
}

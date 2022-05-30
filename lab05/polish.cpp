#include "polish.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;


bool is_digit(char c) {
	return c >= '0' && c <= '9';
}

size_t calc(string polish) {
	size_t res;
	stack <size_t> elements;
	for (size_t i = 0; i < polish.length(); i++) {
		char c = polish[i];
		if (c == '+' || c == '-' || c == '*' || c == '/') {
			size_t right = elements.top();
			elements.pop();
			size_t left = elements.top();
			elements.pop();
			switch (c) {
			case '+':elements.push(left + right); break;
			case '-':elements.push(left - right); break;
			case '*':elements.push(left * right); break;
			case '/':elements.push(left / right); break;
			}
		}
		else {
			size_t n = c - '0';
			elements.push(n);
		}
	}
	if (elements.size() == 1) {
		res = elements.top();
		return res;
	}
}

size_t compare_operators(char op1, char op2) {
	if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) { return -1; }//* +
	else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) { return 1; }//+ *
	return 0;
}

bool is_operator(char character) {
	if (character == '+' || character == '-' || character == '*' || character == '/') {
		return true;
	}
	return false;
}

bool is_operand(char character) {
	if (!is_operator(character) && character != '(' && character != ')') {
		return true;
	}
	return false;
}

string to_postfix(char* input) {
	stack<char> in_stack;
	string postfix_string = "";
	char* ellement = input;
	while (*ellement != '\0') {
		if (is_operand(*ellement)) {
			postfix_string += *ellement;
		}
		else if (is_operator(*ellement)) {
			while (!in_stack.empty() && in_stack.top() != '(' && compare_operators(in_stack.top(), *ellement) <= 0) {
				postfix_string += in_stack.top();
				in_stack.pop();
			}
			in_stack.push(*ellement);
		}
		else if (*ellement == '(') {
			in_stack.push(*ellement);
		}
		else if (*ellement == ')') {
			while (!in_stack.empty()) {
				if (in_stack.top() == '(') { in_stack.pop(); break; }
				postfix_string += in_stack.top();
				in_stack.pop();
			}
		}
		ellement++;
	}
	while (!in_stack.empty()) {
		postfix_string += in_stack.top();
		in_stack.pop();
	}
	return postfix_string;
}
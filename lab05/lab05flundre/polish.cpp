
#include "polish.h"

#include "Stack.h"

bool isDigit(char l)
{
	switch (l) {
	case '0':
		return true;
	case '1':
		return true;
	case '2':
		return true;
	case '3':
		return true;
	case '4':
		return true;
	case '5':
		return true;
	case '6':
		return true;
	case '7':
		return true;
	case '8':
		return true;
	case '9':
		return true;
	default:
		return false;
	}
}

bool isFunc(char l)
{
	switch (l) {
	case('+'):
		return true;
	case('-'):
		return true;
	case('*'):
		return true;
	case('/'):
		return true;
	case('^'):
		return true;
	default:
		return false;
	}
}

size_t getPriority(char l)
{
	switch (l) {
	case('+'):
		return 1;
	case('-'):
		return 1;
	case('*'):
		return 2;
	case('/'):
		return 2;
	case('^'):
		return 3;
	default:
		return -1;
	}
}

std::string getReversedPolishNotation(std::string s)
{
	Stack<char> stack;
	std::string result;
	for (int i = 0; i < s.length(); ++i) {
		char l = s[i]; // 1 / +
		if (isDigit(l)) { // 1
			result += l; // res=1
			if (!isDigit(s[i + 1])) {
				result += ' ';
			}
		}
		else if (l == '(') { // (
			stack.push(l);
		}
		else if (l == ')') {
			while (stack.top() != '(') {
				result += stack.pop(); // () containmetnt 
				result += ' ';
			}
			stack.pop(); // pop (
		}
		else {
			while ((!stack.empty()) && (getPriority(l) <= getPriority(stack.top()))) { // +
				result += stack.pop(); 
				result += ' ';
			}
			stack.push(l);
		}
	}
	while (!stack.empty()) {
		result += stack.pop(); // whole expr
	}

	return result;
}

double calculateReversedPolishNotation(std::string s)
{
	double a, b, result = 0;
	std::string temp = "";
	Stack<std::string> stack;
	for (int i = 0; i < s.length(); ++i) {
		
		while (s[i] == ' ') { // skipping
				++i;
		}
		if (isDigit(s[i])) {
				while (isDigit(s[i])) { 
					temp += s[i];
					++i;
				}
				stack.push(temp.c_str()); // saving numbs
				temp = "";
		}
		else if (isFunc(s[i])) {
				a = std::stod(stack.pop()); // string to double
				b = std::stod(stack.pop()); // variables
			if (s[i] == '+') {  // functioning
				result = a + b;
			}
			if (s[i] == '-') {
				result = a - b;
			}
			if (s[i] == '*') {
				result = (a * b);
			}
			if (s[i] == '/') {
				if (a == 0) {
					a = 1;
				}
				result = (b / a);
			}
			if (s[i] == '^') {
				result = pow(b, a);
			}
			stack.push(std::to_string(result)); // saving result(in string -> stack<string>)
	    }
		else {
		std::cerr << "ERROR: Wrong expression input" << '\n'; // if polish rev notation logic was not followed
		break;
		}
	}
	return std::stod(stack.pop()); // returning result (stack<string>.result-> double)
}


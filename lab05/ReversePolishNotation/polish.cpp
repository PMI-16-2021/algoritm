#include"polish.h"
#include"stack.h"
#include <string>

int GetPriority(char a) {
	switch (a) {
	case '^':
		return 0;
	case '(':
	case ')':
		return 1;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 3;
	default: return -1;
	}
}
bool IsDigit(char a) {
	return (a >= '0' && a <= '9');
}
bool IsOperator(char a) {
	switch (a) {
	case '-': case '+': case '/': case '*': case '^':
		return true;
	default:
		return false;
	}
}
std::string PolishRecord(std::string n) {
	std::string temp;
	Stack<char> my_stack;
	for (int i = 0; i < n.length(); i++) {
		if (IsDigit(n[i])) {
			while (IsDigit(n[i + 1]) && i < n.length()) {
				temp += n[i];
				++i;
			}
			temp += n[i];
			temp += ' ';
		}
		else if (n[i] == '(') {
			my_stack.Push(n[i]);
		}
		else if (n[i] == ')') {
			while (my_stack.Top() != '(') {
				temp += my_stack.Pop();
			}
			my_stack.Pop();
		}
		else if (IsOperator(n[i])) {
			if (my_stack.Empty()) {
				my_stack.Push(n[i]);
				continue;
			}
			else if (GetPriority(n[i]) < GetPriority(my_stack.Top())) {
				my_stack.Push(n[i]);
			}
			else if (GetPriority(n[i]) >= GetPriority(my_stack.Top())) {
				while (!my_stack.Empty() && (GetPriority(n[i]) >= GetPriority(my_stack.Top()) && my_stack.Top() != '(')) {
					temp += my_stack.Pop();
				}
				my_stack.Push(n[i]);
			}
		}
	}
	while (!my_stack.Empty()) {
		temp += my_stack.Pop();
	}
	return temp;
}
int Calculate(std::string e) {
	Stack<std::string> my_stack;
	std::string temp;
	double result = 0;
	for (int i = 0; i < e.length(); ++i) {
		while (e[i] == ' ') {
			++i;
		}
		if (IsDigit(e[i])) {
			while (IsDigit(e[i])) {
				temp += e[i];
				++i;
			}
			my_stack.Push(temp.c_str());
			temp = "";
		}
		else if (IsOperator(e[i])) {
			double a = std::stod(my_stack.Pop());
			double b = std::stod(my_stack.Pop());
			switch (e[i]) {
			case '^':
				result = (pow(b, a));
			case '/':
				result = (b / a);
				break;
			case '*':
				result = (b * a);
				break;
			case '-':
				result = (b - a);
				break;
			case '+':
				result = (b + a);
				break;
			default:
				std::cerr << "Bad operator\n";
			}
			my_stack.Push(std::to_string(result));
		}
	}
	return std::stod(my_stack.Pop());
}	
#include "polish.h"
#include "Stack.h"
#include <cmath>
using namespace std;

bool isNumber(char n) {
	return n == '0' || n == '1' || n == '2' || n == '3' || n == '4' || n == '5' || n == '6' || n == '7' || n == '8' || n == '9';
}

bool isOperator(char o) {
	return o == '+' || o == '-' || o == '*' || o == '/' || o == '^';
}

int priority(char p) {
	switch (p) {
	case '+': case '-':
		return 1;
	case '*': case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

string reversePolish(string expr) {
	Stack<char> st;
	string res;
	for (int i = 0; i < expr.length(); ++i) {
		char temp = expr[i];
		if (isNumber(temp)) {
			res += temp;
			if (!isNumber(expr[i + 1])) {
				res += ' ';
			}
		}
		else if (temp == '(') {
			st.push(temp);
		}
		else if (temp == ')') {
			while (st.stackTop() != '(') {
				res += st.stackTop();
				st.pop();
				res += ' ';
			}
			st.pop();
		}
		else {
			while (!st.isEmpty() && priority(expr[i]) <= priority(st.stackTop())) {
				res += st.pop();
				res += ' ';
			}
			st.push(temp);
		}
	}
	while (!st.isEmpty()) {
		res += st.pop();
	}
	return res;
}

double calculate(string expr) {
	double n1 = 0, n2 = 0, res = 0;
	string tok = "";
	Stack<string> st;
	for (int i = 0; i < expr.length(); ++i) {
		while (expr[i] == ' ') {
			++i;
		}
		if (isNumber(expr[i])) {
			while (isNumber(expr[i])) {
				tok += expr[i];
				++i;
			}
			st.push(tok.c_str());
			tok = "";
		}
		else if (isOperator(expr[i])) {
			n1 = stod(st.pop());
			n2 = stod(st.pop());
			if (expr[i] == '+') {
				res = (n2 + n1);
			}
			if (expr[i] == '-') {
				res = n2 - n1;
			}
			if (expr[i] == '*') {
				res = (n2 * n1);
			}
			if (expr[i] == '/') {
				if (n1 == 0) {
					throw "Cannot divide by 0";
				}
				res = (n2 / n1);
			}
			st.push(to_string(res));
		}
			
		else {
			cout << "Error." << '\n';
			break;
		}
	}
	return stod(st.pop());
}
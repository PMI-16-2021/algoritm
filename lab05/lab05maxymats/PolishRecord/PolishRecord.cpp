#include "PolishRecord.h"
#include "Stack.h"
#include <cmath>
using namespace std;

bool isNumber(char m) {
	return m == '0' || m == '1' || m == '2' || m == '3' || m == '4' || m == '5' || m == '6' || m == '7' || m == '8' || m == '9';
}

bool isOperator(char a) {
	return a == '+' || a == '-' || a == '*' || a == '/' || a == '^';
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
	double a1 = 0, a2 = 0, res = 0;
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
			a1 = stod(st.pop());
			a2 = stod(st.pop());
			if (expr[i] == '+') {
				res = (a2 + a1);
			}
			if (expr[i] == '-') {
				res = a2 - a1;
			}
			if (expr[i] == '*') {
				res = (a2 * a1);
			}
			if (expr[i] == '/') {
				if (a1 == 0) {
					throw "Cannot divide by 0";
				}
				res = (a2 / a1);
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
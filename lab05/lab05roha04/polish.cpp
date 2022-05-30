#include"PolishNotation.h"
#include <string>
using namespace std;



std::string ToPostfix(std::string st) {
	std::string dest;
	Stack<char> myStack;
	myStack.Push('#');
	for (int i = 0; i < st.length(); ++i) {
		char temp = st[i];
		
		if (IsDigital(temp)) {
			dest += temp; 
			if (!IsDigital(st[i + 1])) {
				dest += ' ';
			}
		}
		else {
			int p = Priority(temp);
			switch (temp) {
			case '+': case '-': case '*': case '/':
				while (Priority(myStack.TopS()) >= p) {
					
					dest += myStack.TopS();
					myStack.Pop();
				}
				myStack.Push(temp);
				break;
			case '(':      
				myStack.Push(temp);
				break;
			case ')':     
				while (myStack.TopS() != '(') {
					dest += myStack.TopS();
					myStack.Pop();
					dest += ' ';
				}          
				myStack.Pop();
				break;
			default:
				while (!myStack.IsEmpty() && Priority(st[i]) <= Priority(myStack.TopS())) {
					dest += myStack.Pop();
					dest += ' ';
				}
				myStack.Push(temp);
			}
		}
	}
	while (myStack.TopS() != '#') {
		
		dest += myStack.TopS();
		myStack.Pop();
	}
	return dest;
}
int Priority(char c) {
	switch (c) {
	case '^': return 3;
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	case '#': case '(': case ')': return 0;
	default: return 10;
	}
}
bool IsDigital(char ch) {
	return (ch >= '0' && ch <= '9');
}
bool IsOperator(char c) {
	switch (c) {
	case '+': case '-': case '*': case '/': case '^':
		return true;
	default:
		return false;
	}
}
int Calculate(std::string expr) {
	Stack<std::string> myStack;
	std::string temp = "";
	double result = 0;
	for (int i = 0; i < expr.length(); ++i) {
		while (expr[i] == ' ') {
			++i;
		}
		if (IsDigital(expr[i])) {
			while (IsDigital(expr[i])) {
				temp += expr[i];
				++i;
			}
			myStack.Push(temp.c_str());
			temp = "";
		}
		else if (IsOperator(expr[i])) {
			double right = std::stod(myStack.Pop());
			
			double left = std::stod(myStack.Pop());
			
			switch (expr[i]) {
			case '+':
				result = (left + right);
				break;
			case '-':
				result = (left - right);
				break;
			case '*':
				result = (left * right);
				break;
			case '/':
				result = (left / right);
				break;
			case '^':
				result = (pow(left, right));

			}
			myStack.Push(std::to_string(result));
		}
	}
	return std::stod(myStack.Pop());
}
void TranslateAndCalculate() {
	std::string source, dest;
	std::cout << "Write example:\n";
	std::getline(std::cin, source);
	if (source.empty()) return;
	dest = ToPostfix(source);
	std::cout << "Polish : " << dest << '\n';
	std::cout << "Value = " << Calculate(dest) << "\n\n";

}
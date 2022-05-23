#include "postfix.h"
#include <string>


//------------------------POLISH------------------------------
std::string ToPostfix(std::string st) {
	std::string dest;
	Stack<char> myStack;
	myStack.push('#');
	for (int i = 0; i < st.length(); ++i) {
		char temp = st[i];
		// аналізуємо кожну літеру заданого рядка
		if (IsDigital(temp)) {
			dest += temp; // операнд -> результуючий рядок
			if (!IsDigital(st[i + 1])) {
				dest += ' ';
			}
		}
		else{
			int p = Priority(temp);
			switch (temp) {
			case '+': case '-': case '*': case '/':
				while (Priority(myStack.topS()) >= p){         
					// старші операції полишають стек
					dest += myStack.topS();
					myStack.pop();
				}
				myStack.push(temp);
				break;
			case '(':      // початок пріоритетної частини
				myStack.push(temp);
				break;
			case ')':      // закінчення пріоритетної частини
				while (myStack.topS() != '('){
					dest += myStack.topS();
					myStack.pop();
					dest += ' ';
				}           // дужку теж треба забрати
				myStack.pop(); 
				break;
			default:
				while (!myStack.isEmpty() && Priority(st[i]) <= Priority(myStack.topS())) {
					dest += myStack.pop();
					dest += ' ';
				}
				myStack.push(temp);
			} 
		} 
	} 
	while (myStack.topS() != '#'){   
		// решта операцій до результуючого рядка
		dest += myStack.topS();
		myStack.pop();
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
			myStack.push(temp.c_str());
			temp = "";
		}
		else if(IsOperator(expr[i])) {
			double right = std::stod(myStack.pop()); 
			//myStack.pop();
			double left = std::stod(myStack.pop());
			//myStack.pop();
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
			myStack.push(std::to_string(result));
		}
	}
	return std::stod(myStack.pop());
}
void TranslateAndCalculate() {
	std::string source, dest;
	std::cout << "Write expression:\n";
	std::getline(std::cin, source);
	if (source.empty()) return;
		dest = ToPostfix(source);
		std::cout << "Polish notation: " << dest << '\n';
		std::cout << "Value = " << Calculate(dest) << "\n\n";
	
}
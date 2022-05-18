#include "stack.h"
#include "polish.h"

int main(){
	cout << "Enter expression: ";
	string expression;
	cin >> expression;
	cout << "Reverse polish record: " << polishRecord(expression) << '\n';
	cout << "Answer: " << calculate(polishRecord(expression));
	
	return 0;
}
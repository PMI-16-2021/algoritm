
#include <iostream>
#include "Stack.h"

int main()
{
    string infix;
    cout << "Enter infix form of expression: ";
    cin >> infix;
    cout << "Postfix form of expression: " << infixToPostfix(infix) << endl;
    cout << "Result is: " << action(infixToPostfix(infix)) << endl;
}


#include <iostream>
#include "Stack.h"

int main()
{
    std::string infix;
    std::cout << "Enter infix form of expression: ";
    std::cin >> infix;
    std::cout << "Postfix form of expression: " << infixToPostfix(infix) << std::endl;
    std::cout << "Result is: " << action(infixToPostfix(infix)) << std::endl;
}


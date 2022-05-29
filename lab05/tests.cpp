#include "tests.h"

bool testIsOperator()
{
    char operators[5] = { '+', '-', '*', '/', '^' };
    for (int i = 0; i < 5; ++i)
    {
        if (isOperator(operators[i]))
            return true;
    }
    return false;
}

void resultIsOperator()
{
    assert(testIsOperator() == true);
    std::cout << "Test isOperator is passed\n";
}

bool testIsOperand()
{
    char operands[9] = {'1', '2', '3', '4', '5' ,'6' ,'7', '8','9'};
    for (int i = 0; i < 5; ++i)
    {
        if (isOperand(operands[i]))
            return true;
    }
    return false;

}
void resultIsOperand()
{
    assert(testIsOperand() == true);
    std::cout << "Test isOperand is passed\n";
}

bool testOperation()
{
    int a = operation(1, 2, '+');
    int b = operation(1, 2, '-');
    int c = operation(2, 3, '*');
    int d = operation(3, 6, '/');
    int e = operation(3, 2, '^');
    if (a==3 && b==1 && c==6 && d==2 && e==8)
        return true;
    return false;

}

void resultOperation()
{
    assert(testOperation() == true);
    std::cout << "Test operation is passed\n";
}

bool testPriority()
{
    if (priority('-')==1 && priority('+')==1 && priority('*')==2 && priority('/')==2 && priority('^')==3)
        return true;
    return false;
}

void resultPriority()
{
    assert(testPriority() == true);
    std::cout << "Test priority is passed\n";
}

bool testInfixToPostfix()
{
    std::string a = "23+";
    std::string b = infixToPostfix("+23");
    if (a == b)
        return true;
    return false;
}

void resultInfixToPostfix()
{
    assert(testInfixToPostfix() == true);
    std::cout << "Test infixToPostfix is passed\n";
}

bool testPostfixCalculate()
{
    int a = postfixCalculate("23+51-*");
    if (a == 20)
        return true;
    return false;
}

void resultPostfixCalculate()
{
    assert(testPostfixCalculate() == true);
    std::cout << "Test postfixCalculate is passed\n";
}


#include <iostream>
#include "functions.h"
#include "tests.h"
using namespace std;

int main() {

    resultIsOperator();
    resultIsOperand();
    resultOperation();
    resultPriority();
    resultInfixToPostfix();
    resultPostfixCalculate();
    cout << "\n";
    cout << "The result is: " << postfixCalculate("53+62/*35*+") << '\n';
    cout << "The result is: " << postfixCalculate("93/3^") << '\n';
    cout << "The result is: " << postfixCalculate("(-1)1+(-3)(-7)+-") << '\n';

    return 0;
}

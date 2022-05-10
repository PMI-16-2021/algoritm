
#include"Stack.h"
using namespace std;



int main()
{
    Stack Expression;
    cout << "Enter infix notation: ";
    cin >> infix;
    Expression.Infix_to_Postfix();
    cout << "Your expression in postfix: " << postfix << endl;
    cout << "Result: " << Expression.CountExpression() << endl;

    return 0;
}
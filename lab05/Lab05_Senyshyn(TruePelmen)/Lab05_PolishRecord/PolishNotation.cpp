#include"PolishNotation.h"
#include<string>

using namespace std;

int Priority(char letter)
{
    switch (letter)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^': return 3;
    default:
        return -1;
    }
}

bool Operation(char letter)
{
    switch (letter)
    {
    case '+': case '-': case '*': case '/': case '^':
        return true;
    default:
        return false;
    }
}
bool Number(char letter)
{
    return (letter >= '0' && letter <= '9');
}
string toPostFix(string expression)
{
    Stack<char> stack;
    string res;
    for (int i = 0; i < expression.length(); ++i)
    {
        char temp = expression[i];
        if (Number(temp))
        {
            res += temp;
            if (!Number(expression[i + 1]))
            {
                res += '_';
            }
        }
        else
        {
            switch (temp)
            {
            case '(':
                stack.Push(temp);
            case ')':
                while (stack.Top() != '(')
                {
                    res += stack.Top();
                    stack.Pop();
                    res += '_';
                }
                stack.Pop();
            default:
                while (!stack.IsEmpty() && Priority(expression[i]) <= Priority(stack.Top()))
                {
                    res += stack.Pop();
                    res += '_';
                }
                stack.Push(temp);
            }
        }
    }
    while (!stack.IsEmpty())
    {
        res += stack.Pop();
    }
    return res;
}
double Counting(string expression) 
{
    double v1, v2, result = 0;
    string temp = "";
    Stack<string> stack;
    for (int i = 0; i < expression.length(); ++i)
    {
        while (expression[i] == '_')
        {
            ++i;
        }
        if (Number(expression[i]))
        {
            while (Number(expression[i]))
            {
                temp += expression[i];
                ++i;
            }
            stack.Push(temp.c_str());
            temp = "";
        }
        else if (Operation(expression[i]))
        {
            v1 = stod(stack.Pop());
            v2 = stod(stack.Pop());
            switch (expression[i])
            {
            case '+':
                result = (v1 + v2);
                break;
            case '*':
                result = (v1 * v2);
                break;
            case '-':
                result = (v2 - v1);
                break;
            case '/':
                if (v1 == 0)
                {
                    throw "Dividing by zero is prohibited";
                }
                result = (v2 / v1);
                break;
            case '^':
                result = pow(v2, v1);
                break;
            }
            stack.Push(to_string(result));
        }
        else
        {
            cout << "Here`s an error ! " << endl;
            break;
        }
    }
    return stod(stack.Pop());
}
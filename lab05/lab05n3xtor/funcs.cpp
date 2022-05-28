#include "funcs.h"
using namespace std;
const int pairSize = 6;

pair<char, int> priorities[pairSize]
{
        {'^', 0}, {'(', 1}, {'*', 2}, {'/', 2}, {'+', 3}, {'-', 3}
};

bool CheckBrackets(const string& expression) 
{
    int count = 0;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == ')')
        {
            ++count;
        }
    }
    return true ? ((count % 2) == 0) : false;
}

int GetPriority(const char& action)
{
    for (int i = 0; i < pairSize; ++i) 
    {
        if (action == priorities[i].first) 
        {
            return priorities[i].second;
        }
    }
    return -1;
}

bool isDigit(const char& c)
{
    return c >= '0' && c <= '9';
}

bool isOperator(const char& c) 
{
    for (int i = 0; i < pairSize; ++i)
    {
        if (c == priorities[i].first) 
        {
            return true;
        }
    }
    return false;
}

    string PolishRecord(string& expression)
    {
    string output;
    Stack<char> stack;
    if (!CheckBrackets(expression))
    {
        cout << "odd amount of brackets\n";
        return "odd amount of brackets";
    }
    for (int i = 0; i < expression.length(); i++)
    {
        if (isDigit(expression[i]))
        { 
            while (isDigit(expression[i + 1]) && i < expression.length())
            {
                output += expression[i];
                ++i; 
            }
            output += expression[i]; 
            output += '_';
        }
        else if (expression[i] == '(')
        {
            stack.Push(expression[i]);
        }
        else if (expression[i] == ')')
        {
            while (stack.Top() != '(')
            {
                output += stack.Pop();
            }
            stack.Pop();
        }
        else if (isOperator(expression[i]))
        {
            if (stack.IsEmpty())
            {
                stack.Push(expression[i]);
                continue;
            }
            else if (GetPriority(expression[i]) < GetPriority(stack.Top()))
            {
                stack.Push(expression[i]);
            }
            else if (GetPriority(expression[i]) >= GetPriority(stack.Top()))
            {
                while (!stack.IsEmpty() && (GetPriority(expression[i]) >= GetPriority(stack.Top()) && stack.Top() != '('))
                {
                    output += stack.Pop();
                }
                stack.Push(expression[i]);
            }
        }
        else
        {
            cout << expression[i] << " is invalid character.\n";
        }
    }
    while (!stack.IsEmpty())
    { 
        output += stack.Pop();
    }
    return output;
}

double Calculate(const string& expression)
{
    double result = 0;
    string num;
    Stack<string> stack;
    for (int i = 0; i < expression.length(); i++)
    {
        if (isDigit(expression[i]))
        {
            while (expression[i] != '_' && i < expression.length())
            {  
                num += expression[i];   
                ++i;  
            }
            stack.Push(num);
            num = "";
        }
        if (isOperator(expression[i]))
        {
            double a = stod(stack.Pop());
            double b = stod(stack.Pop());
            char action = expression[i];
            switch (action)
            {
            case '^':
                result = pow(b, a);
                break;
            case '/':
                result = b / a;
                break;
            case '*':
                result = b * a;
                break;
            case '-':
                result = b - a;
                break;
            case '+':
                result = b + a;
                break;
            default:
                cout << "bad operator in calculating function\n";
            }
            stack.Push(to_string(result));
        }
    }
    return stod(stack.Top());
}
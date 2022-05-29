#include "functions.h"

int scanNum(char value)
{
    return (int)(value) - 48;
}

bool isOperator(char value)
{
    if (value == '+' || value == '-' || value == '*' || value == '/' || value == '^')
        return true;
    return false;
}

bool isOperand(char value)
{
    if (value >= '0' && value <= '9')
        return true;
    return false;
}

int operation(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            return b / a;
        case '^':
            return (int)pow(b, a);
        default:
            throw "Invalid operator\n";
    }
}

int priority(char value)
{
    switch (value)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return -1;
    }
}

std::string infixToPostfix(std::string expression)
{
    std::stack<char> st;
    std::string result;

    for (std::string::iterator it = expression.begin(); it != expression.end(); it++)
    {
        char c = *it;

        if ((c >= '0' && c <= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && priority(*it) <= priority(st.top()))
            {
                if (c == '^' && st.top() == '^')
                {
                    break;
                }
                else
                {
                    result += st.top();
                    st.pop();
                }
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    return result;
}

int postfixCalculate(std::string postfix) // (-1)2+
{
    int a, b;
    std::stack<int> stk;
    std::string::iterator it = postfix.begin();
    while (it != postfix.end())
    {
        if (isOperator(*it))
        {
            a = stk.top();
            stk.pop();
            b = stk.top();
            stk.pop();
            stk.push(operation(a, b, *it));
        }
        else if (*it == '(')
        {
            if (*(++it) == '-')
            {
                if (*(it += 2) == ')')
                {
                    stk.push(-scanNum(*(--it)));
                }
            }
            it++;
        }
        else
        {
            stk.push(scanNum(*it));
        }
        it++;
    }
    return stk.top();
}

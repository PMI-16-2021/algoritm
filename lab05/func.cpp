#pragma once
#include "functions.h"

int priority(char symbol) // priority of operation
{
    switch (symbol)
    {
        case '(':return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
        case '%':
            return 2;
        case '^': return 3;
        default:
            return -1;
    }
}
bool IsNum(char symbol) // check if symbol  is number
{

    return (symbol >= '0' && symbol <= '9' );
}
bool IsOperator(char symbol)
{
    switch (symbol)
    {
        case '+': case '-': case '*': case '/': case '^':
            return true;
        default:
            return false;
    }
}

string toPostfix(string expression)
{
    Stack<char> stack;
    string res;
    for (int i = 0; i < expression.length(); ++i)
    {
        char temp = expression[i];
        //if is multi-digit continue
        if (IsNum(temp))
        {
            res += temp;
            if (!IsNum(expression[i + 1]))
            {
                res += '_'; // for output
            }
        }
        else if (temp == '(')
        {
            stack.push(temp);
        }
        else if (temp == ')')
        {
            while (stack.getTop() != '(')
            {
                res += stack.getTop();
                stack.pop();
                res += '_';
            }
            stack.pop();
        }
        else
        {
            while (!stack.isEmpty() && priority(expression[i]) <= priority(stack.getTop()))
            {
                res += stack.pop();
                res += '_';
            }
            stack.push(temp);
        }
    }
    while (!stack.isEmpty())
    {
        res += stack.pop();
    }
    return res;
}


double CountExpression(string expression) //count the expression in postfix
{
    double t1, t2,result =0;
    string temp = "";
    Stack<string> stack;
    for (int i = 0; i < expression.length(); ++i)
    {
        while (expression[i] == '_')
        {
            ++i;
        }
        if (IsNum(expression[i]))
        {
            while (IsNum(expression[i]))
            {
                temp += expression[i];
                ++i;
            }
            stack.push(temp.c_str());
            temp = "";
        }
        else if (IsOperator(expression[i]))
        {
            t1 = stod(stack.pop());//string TO double
            t2 = stod(stack.pop());//string TO double
            if (expression[i] == '+')
            {
                result = (t1 + t2);
            }
            if (expression[i] == '-')
            {
                result =t2 - t1;
            }
            if (expression[i] == '*')
            {
                result = (t1 * t2);
            }
            if (expression[i] == '/')
            {
                if (t1 == 0)
                {
                    throw "You can not divide by zero";
                }
                result = (t2/ t1);
            }
            if (expression[i] == '^')
            {
                result = pow(t2, t1);
            }
            stack.push(to_string(result));
        }
        else
        {
            cout << "ERROR "<< '\n';
            break;
        }
    }
    return stod(stack.pop());
}
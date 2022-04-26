#include "Stack.h"

Stack::Stack(const Stack& S)
{
    quantity = S.quantity;
    stack = new char[quantity];
    for (int i = 0; i < quantity; ++i)
    {
        stack[i] = S.stack[i];
    }
}

Stack Stack::operator=(const Stack& S)
{
    if (this == &S) return *this;
    if (size() > 0) delete[] stack;
    quantity = S.quantity;
    stack = new char[quantity];
    for (int i = 0; i < quantity; ++i)
    {
        stack[i] = S.stack[i];
    }
    return *this;
}

char Stack::push(char new_element)
{
    char* temp = stack;
    ++quantity;
    stack = new char[quantity];
    for (int i = 0; i < quantity - 1; ++i)
    {
        stack[i] = temp[i];
    }
    stack[quantity - 1] = new_element;
    return new_element;
}

char Stack::pop()
{
    if (quantity == 0)
    {
        return 0;
    }
    char pop = stack[quantity - 1];
    quantity--;
    return pop;
}

bool Stack::isEmpty()
{
    return quantity == 0;
}

char Stack::top()
{
    if (quantity == 0)
    {
        return 0;
    }
    else return stack[quantity - 1];
}

void Stack::print()
{
    if (isEmpty()) cout << "Stack is empty!" << endl;
    else
    {
        for (int i = quantity - 1; i >= 0; --i)
        {
            cout << quantity - i << " item: " << stack[i] << "\t";
        }
        cout << endl;
    }
}

bool emptySpace(char symbol)
{
    if (symbol == ' ' || symbol == '\t')
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string infix)
{
    string postfix = "";
    Stack stack;
    int inf;
    char next;
    char symbol;
    for (inf = 0; inf < infix.length(); inf++)
    {
        symbol = infix[inf];
        if (!emptySpace(symbol))
        {
            switch (symbol)
            {
            case '(':
                stack.push(symbol);
                break;
            case ')':
                while ((next = stack.pop()) && next != '(')
                {
                    postfix += next;
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!stack.isEmpty() && priority(symbol) <= priority(stack.top()))
                {
                    postfix += stack.pop();
                }
                stack.push(symbol);
                break;
            default:
                postfix += symbol;
            }
        }
    }
    while (!stack.isEmpty())
    {
        postfix += stack.pop();
    }
    return postfix;
}

int priority(char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

bool isNum(char symbol)
{
    return (symbol >= '0' && symbol <= '9');
}

int action(string postfix)
{
    Stack stack;
    int a, b, i, temp_result, result;
    for (i = 0; i < postfix.length(); i++)
    {
        if (isNum(postfix[i]))
        {
            stack.push(postfix[i] - '0');
        }

        else
        {
            a = stack.pop();
            b = stack.pop();
            switch (postfix[i])
            {
            case '+':
                temp_result = b + a;
                break;
            case '-':
                temp_result = b - a;
                break;
            case '*':
                temp_result = b * a;
                break;
            case '/':
                temp_result = b / a;
                break;
            case '%':
                temp_result = b % a;
                break;
            case '^':
                temp_result = pow(b, a);
            }
            stack.push(temp_result);
        }
    }
    result = stack.pop();
    return result;
}
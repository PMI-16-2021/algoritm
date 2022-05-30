#include <stack>
#include<string>
using namespace std;

bool isSign(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
        return true;
    default:
        return false;
    }
}


int signToInt(char c)
{
    if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string toPolish(string expression)
{
    stack<char> stackString;

    string result;

    for (char& letter : expression)
    {

        if (isSign(letter))
        {
            result += ' ';
        }

        if (isdigit(letter) || letter == '.')
        {
            result += letter;
        }
        else if (letter == '(')
        {
            stackString.push('(');
        }
        else if (letter == ')')
        {
            while (!stackString.empty() && stackString.top() != '(')
            {
                char c = stackString.top();
                stackString.pop();
                result += ' ';
                result += c;

            }
            if (stackString.top() == '(')
            {
                stackString.pop();
            }
        }
        else
        {
            while (!stackString.empty() && signToInt(letter) <= signToInt(stackString.top()))
            {
                char c = stackString.top();
                stackString.pop();
                result += c;
            }
            stackString.push(letter);
        }
    }

    result += ' ';

    while (!stackString.empty())
    {
        char c = stackString.top();
        stackString.pop();
        result += c;
    }

    return result;
}

double functionToEvaluate(string expression)
{
    stack<double> stackOfNumbers;

    string temp;
    int i = 0;

    double tempVariable1, tempVariable2, tempResult;

    while (i < expression.size())
    {

        while (isspace(expression[i]))
        {
            i++;
        }

        if (isdigit(expression[i]) || expression[i] == '.')
        {
            while (isdigit(expression[i]) || expression[i] == '.')
            {
                temp += expression[i];
                i++;
            }

            stackOfNumbers.push(stod(temp));
            temp = "";

        }
        else if (isSign(expression[i]))
        {

            tempVariable1 = stackOfNumbers.top();
            stackOfNumbers.pop();
            tempVariable2 = stackOfNumbers.top();
            stackOfNumbers.pop();

            switch (expression[i])
            {
            case '+':
                tempResult = (tempVariable2 + tempVariable1);
                break;

            case '-':
                tempResult = (tempVariable2 - tempVariable1);
                break;

            case '*':
                tempResult = (tempVariable2 * tempVariable1);
                break;

            case '/':
                tempResult = (tempVariable2 / tempVariable1);
                break;
            }
            i++;

            stackOfNumbers.push(tempResult);
        }
        else
        {
            throw ("Error");
        }
    }
    return stackOfNumbers.top();
}
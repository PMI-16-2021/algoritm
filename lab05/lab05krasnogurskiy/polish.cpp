#include "polish.h"

bool is_operator(char op)
{
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%' || op == 's' || op == 'c' || op == 't' || op == 'g';
}

double calculate(double a, double b, char operation)
{
    if (operation == 's')
    {
        return sin(b);
    }
    if (operation == 'c')
    {
        return cos(b);
    }
    if (operation == 't')
    {
        return tan(b);
    }
    if (operation == 'g')
    {
        return (double)1 / tan(b);
    }
    if (operation == '+')
    {
        if (a == -8)
        {
            return b;
        }
        return a + b;
    }
    if (operation == '-')
    {
        if (a == -8)
        {
            return -b;
        }
        return a - b;
    }
    if (operation == '*')
    {
        if (a == -8)
        {
            return b;
        }
        return a * b;
    }
    if (operation == '/')
    {
        if (a == -8)
        {
            return b;
        }
        return a / b;
    }
    if (operation == '^')
    {
        if (a == -8)
        {
            return b;
        }
        return pow(a, b);
    }
    if (operation == '%')
    {
        if (a == -8)
        {
            return b;
        }
        return (int)a % (int)b;
    }

    return -1;
}

double rpolish_calculate(std::string notation)
{
    std::stack<double> s;

    for (int i = 0; i < notation.length(); i++)
    {
        if (is_operator(notation[i]))
        {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();

            s.push(calculate(b, a, notation[i]));
        }
        else
        {
            s.push((double)(notation[i]) - 48);
        }
    }
    return s.top();
}

int prec(char c) {
    if (c == 's' || c == 'c' || c == 't' || c == 'g')
        return 4;
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

std::string rpolish(std::string notation)
{
    notation = std::regex_replace(notation, std::regex("sin"), "s");
    notation = std::regex_replace(notation, std::regex("cos"), "c");
    notation = std::regex_replace(notation, std::regex("tg"), "t");
    notation = std::regex_replace(notation, std::regex("ct"), "g");
    std::stack<char> st;
    std::string result;
    bool obracket_caught = 0;
    bool unary = 0;
    for (int i = 0; i < notation.length(); i++)
    {
        if (notation[i] >= '0' && notation[i] <= '9')
        {
            if (unary)
            {
                result += '(';
                unary = 0;
            }
            obracket_caught = 0;
            result += notation[i];
        }

        else if (notation[i] == '(')
        {
            st.push('(');
            obracket_caught = 1;
        }

        else if (notation[i] == ')')
        {
            obracket_caught = 0;
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        else if (is_operator(notation[i]))
        {
            if (obracket_caught)
            {
                unary = 1;
            }
            while (!st.empty() && prec(notation[i]) <= prec(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(notation[i]);
        }
    }

    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}
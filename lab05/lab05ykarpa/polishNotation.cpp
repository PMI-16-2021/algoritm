#include "polishNotation.h"
#include <stack>
using namespace std;

bool is_operation(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == '%';
}

double calculate(double a, double b, char operation) {
    if (operation == '+') {
        return a + b;
    }
    if (operation == '-') {
        return a - b;
    }
    if (operation == '*') {
        return a * b;
    }
    if (operation == '/') {
        return a / b;
    }
    if (operation == '^') {
        return pow(a, b);
    }
    if (operation == '%') {
        return (int)a % (int)b;
    }
    return -1;
}

double reversed_polish_notation(string notation) {
    stack<double> s;
    for (int i = 0; i < notation.length(); i++) {
        if (is_operation(notation[i])) {
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            s.push(calculate(b, a, notation[i]));
        }
        else {
            s.push((double)(notation[i]) - 48);
        }
    }
    return s.top();
}

int prec(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '/' || c == '*' || c == '%') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string convert_to_reversed_polish_notation(string notation) {
    stack<char> st;
    string result;
    for (int i = 0; i < notation.length(); i++) {
        if (notation[i] >= '0' && notation[i] <= '9') {
            result += notation[i];
        }
        else if (notation[i] == '(') {
            st.push('(');
        }
        else if (notation[i] == ')') {
            while (st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && prec(notation[i]) <= prec(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(notation[i]);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}
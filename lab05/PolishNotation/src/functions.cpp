#include "functions.h"
#include "Stack.h"
#include <string>
#include <cmath>

bool isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            return true;
        default:
            return false;
    }
}

bool isDigit(char c) {
    switch (c) {
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return true;
        default:
            return false;
    }
}

int getPriority(char c) {
    switch (c) {
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

std::string getReversePolishNotation(std::string expression) {
    Stack<char> symbolsStack;
    std::string result;
    for (size_t i = 0; i < expression.length(); ++i) {
        char temporary = expression[i];
        //якщо це число то ми додаємо його до нашої результуючої стрічки
        if (isDigit(temporary)) {
            result += temporary;
            //якщо це число не продовжується, то ми додаємо нижнє підкреслення, щоб відрізнити різні числа
            if (!isDigit(expression[i + 1])) {
                result += '_';
            }
        }
            //якщо це відкриваюча дужка то ми заносимо її в стек чарів
        else if (temporary == '(') {
            symbolsStack.push(temporary);
        }
            //якщо ми побачили закриваючу дужку, то ми додаємо до результуючої стрічки усі знаки що присутні в стеку допоки не наткнемося на закриваючу дужку
        else if (temporary == ')') {
            while (symbolsStack.top() != '(') {
                result += symbolsStack.pop();
                result += '_';
            }
            symbolsStack.pop();
        } else {
            //якщо це знак дій, то ми перевіряємо чи стек не порожній і чи його пріоритет нижчий аніж найвищого в стеку
            while (!symbolsStack.isEmpty() && getPriority(expression[i]) <= getPriority(symbolsStack.top())) {
                //тоді ми додаємо до результуючої стрічки знак з вищим пріоритетом
                result += symbolsStack.pop();
                result += '_';
            }
            //в кінцевому результаті долаємо наш знак
            symbolsStack.push(temporary);
        }
    }
    //якщо після проходу циклом по рядку, якісь знаки ще залишились в стеку, то ми їх додаємо
    while (!symbolsStack.isEmpty()) {
        result += symbolsStack.pop();
    }
    return result;
}

double calculate(std::string expression) {
    double first = 0, second = 0;
    double result = 0;
    std::string tokString = "";
    Stack<std::string> numbersStack;
    for (size_t i = 0; i < expression.length(); ++i) {
        while (expression[i] == '_') {
            ++i;
        }
        //якщо символ то ми додаємо до стрічки і до стека
        if (isDigit(expression[i])) {
            while (isDigit(expression[i])) {
                tokString += expression[i];
                ++i;
            }
            numbersStack.push(tokString.c_str());
            // робимо tokString порожнім, щоб не дублювати
            tokString = "";
        } else if (isOperator(expression[i])) {
            //перетворюємо рядок в число за допомогою std::stod
            first = std::stod(numbersStack.pop());
            second = std::stod(numbersStack.pop());
            if (expression[i] == '+') {
                result = (first + second);
            }
            if (expression[i] == '-') {
                result = second - first;
            }
            if (expression[i] == '*') {
                result = (first * second);
            }
            if (expression[i] == '/') {
                if (first == 0) {
                    throw "Division by zero isn't possible";
                }
                result = (second / first);
            }
            if (expression[i] == '^') {
                result = pow(second, first);
            }
            numbersStack.push(std::to_string(result));
        } else {
            std::cout << "You entered incorrect data" << '\n';
            break;
        }
    }
    return std::stod(numbersStack.pop());
}
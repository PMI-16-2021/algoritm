#pragma once
#include <iostream>
#include <stack>
#include <cmath>

int scanNum(char value);
bool isOperator(char value);
bool isOperand(char value);
int operation(int a, int b, char op);
int priority(char value);
std::string infixToPostfix(std::string expression);
int postfixCalculate(std::string postfix);
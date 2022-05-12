#pragma once
#include <string>

bool isOperator(char c);
bool isDigit(char c);
int getPriority(char c);
std::string getReversePolishNotation(std::string expression);
double calculate(std::string expression);
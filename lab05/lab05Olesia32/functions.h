#pragma once
#include <string>

bool IsOperator(char c);
bool IsDigit(char c);
int Priority(char c);
std::string ReversePolishNotation(std::string expression);
double Calculate(std::string expression);
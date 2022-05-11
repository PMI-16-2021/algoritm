#pragma once
#include <string>
#include "stack.h"
#include <cmath>

int GetPrior(const char& action);
std::string PolishRecord(std::string& notation);
double Calculate(const std::string& notation);
bool isDigit(const char& c);
bool isOperator(const char& c);
bool CheckBrackets(const std::string& notation);
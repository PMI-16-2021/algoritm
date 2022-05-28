#pragma once
#include <string>
#include <cmath>
#include "stack.h"
using namespace std;

int GetPriority(const char& action);
string PolishRecord(string& expression);
double Calculate(const string& expression);
bool isDigit(const char& c);
bool isOperator(const char& c);
bool CheckBrackets(const string& expression);
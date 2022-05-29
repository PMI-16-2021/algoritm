#pragma once
#include <string>
#include "stack.h"
#include <cmath>
int GetPriority(char a);
bool IsDigit(char a);
bool IsOperator(char a);
std::string PolishRecord(std::string n);
int Calculate(std::string e);
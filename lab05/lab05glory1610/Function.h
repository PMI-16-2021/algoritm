#pragma once
#include<iostream>
#include "Stack.h"
#include<string>
#include<cmath>

bool isOperator(char c);
bool isDigit(char c);
int priority(char c);
std::string ReversePN(std::string expression);
double calculate(std::string expression);

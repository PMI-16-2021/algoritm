#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <regex>

bool is_operator(char op);
double calculate(double a, double b, char operation);
double rpolish_calculate(std::string notation);
int prec(char c);
std::string rpolish(std::string notation);
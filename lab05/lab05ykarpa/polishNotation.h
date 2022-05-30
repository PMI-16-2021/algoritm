#pragma once
#include <iostream>
#include <string>

bool is_operation(char op);
double calculate(double a, double b, char operation);
double reversed_polish_notation(std::string notation);
int prec(char c);
std::string convert_to_reversed_polish_notation(std::string notation);
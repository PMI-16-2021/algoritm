#pragma once
#include <iostream>
#include <string>

bool isNumber(char n);
bool isOperator(char o);
int priority(char pr);
std::string reversePolish(std::string expr);
double calculate(std::string expr);

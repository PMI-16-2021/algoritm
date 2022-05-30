#pragma once
#include <iostream>

bool is_digit(char c);
size_t calc(std::string polish);
size_t compare_operators(char op1, char op2);
bool is_operator(char character);
bool is_operand(char character);
std::string to_postfix(char* input);

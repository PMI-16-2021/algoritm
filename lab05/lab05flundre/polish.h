#pragma once
#include <string>
#include "Stack.h"


bool isDigit(char l);
bool isFunc(char l);
size_t getPriority(char l);
std::string getReversedPolishNotation(std::string s);
double calculateReversedPolishNotation(std::string s);

#pragma once
#include<iostream>
using namespace std;
#include "cmath"
#include "stack.h"

int priority(char symbol); // priority of operation
bool IsNum(char symbol); // check if symbol  is number
bool IsOperator(char symbol);//check if symbol is operator
string toPostfix(string expression);//reformat to postfix (reverse polish notation)
double CountExpression(string expression); //count the expression in postfix



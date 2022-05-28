#pragma once
#include<iostream>
using namespace std;
#include "cmath"
#include "stack.h"

int Priority(char letter);
bool Number(char letter);
bool Operation(char letter);
string toPostFix(string expression);
double Counting(string expression);

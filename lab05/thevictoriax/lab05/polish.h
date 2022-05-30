#pragma once
#include<string>

bool operators(const char& op);
bool numbers(const char& num);
int priority(const char& prior);
double calculation(std::string sample);
std::string reversion(std::string sample);
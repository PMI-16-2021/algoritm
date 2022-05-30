#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>

class Rule
{
    std::string before;
    std::string after;

public:
    Rule();
    Rule(const std::string& b, const std::string& a);
    ~Rule();

    bool apply(std::string& word);
    bool terminal();
};

void algorithm(std::string& word, std::vector<Rule>& rules);
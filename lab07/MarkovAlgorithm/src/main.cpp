#include <iostream>
#include <vector>
#include "MyString.h"

int main() {
    std::vector<Rule> rules;
    Rule a1("F", "food");
    Rule a2("T", "tesla");
    Rule a3("A", "apple");
    Rule a4(".", "", true);
    rules.push_back(a1);
    rules.push_back(a2);
    rules.push_back(a3);
    rules.push_back(a4);

    MyString result = markovAlgorithm(rules, "She bought an A in F store.");
    std::cout << result;

    return 0;
}

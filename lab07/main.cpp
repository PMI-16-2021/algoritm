#include <iostream>
#include "markov.h"
using namespace std;

int main() {

    vector<Rule> rule = { Rule("|-|",  "-"), Rule("|-" ,  "|") };
    string word = "|||||-|||";
    cout << "Before: " << word << "\n";
    algorithm(word, rule);
    cout << "After: " << word << "\n";

    return 0;
}

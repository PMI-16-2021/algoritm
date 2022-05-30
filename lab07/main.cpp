#include "markovAlgorithm.h"
#include <iostream>
using namespace std;

int main() {
	vector<Rule> rules;
	Rule r1("er", "o");
	Rule r2("b", "p");
	Rule r3("ad", "ul");
	Rule r4("lak", "gh");
	Rule r5("p", "ky");
	rules.push_back(r1);
	rules.push_back(r2);
	rules.push_back(r3);
	rules.push_back(r4);
	rules.push_back(r5);
	for (int i = 0; i < markovAlgorithm(rules, "terberlakerad").getLength(); ++i) {
		cout << markovAlgorithm(rules, "terberlakerad")[i];
	}

	return 0;
}
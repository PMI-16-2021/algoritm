#include "string.h"
#include <iostream>
using namespace std;

int main() {
	std::vector<Rule> rules;
	Rule a1("aa", "a");
	Rule a2("bb", "b");
	rules.push_back(a1);
	rules.push_back(a2);
	String result = Markov(rules, "bbbbaabb");
	for (int i = 0; i < result.lenght(); ++i) {
		cout << result[i];
	}
	system("pause");
	return 0;
}
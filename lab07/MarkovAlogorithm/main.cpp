#include "String.h"
using std::cout;
using std::vector;

int main()
{

	std::vector<Rule> rules;
	Rule a1("+", "");
	Rule a2("", "", true);
	rules.push_back(a1);
	String result = markovAlg(rules, "||||+||+|");

	cout << result;

	system("pause");
	return 0;
}
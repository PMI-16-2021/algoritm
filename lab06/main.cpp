#include "myString.h"
#include <iostream>
using namespace std;

int main() {
	vector<Rule> r;

	Rule r1("aa", "k");
	r.push_back(r1);

	Rule r2("u", "i");
	r.push_back(r2);

	Rule r3("fa", "t");
	r.push_back(r3);

	Rule r4("ew", "r");
	r.push_back(r4);

	Rule r5("rr", "y");
	r.push_back(r5);

	for (int i = 0; i < markov(r, "aaufafarr").getSize(); ++i) {
		cout << markov(r, "aaufafarr")[i];
	}
	cout << "\n\n";

	system("pause");
	return 0;
}
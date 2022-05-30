#include <iostream>
#include <vector>
#include "markov.h"
using namespace std;

int main()
{
	String S("abccbbaadbcdd");
	std::vector<std::pair<String, String>> rules = { { "aa","a" }, { "bb","b" }, { "cc","c" }, { "dd","d"} };
	S.markov(rules);
	cout << S.getLetters() <<"\n";

	system("pause");
	return 0;
}
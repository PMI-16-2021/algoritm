#include<iostream>
#include"string_markov.h"
using namespace std;
int main() {
	std::vector<std::pair<String, String>> rules{
				std::make_pair("a|", "ab"),
				std::make_pair("b|", "ba"),
				std::make_pair("aa", "b"),
				std::make_pair("bb", "a"),
	};
	String result = MarkovAlgorithm(rules, "a||b||aa|bb||");
	cout << "result: " << result << endl;

	std::vector<std::pair<String, String>> rules1{
				std::make_pair("*", "ab"),
				std::make_pair("/", "ba"),
				std::make_pair("^", "b"),
				std::make_pair("-", "a"),
	};
	String result1 = MarkovAlgorithm(rules1, "*/**-^");
	cout << "result: " << result1 << endl;
	system("pause");
	return 0;
}
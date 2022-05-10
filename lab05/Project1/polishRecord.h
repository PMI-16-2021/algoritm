#pragma once
#include <string>
#include <iostream>
using std::string;
using std::stod;
using std::to_string;

//transform infix string to postfix 
//!!!str should contain SPACE after each character!!!
string PolishRecord(string str);

//calculates based on PolishRecord
double Calculate(string rev_polish);

//get Priotity of operator
size_t GetPriority(const string a);

//determin wheter char is operation
bool IsOperation(const string a);

//check if parentheses are balanced correctly
bool balanceStr(const string b);

//class-exception if brackets are badly-balanced
class BadBracketBalance
{
private:
	string mess;

public:
	BadBracketBalance(string param): mess(param){}
	void report()const
	{ 
		std::cerr << "Bad bracket balance in infix " << mess << '\n'; 
	}
};


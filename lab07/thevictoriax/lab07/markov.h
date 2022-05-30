#pragma once
#include <iostream>
#include<vector>

class String
{
private:
	int length;
	char* letters;
public:
	String(const char* letters);

	int getLength();
	char* getLetters();
	
	void markov(std::vector<std::pair<String, String>>& rules);
	char* find(String& subString);
	void replace(String& a, String& b);
};
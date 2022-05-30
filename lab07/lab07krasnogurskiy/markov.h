#pragma once
#include <string>
#include <vector>
#include <fstream>



struct Rule
{
	std::string pattern;
	std::string replacement;
	bool terminal;

	Rule(std::string, std::string, bool);
};

std::string markovAlgorithm(std::vector<Rule>, std::string);


//NEED TO DO (find, replace, insert, erase, resize)
//class String {
//private:
//	int size;
//	char* container;
//public:
//	String();
//	String(const char* cont);
//	String(const String& S);
//	~String();
//	size_t lenght() const;
//	char& operator[](const int i) const;
//	String& operator=(const String& from);
//	bool operator==(const String& other);
//	String operator+(const String& other);
//	friend std::ostream& operator<<(std::ostream& out, const String& str);
//};
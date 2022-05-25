#pragma once
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

class String {
private:
	int size;
	char* container;
public:
	String();
	String(const char* cont);
	String(const String& S);
	~String();
	size_t lenght() const;
	int Find(const String& subtr) const;
	void Replace(const String& from, const String& to);
	void Erase(size_t pos, size_t len);
	void Resize(size_t _size);
	void Insert(size_t pos, const String& str);
	char& operator[](const int i) const;
	String& operator=(const String& from);
	bool operator==(const String& other);
	String operator+(const String& other);
	friend std::ostream& operator<<(std::ostream& out, const String& str);
};

struct Rule {
	String pattern;
	String replacement;
	bool terminal;
	Rule();
	Rule(String _pattern, String _replacement);
	Rule(String _pattern, String _replacement, bool _terminal);
};

String Markov(std::vector<Rule> rules, String input);
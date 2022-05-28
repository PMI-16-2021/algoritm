#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct rules_for_bin_to_dec;
struct rules_for_multiply;
struct my_rules;

class String {
	size_t size_ = 0;
	char* container_ = nullptr;
public:
	String();
	String(const char* string);
	String(const String& other);
	~String();

	String& operator=(const String& other);
	String operator+(const String& other);
	bool operator==(const String& other);
	char operator[](int n);

	size_t leng();
	int Find(String& what_to_find);
	void Replace(String what_to_find, String replacement);
	String for_bin_to_dec(rules_for_bin_to_dec& rule);
	String for_multiply(rules_for_multiply& rule);
	String for_my_rules(my_rules& rule);
	friend ostream& operator<<(ostream& out, const String& str);
};

struct rules_for_bin_to_dec {
	vector<String> to_replace = { "1", "|0", "0" };
	vector<String> replacements = { "0|", "0||", "" };
};

struct rules_for_multiply {
	vector<String> to_replace = { "|b", "ab", "b", "*|", "*", "|c", "ac", "c" };
	vector<String> replacements = { "ba|", "ba", "", "b*", "c", "c", "c|", "" };
};

struct my_rules {
	vector<String> to_replace = { "ab", "ac", "bc", "c" };
	vector<String> replacements = { "c", "b", "a", "a" };
};
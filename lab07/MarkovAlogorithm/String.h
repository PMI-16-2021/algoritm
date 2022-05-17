#pragma once
#include <iostream>
#include <vector>
#include <string>

//class string 
//quiete similar to std::string
//has an iterator
class String
{
private:
	size_t size;   //number of stored char symbols
	char* cont;    //dynamic array
public:
	String();
	String(const char* str);
	String(const String& str);
	~String();

	//returns length of array 
	size_t length() const; 
	
	//differentiates substring of length *len* starting from position *pos*
	String substring(size_t pos, size_t length) const;  

	//lloks for substring *subtr* in this; returns index or -1
	int find(const String& substr) const;

	//replaces *from* to *to* in current String
	//returns if operation is successful
	bool replace(const String& from, const String& to);
	String& operator=(const String& str);

	//concantenation
	String operator+(const String& str);
	bool operator==(const String& str) const;
	
	//string built-in 
	//non-const iterator
	class iterator
	{
	private:
		char* ptr;
	public:
		iterator(char* _ptr = nullptr); 
		
		//basic iterator functionality
		iterator& operator++();
		char& operator*();
		bool operator !=(const iterator& it);
		bool operator ==(const iterator& it);
		bool operator < (const iterator& it);
	};

	//returns iterator to begin of String
	iterator begin();

	//returns iterator to the end of String
	iterator end();

	//output operator for String
	friend std::ostream& operator<<(std::ostream& out, const String& str);
};

//Struct for emulating Markov 
//replace rules
struct Rule
{
	String from;             //original
	String to;               //to replace original
	bool terminal;           //check if terminal
	Rule(String _from, String _to, bool _t = false)
	{
		from = _from;
		to = _to;
		terminal = _t;
	}
};

String markovAlg(std::vector<Rule>&, String data);

class BadRule
{
private:
	String mess;

public:
	BadRule(const String& _mess): mess(_mess) {}
	void report() const
	{
		std::cerr << "Loping detected during Markov algorithm on String " << mess << '\n';
	}
};

#pragma once
#include <iostream>

class Set
{
private:
	char* elements;
	int setSize;
	int setCapacity;
public:
	Set();
	Set(int size);
	~Set();

	void add(char elem);
	void remove(char elem);
	int len() const;
	bool in(char elem) const;
	Set unionSet(Set &S) const;
	Set intersection(Set& S);
	Set difference(Set& S);
	Set symmetric_difference(Set& S);
	void print() const;
	char& operator[](int temp);
};
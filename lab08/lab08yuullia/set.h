#pragma once
#include <iostream>

class Set {
private:
	int* value;
	int count;
	int size;
public:
	Set();
	Set(int s);
	~Set();

	void add(int v);
	void remove(int v);
	bool in(int v) const;
	int len();

	Set unionS(Set& S);
	Set intersectionS(Set& S);
	Set differenceS(Set& S);
	Set symmetricDifferenceS(Set& S);

	int& operator[](int i);

	void print() const;
};
#pragma once


class Set {
private:
	int* elements;
	int size;
	int capacity;
public:
	Set();
	Set(int _size);
	~Set();
	bool in(int e) const;
	void add(int e);
	void remove(int e);
	void print() const;
	int len() const;
	Set unionn (Set& o);
	Set intersection(Set& o);
	Set difference(Set& o);
	Set symmetricDifference(Set& o);
	int& operator[](int i);
	const int& operator[](int i) const;
};
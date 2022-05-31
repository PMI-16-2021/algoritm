#include "plurall.h"
#include <iostream>
using namespace std;

Set::Set(): size(15), capacity(0)
{
	elements = new int[size];
}
Set::Set(int s) : size(s), capacity(0)
{
	elements = new int[size];
}
Set::~Set() {}

bool Set::in(int e) const
{
	if (capacity == 0) {
		return false;
	}
	for (int i = 0; i < capacity; ++i) {
		if (elements[i] == e) {
			return true;
		}
	}
	return false;
}

void Set::add(int e)
{
	if (!in(e)) {
		if (capacity == size) {
			size += 15;
			int* temp = new int[size];
			for (int i = 0; i < capacity; ++i) {
				temp[i + 1] = elements[i];
			}
			delete[] elements;
			elements = temp;
			temp = nullptr;
		}
		elements[capacity] = e;
		++capacity;
	}
}

void Set::remove(int e)
{
	if (!in(e)) {
		cout << "wrong element!!!\n";
		return;
	}
	for (int i = 0; i < capacity; ++i) {
		if (elements[i] == e) {
			int* temp = new int[size];
			for (int j = 0; j < i; ++j) {
				temp[j] = elements[j];
			}
			for (int j = i; j < capacity; ++j) {
				temp[j] = elements[j + 1];
			}
			--capacity;
			delete[] elements;
			elements = temp;
			temp = nullptr;
			break;
		}
	}
}

void Set::print() const {
	if (capacity == 0) {
		cout << "Set is empty";
	}
	else {
		for (int i = 0; i < capacity; ++i) {
			cout << elements[i] << " ";

		}
		cout << '\n';
	}
}

int Set::len() const {
	return capacity;
}

Set Set::unionn(Set& o)
{
	int sizeO = o.len();
	Set unionSet(capacity + sizeO);
	for (int i = 0; i < capacity; ++i) {
		unionSet.add(elements[i]);
	}
	for (int i = 0; i < sizeO; ++i) {
		unionSet.add(o[i]);

	}
	return unionSet;
}
Set Set::intersection(Set& o)
{
	Set intersectionSet;
	for (int i = 0; i < capacity; ++i) {
		if (o.in(elements[i])) {
			intersectionSet.add(elements[i]);
		}
	}
	return intersectionSet;
}
Set Set::difference(Set& o)
{
	Set differenceSet;
	for (int i = 0; i < capacity; ++i) {
		if (!o.in(elements[i])) {
			differenceSet.add(elements[i]);
		}
	}
	return differenceSet;
}
Set Set::symmetricDifference(Set& o)
{
	Set symmetricDifferenceSet;
	for (int i = 0; i < capacity; ++i) {
		if (!o.in(elements[i])) {
			symmetricDifferenceSet.add(elements[i]);
		}
	}
	for (int i = 0; i < o.len(); ++i) {
		if (!in(o[i])) {
			symmetricDifferenceSet.add(o[i]);
		}
	}
	return symmetricDifferenceSet;
}

int& Set::operator[](int i)
{
	return elements[i];
}
const int& Set::operator[](int i) const
{
	return elements[i];
}
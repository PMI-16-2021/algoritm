#pragma once
#include <iostream>

void insertSort(int* array, int size);
void printArray(int* array, int size, std::ostream& out);

class BadPointer
{
public:
	void report(std::ostream& out) const;
	BadPointer() {}

};

class BadSize
{
private:
	int bad_index;
public:
	BadSize(int parameter) : bad_index(parameter) {}
	void report(std::ostream& out) const;
};
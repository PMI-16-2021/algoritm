#pragma once
#include <iostream>

void InsertSort(int* array, int size);
void printArray(int* array, int size, std::ostream& out);

class BadPointer
{
public:
	void report(std::ostream& out) const;
	BadPointer() {}

};

class BadSize
{
protected:
	int bad_index;
public:
	BadSize(int parameter) : bad_index(parameter) {}
	int returnField() const;
	virtual void report(std::ostream& out) const;
};


class BadIndex : public BadSize
{
public:
	BadIndex(int bad_index) : BadSize(bad_index) {}
	void report(std::ostream& out) const override;



};

void Swap(int& first, int& second);
void QuickSort(int* arr, int min_index, int max_index);

int GetPivotIndex(int* arr, int start, int begin);

void ShellSorting(int* arr, int size);

int GetMin(int* arr, int size);
int GetMax(int* arr, int size);

void CountSorting(int* arr, int size);

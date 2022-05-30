#pragma once
#include <iostream>
#include <vector>

struct Data
{
	size_t line = 0;
	size_t column = 0;
	double val;

	Data* up = this;
	Data* left = this;
};

class Matrix
{
private:
	size_t linesCounter;
	size_t columnsCounter;
	std::vector<Data> lns;
	std::vector<Data> cls;

	Data* prevColumn(size_t line, size_t column);
	Data* prevLine(size_t line, size_t column);

	void addVal(Data* prevLine, Data* prevColumn, size_t line, size_t column, double val);
	void changeVal(Data* prevLine, Data* prevColumn, size_t line, size_t column, double val);

public:
	Matrix(size_t lnsCounter, size_t clsCounter);
	double getVal(size_t line, size_t column);
	void setVal(size_t line, size_t column, double val);
	void add(Matrix& a);
	void subtraction(Matrix& a);
	void multiply(Matrix& a);
	void transposition();
	std::vector<double> significant_elements();
	void print();
};
#pragma once
#include <iostream>
#include <vector>

struct Element {
	int column;
	int row;
	int val;
	Element* upper_elem;
	Element* left_elem;
	Element() : column(0), row(0), val(0), upper_elem(this), left_elem(this) {}
};


class SparseMatrix {
private:
	int rowCount;
	int columnCount;
	int elements;
	std::vector<Element> rows;
	std::vector<Element> columns;
	
	Element* prevByRow(int r, int c);
	Element* prevByColumn(int r, int c);

public:
	SparseMatrix();
	SparseMatrix(int rCount, int cCount);
	~SparseMatrix();

	int get(int r, int c);
	void set(int r, int c, int v);
	bool isEmpty() const;
	//int size() const;

	void significantElements(std::vector<int>& v);
	SparseMatrix addition(SparseMatrix& SM);
	SparseMatrix subtraction(SparseMatrix& SM);
	SparseMatrix multiplication(SparseMatrix& SM);
	
	void print();
};
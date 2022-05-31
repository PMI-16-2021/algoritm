#pragma once
#include <vector>
#include <iostream>
using namespace std;

template<typename T>
struct matrixNode
{
	int row = 0;
	int col = 0;
	T val = 0;
	matrixNode* topElement = this;
	matrixNode* leftElement = this;
};

template<typename T>
class SpaceMatrix {
private:
	int elements;
	std::vector<matrixNode<T>> rows;
	std::vector<matrixNode<T>> columns;
	int rowCount;
	int colCount;
	matrixNode<T>* getPrevByRow(int r, int c);
	matrixNode<T>* getPrevByCol(int r, int c);
public:
	SpaceMatrix();
	SpaceMatrix(int _countRow, int _countCol);
	~SpaceMatrix();
	void set(int r, int c, T value);
	T get(int r, int c);
	void print();
	void significantElements(vector<T>& v);
	void subtraction(SpaceMatrix& m);
	void addition(SpaceMatrix& m);
	void multiplication(SpaceMatrix& m);
};
template<typename T>
SpaceMatrix<T>::SpaceMatrix() :
	rowCount(0), colCount(0), elements(0)
{}
template<typename T>
SpaceMatrix<T>::SpaceMatrix(int _countRow, int _countCol) :
	rowCount(_countRow), colCount(_countCol), elements(0)
{
	rows.resize(rowCount + 1);
	columns.resize(colCount + 1);
}
template<typename T>
SpaceMatrix<T>::~SpaceMatrix() {}
template<typename T>
matrixNode<T>* SpaceMatrix<T>::getPrevByRow(int r, int c)
{
	matrixNode<T>* prevNode = &rows[r];
	while (prevNode->leftElement->col > c) {
		prevNode = prevNode->leftElement;
	}
	return prevNode;
}
template<typename T>
matrixNode<T>* SpaceMatrix<T>::getPrevByCol(int r, int c)
{
	matrixNode<T>* prevNode = &rows[c];
	while (prevNode->topElement->row > r) {
		prevNode = prevNode->topElement;
	}
	return prevNode;
}
template<typename T>
void SpaceMatrix<T>::set(int r, int c, T value)
{
	if (value == 0)
	{
		return;
	}
	if (r > rowCount || r<0 || c>colCount || c < 0) {
		cout << "wrong row or column\n";
		return;
	}
	matrixNode<T>* prevRowNode = getPrevByRow(r, c);
	matrixNode<T>* prevColNode = getPrevByCol(r, c);
	bool is = prevColNode->topElement->row == r && prevColNode->topElement->col == c;
	if (is)
	{
		if (value == 0) {
			matrixNode<T>* tempNode = prevRowNode->leftElement;
			prevRowNode->leftElement = tempNode->leftElement;
			prevColNode->topElement = tempNode->topElement;
			tempNode = nullptr;
			++elements;
		}
		else {
			prevRowNode->leftElement->val = value;
		}
	}
	else {
		matrixNode<T>* newElNode = new matrixNode<T>;
		newElNode->row = r;
		newElNode->col = c;
		newElNode->val = value;
		newElNode->leftElement = prevRowNode->leftElement;
		prevRowNode->leftElement = newElNode;
		newElNode->topElement = prevColNode->topElement;
		prevColNode->topElement = newElNode;
		++elements;
	}
}
template<typename T>
T SpaceMatrix<T>::get(int r, int c)
{
	double value = 0;
	matrixNode<T>* prevColNode = getPrevByCol(r, c);
	bool is = prevColNode->topElement->row == r && prevColNode->topElement->col == c;
	if (is) {
		value = prevColNode->topElement->val;
	}
	return value;
}
template<typename T>
void SpaceMatrix<T>::print() {
	for (int i = 0; i <= rowCount; ++i) {
		for (int j = 0; j <= colCount; ++j) {
			cout << get(i, j) << " ";
			if (j == colCount) {
				cout << endl;
			}
		}
	}
}
template<typename T>
void SpaceMatrix<T>::significantElements(vector<T>& v)
{
	for (int i = 0; i <= rowCount; ++i){
		for (int j = 0; j <= colCount; ++j){
			T value = get(i, j);
			if (value != 0) {
				v.push_back(value);
			}
		}
	}
}
template<typename T>
void SpaceMatrix<T>::subtraction(SpaceMatrix& m)
{
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < colCount; ++j) {
			double value = get(i, j) - m.get(i, j);
			set(i, j, value);
		}
	}
}
template<typename T>
void SpaceMatrix<T>::addition(SpaceMatrix& m) 
{
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < colCount; ++j) {
			double value = get(i, j) + m.get(i, j);
			set(i, j, value);
		}
	}
}
template<typename T>
void SpaceMatrix<T>::multiplication(SpaceMatrix& m)
{
	double temp = 0;
	SpaceMatrix t(rowCount, m.colCount);
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < m.colCount; ++j) {
			for (int r = 0; r < m.rowCount; ++r) {
				temp = get(i, r) * m.get(r, j);
			}
			t.set(i, j, temp);
			temp = 0;
		}
	}
	colCount = m.colCount;
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < colCount; ++j) {
			double value = get(i, j) + m.get(i, j);
			set(i, j, m.get(i,j));
		}
	}
}

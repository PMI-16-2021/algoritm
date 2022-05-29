#include <iostream>
#include <vector>
using namespace std;

struct Element {
	int column = 0;
	int row = 0;
	int value = 0;
	Element* upper = this;
	Element* left = this;
};

class SparseMatrix {
private:
	vector<Element> rows;
	vector<Element> columns;
	int rowCount;
	int columnCount;
	int elements;
	Element* getPreviousByRow(int i, int j);
	Element* getPreviousByColumn(int i, int j);

public:
	SparseMatrix();
	SparseMatrix(int _rowCount, int _columnCount);
	~SparseMatrix();

	int get(int row, int col);
	void set(int row, int col, int value);
	void significantElements(vector<int>& vec);
	SparseMatrix addition(SparseMatrix& other);
	SparseMatrix subtraction(SparseMatrix& other);
	SparseMatrix multiplication(SparseMatrix& other);
	int size() const;
	bool isEmpty() const;
	void print();
};
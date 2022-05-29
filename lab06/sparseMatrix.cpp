#include "sparseMatrix.h"

Element* SparseMatrix::getPreviousByRow(int row, int col) {
	Element* previous = &rows[row];
	while (previous->left->column > col) {
		previous = previous->left;
	}
	return previous;

}
Element* SparseMatrix::getPreviousByColumn(int row, int col) {
	Element* previous = &columns[col];
	while (previous->upper->row > row) {
		previous = previous->upper;
	}
	return previous;
}

SparseMatrix::SparseMatrix() : rowCount(0), columnCount(0), elements(0) {}

SparseMatrix::SparseMatrix(int _rowCount, int _columnCount) : rowCount(_rowCount), columnCount(_columnCount), elements(0) {
	rows.resize(rowCount);
	columns.resize(columnCount);
}

SparseMatrix::~SparseMatrix() {}

int SparseMatrix::get(int row, int col) {
	if (row > rowCount || row < 0 || col > columnCount || col < 0) {
		throw "Index out of range";
	}
	Element* previousByRow = getPreviousByRow(row, col);
	if (previousByRow->left->column == col && previousByRow->left->row == row) {
		return previousByRow->left->value;
	}
	return 0;
}

void SparseMatrix::set(int row, int col, int value) {
	if (row > rowCount || row < 0 || col > columnCount || col < 0) {
		throw "Index out of range";
	}
	if (value == 0) {
		return;
	}
	Element* previousByRow = getPreviousByRow(row, col);
	Element* previousByColumn = getPreviousByColumn(row, col);
	if (previousByColumn->upper->row == row && previousByColumn->upper->column == col) {
		if (value == 0) {
			Element* newMatrix = previousByRow->left;
			previousByRow->left = newMatrix->left;
			previousByColumn->upper = newMatrix->upper;
			newMatrix = nullptr;
			++elements;
		}
		else {
			previousByRow->left->value = value;
		}
	}
	else {
		Element* newMatrix = new Element;
		newMatrix->row = row;
		newMatrix->column = col;
		newMatrix->value = value;
		newMatrix->left = previousByRow->left;
		previousByRow->left = newMatrix;
		newMatrix->upper = previousByColumn->upper;
		previousByColumn->upper = newMatrix;
		++elements;
	}

}

void SparseMatrix::significantElements(vector<int>& vec) {
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount; ++j) {
			int value = get(i, j);
			if (value != 0) {
				vec.push_back(value);
			}
		}
	}
}

SparseMatrix SparseMatrix::addition(SparseMatrix& other) {
	if (other.columnCount != columnCount || other.rowCount != rowCount) {
		std::cout << "Size of matrix doesn`t fit";
	}
	else {
		SparseMatrix newMatrix(rowCount, columnCount);
		for (int i = 0; i < rowCount; ++i) {
			for (int j = 0; j < columnCount; ++j) {
				int val = get(i, j) + other.get(i, j);
				newMatrix.set(i, j, val);
			}
		}
		return newMatrix;
	}
}

SparseMatrix SparseMatrix::subtraction(SparseMatrix& other) {
	if (other.columnCount != columnCount || other.rowCount != rowCount) {
		std::cout << "Size of matrix doesn`t fit";
	}
	else {
		SparseMatrix newMatrix(rowCount, columnCount);
		for (int i = 0; i < rowCount; ++i) {
			for (int j = 0; j < columnCount; ++j) {
				int val = get(i, j) - other.get(i, j);
				newMatrix.set(i, j, val);
			}
		}
		return newMatrix;
	}
}

SparseMatrix SparseMatrix::multiplication(SparseMatrix& other) {
	if (columnCount != other.rowCount) {
		std::cout << "Size of matrix doesn`t fit";
	}
	SparseMatrix newMatrix(rowCount, other.columnCount);
	int temp = int();
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < other.columnCount; ++j) {
			temp = int();
			for (int n = 0; n < columnCount; ++n) {
				temp += get(i, n) * other.get(n, j);
			}
			newMatrix.set(i, j, temp);
		}
	}
	return newMatrix;
}

int SparseMatrix::size() const {
	return elements;
}

bool SparseMatrix::isEmpty() const {
	if (elements == 0) {
		return true;
	}
	return false;
}

void SparseMatrix::print() {
	for (int i = 0; i < rowCount; ++i) {
		for (int j = 0; j < columnCount; ++j) {
			std::cout << get(i, j) << ' ';
		}
		std::cout << '\n';
	}
}
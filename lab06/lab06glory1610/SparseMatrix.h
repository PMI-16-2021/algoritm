#pragma once
#include<vector>
#include<iostream>

template<typename T>
struct Node {
	T value;
	int row_index;
	int col_index;
	Node* row_link;
	Node* column_link;
	Node()
		: value(0), row_index(0), col_index(0), row_link(this), column_link(this)
	{}
};

template<typename T>
class SparseMatrix {
private:
	std::vector<Node<T>> rows;
	std::vector<Node<T>> columns;
	int row_count;
	int column_count;
	int element;
	Node<T>* GetPreviousByRow(int row, int col);
	Node<T>* GetPreviousByColumn(int row, int col);
public:
	SparseMatrix();
	SparseMatrix(int row, int col);
	~SparseMatrix();
	T get(int row, int col);
	void set(int row, int col, T value);
	std::vector<T> significant_elements();
	SparseMatrix<T> addition(SparseMatrix<T>& matrix);
	SparseMatrix<T> subtraction(SparseMatrix<T>& matrix);
	SparseMatrix<T> multiplication(SparseMatrix<T>& matrix);
	int size() const;
	void print();
};

template<typename T>
Node<T>* SparseMatrix<T>::GetPreviousByRow(int row, int col) {
	Node<T>* prev = &rows[row];
	while (prev->row_link->col_index > col) {
		prev = prev->row_link;
	}
	return prev;
}

template<typename T>
Node<T>* SparseMatrix<T>::GetPreviousByColumn(int row, int col) {
	Node<T>* prev = &columns[col];
	while (prev->column_link->row_index > row) {
		prev = prev->column_link;
	}
	return prev;
}

template<typename T>
SparseMatrix<T>::SparseMatrix() 
	: row_count(0), column_count(0), element(0)
{}

template<typename T>
SparseMatrix<T>::SparseMatrix(int row, int col)
	: row_count(row), column_count(col), element(0) {
	rows.resize(row_count);
	columns.resize(column_count);
}

template<typename T>
SparseMatrix<T>::~SparseMatrix()
{}

template<typename T>
T SparseMatrix<T>::get(int row, int col) {
	if (row > row_count || row < 0 || col > column_count || col < 0) {
		throw "Bad index";
	}
	Node<T>* prevByRow = GetPreviousByRow(row, col);
	if (prevByRow->row_link->col_index == col && prevByRow->row_link->row_index == row) {
		return prevByRow->row_link->value;
	}
	return 0;
}

template<typename T>
void SparseMatrix<T>::set(int row, int col, T value) {
	if (row > row_count || row < 0 || col > column_count || col < 0) {
		throw "Bad index";
	}
	if (value == 0) {
		return;
	}
	Node<T>* prevByRow = GetPreviousByRow(row, col);
	Node<T>* prevByColumn = GetPreviousByColumn(row, col);
	if (prevByColumn->column_link->row_index == row && prevByColumn->column_link->col_index == col) {
		if (value == 0) {
			Node<T>* temp = prevByRow->row_link;
			prevByRow->row_link = temp->row_link;
			prevByColumn->column_link = temp->column_link;
			temp = nullptr;
			++element;
		}
		else {
			prevByRow->row_link->value = value;
		}
	}
	else {
		Node<T>* temp = new Node<T>;
		temp->row_index = row;
		temp->col_index = col;
		temp->value = value;
		temp->row_link = prevByRow->row_link;
		prevByRow->row_link = temp;
		temp->column_link = prevByColumn->column_link;
		prevByColumn->column_link = temp;
		++element;
	}
}

template<typename T>
std::vector<T> SparseMatrix<T>::significant_elements() {
	std::vector<T> elements;
	for (int i = 1; i <= row_count; i++) {
		for (int j = 1; j <= column_count; ++j) {
			if (get(i, j) != 0) {
				elements.push_back(get(i, j));
			}
		}
	}
	return elements;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::addition(SparseMatrix<T>& matrix) {
	if (matrix.column_count != column_count || matrix.row_count != row_count) {
		throw "Bad size";
	}
	else {
		SparseMatrix<T> newMatrix(row_count, column_count);
		for (int i = 0; i < row_count; ++i) {
			for (int j = 0; j < column_count; ++j) {
				T value = get(i, j) + matrix.get(i, j);
				newMatrix.set(i, j, value);
			}
		}
		return newMatrix;
	}
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::subtraction(SparseMatrix<T>& matrix) {
	if (matrix.column_count != column_count || matrix.row_count != row_count) {
		throw "Bad size";
	}
	else {
		SparseMatrix<T> newMatrix(row_count, column_count);
		for (int i = 0; i < row_count; ++i) {
			for (int j = 0; j < column_count; ++j) {
				T value = get(i, j) - matrix.get(i, j);
				newMatrix.set(i, j, value);
			}
		}
		return newMatrix;
	}
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::multiplication(SparseMatrix<T>& matrix) {
	if (column_count != matrix.row_count) {
		throw "Bad size";
	}
	SparseMatrix<T> newMatrix(row_count, matrix.column_count);
	T temp = T();
	for (int i = 0; i < row_count; ++i) {
		for (int j = 0; j < matrix.column_count; ++j) {
			temp = T();
			for (int k = 0; k < column_count; ++k) {
				temp += get(i, k) * matrix.get(k, j);
			}
			newMatrix.set(i, j, temp);
		}
	}
	return newMatrix;
}

template<typename T>
int  SparseMatrix<T>::size() const {
	return element;
}

template<typename T>
void SparseMatrix<T>::print() {
	for (int i = 0; i < row_count; ++i) {
		for (int j = 0; j < column_count; ++j) {
			std::cout << get(i, j) << ' ';
		}
		std::cout << '\n';
	}
}


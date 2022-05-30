#pragma once
#include <vector>
#include <iostream>

template<typename T>
struct Node {
	T value;
	size_t row;
	size_t col;
	Node* up_col;
	Node* left_row;
	Node(T val = T(), size_t r = 0, size_t c = 0) :
		value(val), row(r), col(c), up_col(this), left_row(this) {};
};

template<typename T>
class SparseMatrix {
private:
	std::vector<Node<T>> rows;
	std::vector<Node<T>> columns;
	size_t row_c;
	size_t col_c;
	size_t elem_c;
	Node<T>* getPreviousByRow(size_t row, size_t col);
	Node<T>* getPreviousByColumn(size_t row, size_t col);
public:

	SparseMatrix() : row_c(0), col_c(0), elem_c(0) {
		rows.resize(0);
		columns.resize(0);
	}

	SparseMatrix(size_t r, size_t c) : row_c(r), col_c(c), elem_c(0) {
		rows.resize(r);
		columns.resize(c);
	}

	~SparseMatrix() {
		rows.clear();
		columns.clear();
	}

	void set(size_t r, size_t c, T val);
	T get(size_t r, size_t c);
	void significant_elements(std::vector<T> vec);
	SparseMatrix<T> addition(SparseMatrix<T> matrix);
	SparseMatrix<T> subtraction(SparseMatrix<T> matrix);
	SparseMatrix<T> multiplication(SparseMatrix<T> matrix);
	void print();

};

template<typename T>
Node<T>* SparseMatrix<T>::getPreviousByRow(size_t row, size_t col) {
	Node<T>* prev = &rows[row];
	while (prev->left_row->col > col) {
		prev = prev->left_row;
	}
	return prev;
}

template<typename T>
Node<T>* SparseMatrix<T>::getPreviousByColumn(size_t row, size_t col) {
	Node<T>* prev = &columns[col];
	while (prev->up_col->row > row) {
		prev = prev->up_col;
	}
	return prev;
}

template<typename T>
void SparseMatrix<T>::set(size_t r, size_t c, T val) {
	Node<T>* previous_by_row = getPreviousByRow(r, c);
	Node<T>* previous_by_column = getPreviousByColumn(r, c);
	if (previous_by_column->up_col->row == r && previous_by_column->up_col->col == c) {
		if (val == 0) {
			Node<T>* victim = previous_by_row->left_row;
			previous_by_row->left_row = victim->left_row;
			previous_by_column->up_col = victim->up_col;
			victim = nullptr;
			++elem_c;
		}
		else {
			previous_by_row->left_row->value = val;
		}
	}
	else {
		Node<T>* temp = new Node<T>;
		temp->row = r;
		temp->col = c;
		temp->value = val;
		temp->left_row = previous_by_row->left_row;
		previous_by_row->left_row = temp;
		temp->up_col = previous_by_column->up_col;
		previous_by_column->up_col = temp;
		++elem_c;
	}
}

template<typename T>
T SparseMatrix<T>::get(size_t r, size_t c) {
	Node<T>* previous_by_row = getPreviousByRow(r, c);
	if (previous_by_row->left_row->col == c && previous_by_row->left_row->row == r) {
		return previous_by_row->left_row->value;
	}
	return T();
}

template<typename T>
void SparseMatrix<T>::significant_elements(std::vector<T> vec) {
	for (size_t i = 0; i < row_c; ++i) {
		for (size_t j = 0; j < col_c; ++j) {
			T temp = get(i, j);
			if (temp != 0) {
				vec.push_back(temp);
			}
		}
	}
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::addition(SparseMatrix<T> matrix) {
	if (matrix.col_c != col_c || matrix.row_c != row_c) {
		std::cout << "Matrixx size must be equal";
		return SparseMatrix();
	}
	SparseMatrix<T> temp(row_c, col_c);
	for (size_t i = 0; i < row_c; ++i) {
		for (size_t j = 0; j < col_c; ++j) {
			T val = get(i, j) + matrix.get(i, j);
			temp.set(i, j, val);
		}
	}
	return temp;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::subtraction(SparseMatrix<T> matrix) {
	if (matrix.col_c != col_c || matrix.row_c != row_c) {
		std::cout << "ERROR: Matrixx size must be equal";
		return SparseMatrix();
	}

	SparseMatrix<T> temp(row_c, col_c);
	for (size_t i = 0; i < row_c; ++i) {
		for (size_t j = 0; j < col_c; ++j) {
			T val = get(i, j) - matrix.get(i, j);
			temp.set(i, j, val);
		}
	}
	return temp;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::multiplication(SparseMatrix<T> matrix) {
	if (col_c != matrix.row_c) {
		std::cout << "ERROR: Matrix row must be equal to column count";
		return SparseMatrix();
	}

	SparseMatrix<T> temp(row_c, matrix.col_c);
	for (size_t i = 0; i < row_c; ++i) {
		for (size_t j = 0; j < matrix.col_c; ++j) {
			T val = T();
			for (size_t n = 0; n < col_c; ++n) {
				val += get(i, n) * matrix.get(n, j);
			}
			temp.set(i, j, val);
		}
	}
	return temp;
}

template<typename T>
void SparseMatrix<T>::print() {
	for (size_t i = 0; i <= row_c; ++i) {
		for (size_t j = 0; j <= col_c; ++j) {
			std::cout << get(i, j) << ' ';
		}
		std::cout << '\n';
	}
}


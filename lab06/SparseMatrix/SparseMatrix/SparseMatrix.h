#pragma once
#include <iostream>
#include <vector>

template<typename T>
struct Element {
	Element* upper_element = this;
	Element* left_element = this;
	//from 1 to N
	int row = 0;
	//from 1 to N
	int column = 0;
	T value;
};

template<typename T>
class SparseMatrix
{
	int rows_count;
	int cols_count;
	std::vector<Element<T>> cols;
	std::vector<Element<T>> rows;

	Element<T>* getPrevByRow(int row, int column);
	Element<T>* getPrevByCol(int row, int column);
	void addValueImpl(Element<T>* previous_by_row, Element<T>* previous_by_col, int row, int column, T value);
	void changeValueImpl(Element<T>* previous_by_row, Element<T>* previous_by_col, int row, int column, T value);

public:
	SparseMatrix(int _rows_count, int _cols_count);
	void set(int row, int column, T value);
	T get(int row, int column);
	std::vector<T> significant_elements();
	void addition(SparseMatrix& arg2);
	void subtraction(SparseMatrix& arg2);
	void multiplication(SparseMatrix& arg2);
	void print_matrix();
};

template<typename T>
Element<T>* SparseMatrix<T>::getPrevByRow(int row, int column) {
	Element<T>* prev = &rows[row];
	while (prev->left_element->column > column)
	{
		prev = prev->left_element;
	}
	return prev;
}

template<typename T>
Element<T>* SparseMatrix<T>::getPrevByCol(int row, int column) {
	Element<T>* prev = &cols[column];
	while (prev->upper_element->row > row)
	{
		prev = prev->upper_element;
	}
	return prev;
}

//element does not exists
//add it
template<typename T>
void SparseMatrix<T>::addValueImpl(Element<T>* previous_by_row, Element<T>* previous_by_col, int row, int column, T value) {
	Element<T>* new_element = new Element<T>();
	new_element->row = row;
	new_element->column = column;
	new_element->value = value;
	new_element->left_element = previous_by_row->left_element;
	previous_by_row->left_element = new_element;
	new_element->upper_element = previous_by_col->upper_element;
	previous_by_col->upper_element = new_element;
}

template<typename T>
void SparseMatrix<T>::changeValueImpl(Element<T>* previous_by_row, Element<T>* previous_by_col, int row, int column, T value) {
	if (value == 0) {
		Element<T>* elem_to_del = previous_by_row->left_element;
		previous_by_row->left_element = elem_to_del->left_element;
		previous_by_col->upper_element = elem_to_del->upper_element;
		delete elem_to_del;
	}
	else {
		previous_by_row->left_element->value = value;
	}
}

template<typename T>
SparseMatrix<T>::SparseMatrix(int _rows_count, int _cols_count) :rows_count(_rows_count), cols_count(_cols_count) {
	cols.resize(cols_count + 1);
	rows.resize(rows_count + 1);
}

//set a[row, column]
//row = 1..row_count
//column = 1..column_count
template<typename T>
void SparseMatrix<T>::set(int row, int column, T value) {
	//get element that is previous by row and column
	Element<T>* previous_by_row = getPrevByRow(row, column);
	Element<T>* previous_by_col = getPrevByCol(row, column);
	//is there element in matrix?
	bool element_in_matrix = previous_by_col->upper_element->row == row &&
		previous_by_col->upper_element->column == column;
	if (element_in_matrix) {
		changeValueImpl(previous_by_row, previous_by_col, row, column, value);
	}
	else {
		addValueImpl(previous_by_row, previous_by_col, row, column, value);
	}
}

//get a[row, column]
//row = 1..row_count
//column = 1..column_count
template<typename T>
T SparseMatrix<T>::get(int row, int column) {
	double ret_value = 0;
	Element<T>* previous_by_col = getPrevByCol(row, column);
	bool element_in_matrix = previous_by_col->upper_element->row == row && previous_by_col->upper_element->column == column;
	if (element_in_matrix) {
		ret_value = previous_by_col->upper_element->value;
	}
	return ret_value;
}

template<typename T>
std::vector<T> SparseMatrix<T>::significant_elements() {
	std::vector<T> SignificantElements;
	for (int i = 1; i <= rows_count; i++) {
		for (int j = 1; j <= cols_count; j++) {
			if (get(i, j) != 0) {
				SignificantElements.push_back(get(i, j));
			}
		}
	}
	return SignificantElements;
}

template<typename T>
void SparseMatrix<T>::addition(SparseMatrix& arg2) {
	for (int i = 1; i <= rows_count; i++) {
		for (int j = 1; j <= cols_count; j++) {
			double value = get(i, j) + arg2.get(i, j);
			set(i, j, value);
		}
	}
}

template<typename T>
void SparseMatrix<T>::subtraction(SparseMatrix& arg2) {
	for (int i = 1; i <= rows_count; i++) {
		for (int j = 1; j <= cols_count; j++) {
			double value = get(i, j) - arg2.get(i, j);
			set(i, j, value);
		}
	}
}

template<typename T>
void SparseMatrix<T>::multiplication(SparseMatrix& arg2) {
	double temp_value = 0;
	SparseMatrix x(rows_count, arg2.cols_count);

	for (int i = 1; i <= rows_count; i++) {
		for (int j = 1; j <= arg2.cols_count; j++) {
			for (int r = 1; r <= arg2.rows_count; r++) {
				temp_value += get(i, r) * arg2.get(r, j);
			}

			x.set(i, j, temp_value);
			temp_value = 0;
		}
	}

	cols_count = arg2.cols_count;
	for (int i = 1; i <= rows_count; i++) {
		for (int j = 1; j <= cols_count; j++) {
			set(i, j, x.get(i, j));
		}
	}
}

template<typename T>
void SparseMatrix<T>::print_matrix() {
	for (int i = 1; i <= rows_count; i++) {
		for (int j = 1; j <= cols_count; j++) {
			std::cout << get(i, j) << " ";
			if (j == cols_count) {
				std::cout << '\n';
			}
		}
	}
}

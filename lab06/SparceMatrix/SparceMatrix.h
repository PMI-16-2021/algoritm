#pragma once
#include "MatrixNode.h"
#include <utility>
#include <vector>
#include <iostream>
using std::vector;
using std::pair;

template<typename T>
class SparceMatrix
{
private:
	MatrixNode<T>* rows;
	MatrixNode<T>* columns;
	size_t no_of_rows;
	size_t no_of_cols;
	size_t elems;
	MatrixNode<T>* getPrevByRow(size_t row, size_t col) const;
	MatrixNode<T>* getPrevByCol(size_t row, size_t col) const;
	void clear_matrix();
	void copy_matrix(const SparceMatrix<T>& M);
public:
	SparceMatrix(int rows, int cols);
	SparceMatrix(const SparceMatrix<T>& M);
	~SparceMatrix();
	void significant_elements(vector<RawElem<T>>& vect) const;
	SparceMatrix& addition(SparceMatrix& other);
	SparceMatrix& substraction(SparceMatrix& other);
	SparceMatrix& multiplication(SparceMatrix& other);
	T get(int i, int j) const;
	void set(int row, int col, T value);
	void erase_elem(int row, int col);
	const MatrixNode<T>& operator[](int ind) const;
	void print(std::ostream& out = std::cout) const;
};

template<typename T>
MatrixNode<T>* SparceMatrix<T>::getPrevByRow(size_t row, size_t col) const
{
	MatrixNode<T>* temp = &rows[row];
	while (temp->left->col > col)
	{
		temp = temp->left;
	}
	return temp;
}

template<typename T>
MatrixNode<T>* SparceMatrix<T>::getPrevByCol(size_t row, size_t col) const
{
	MatrixNode<T>* temp = &columns[col];
	while (temp->up->row > row)
	{
		temp = temp->up;
	}
	return temp;
}

template<typename T>
void SparceMatrix<T>::clear_matrix()
{
	MatrixNode<T>* temp;
	MatrixNode<T>* victim;
	for (size_t i = 0; i < no_of_cols; i++)
	{
		temp = columns[i].up;
		while (temp != & columns[i])
		{
			victim = temp;
			temp = temp->up;
			delete victim;
		}
	}
	elems = 0;
}

template<typename T>
SparceMatrix<T>::SparceMatrix(int _rs, int _cls): elems(0)
{
	no_of_rows = (_rs > 0) ? _rs : 5; 
	no_of_cols = (_cls > 0) ? _cls : 5;
	rows = new MatrixNode<T>[no_of_rows];
	columns = new MatrixNode<T>[no_of_cols];

	for (size_t i = 0; i < no_of_rows; i++)
	{
		rows[i].left = &rows[i];
	}
	for (size_t i = 0; i < no_of_cols; i++)
	{
		columns[i].up = &columns[i];
	}
}

template<typename T>
SparceMatrix<T>::SparceMatrix(const SparceMatrix<T>& M)
{
	no_of_rows = M.no_of_rows;
	no_of_cols = M.no_of_cols;
	rows = new MatrixNode<T>[no_of_rows];
	columns = new MatrixNode<T>[no_of_cols];

	for (size_t i = 0; i < no_of_rows; i++)
	{
		rows[i].left = &rows[i];
	}
	for (size_t i = 0; i < no_of_cols; i++)
	{
		columns[i].up = &columns[i];
	}
	copy_matrix(M);
}

template<typename T>
SparceMatrix<T>::~SparceMatrix()
{
	clear_matrix();
	delete[] columns;
	delete[] rows;
}

template<typename T>
void SparceMatrix<T>::significant_elements(vector<RawElem<T>>& vect) const
{
	//vect.reserve(elems);
	RawElem<T>* arr = new RawElem<T>[elems];
	size_t cont = 0;
	for (size_t i = 0; i < no_of_rows; i++)
	{
		MatrixNode<T>* temp = rows[i].left;
		while (temp != &rows[i])
		{
			vect.push_back(RawElem<T>(temp->row, temp->col, temp->val));
			temp = temp->left;
		}
	}
}

template<typename T>
inline T SparceMatrix<T>::get(int row, int col) const
{
	MatrixNode<T>* temp = getPrevByRow(row, col);
	if (temp->left->col == col)
	{
		return temp->left->val;
	}
	return T();
}

template<typename T>
void SparceMatrix<T>::set(int row, int col, T value)
{
	if (row >= no_of_rows || row < 0 || col >= no_of_cols || col < 0 || value == T())
	{
		//TODO: create exception
	}
	MatrixNode<T>* prev_by_row = getPrevByRow(row, col);
	MatrixNode<T>* prev_by_col = getPrevByCol(row, col);
	MatrixNode<T>* to_add = new MatrixNode<T>(value, row,
		        col, prev_by_col->up, prev_by_row->left);
	prev_by_row->left = to_add;
	prev_by_col->up = to_add;
}

template<typename T>
void SparceMatrix<T>::erase_elem(int row, int col)
{
	MatrixNode<T>* prev_by_row = getPrevByRow(row, col);
	MatrixNode<T>* prev_by_col = getPrevByCol(row, col);
	MatrixNode<T>* victim = prev_by_col->up;
	if (victim->row == row)
	{
		prev_by_col->up = victim->up;
		prev_by_row->left = victim->left;
		--elems;
		delete victim;
	}
}

template<typename T>
const MatrixNode<T>& SparceMatrix<T>::operator[](int ind) const
{
	if (ind >= no_of_rows || ind < 0)
	{
		//TODO: exception
	}
	return rows[ind];
}

template<typename T>
void SparceMatrix<T>::print(std::ostream& out) const
{
	for (size_t i = 0; i < no_of_rows; i++)
	{
		for (size_t k = 0; k < no_of_cols; k++)
		{
			out.width(3);
			out << this->operator[](i).operator[](k) << ' ';
		}
		out << '\n';
	}
}

template<typename T>
void SparceMatrix<T>::copy_matrix(const SparceMatrix<T>& M)
{
	clear_matrix();
	for (size_t i = 0; i < M.no_of_rows; i++)
	{
		MatrixNode<T>* temp = M.rows[i].left;
		while (temp != &M.rows[i])
		{
			this->set(temp->row, temp->col, temp->val);
			temp = temp->left;
		}
	}
}
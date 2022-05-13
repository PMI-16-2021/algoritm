#pragma once
#include <memory>

template<typename T> 
struct MatrixNode
{
	T val;
	size_t row;
	size_t col;
	MatrixNode* up;
	MatrixNode* left;
	MatrixNode(T val = T(), size_t row = 0, size_t col = 0, MatrixNode* _up = nullptr, MatrixNode* _left = nullptr);
	const T& operator[](int ind) const;
};

template<typename T>
MatrixNode<T>::MatrixNode(T _val, size_t _row, size_t _col, MatrixNode* _up, MatrixNode* _left)
{
	val = _val;
	row = _row;
	col = _col;
	up = _up;
	left  = _left;
}

template<typename T>
const T& MatrixNode<T>::operator[](int ind) const
{
	MatrixNode<T>* temp = this->left;
	while (temp != this && temp->col > ind)
	{
		temp = temp->left;
	}
	if (temp->col == ind)
	{
		return temp->val;
	}
	return T();
}

template<typename T>
struct RawElem
{
	size_t row;
	size_t column;
	T elem;
	RawElem(size_t _row, size_t _col, T _val): row(_row), column(_col), elem(_val){}
	RawElem(): row(0), column(0), elem(T()){}
};
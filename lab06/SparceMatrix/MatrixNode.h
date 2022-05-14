#pragma once
#include <iostream>

// matrix node struct
template<typename T> 
struct MatrixNode
{
	T val;                           // holds value
	size_t row;                      // number of row it represents
	size_t col;                      // number of col it represents
	MatrixNode* up;                  // up-pointer (for next in cols)
	MatrixNode* left;                // left pointer (for next in rows)
	MatrixNode(T val = T(), size_t row = 0, size_t col = 0, MatrixNode* _up = nullptr, MatrixNode* _left = nullptr);
	const T operator[](int ind) const; // operator go get value
};

// constructor for MatrixNode
template<typename T>
MatrixNode<T>::MatrixNode(T _val, size_t _row, size_t _col, MatrixNode* _up, MatrixNode* _left)
{
	val = _val;
	row = _row;
	col = _col;
	up = _up;
	left  = _left;
}

// operator[] for matrix
template<typename T>
const T MatrixNode<T>::operator[](int ind) const
{
	if (ind < 0)
	{
		//throw std::invalid_argument("BAD ACCESS INDEX!\n");
	}
	MatrixNode<T>* temp = this->left;       
	while (temp != this && temp->col > ind) // while not in the begin and col is bigger
	{
		temp = temp->left;                  // move
	}
	if (temp->col == ind)                   // if MatrixNode with col number exists 
	{
		return temp->val;                   // return its val
	}
	return T();                             // else return T();
}

// struct for 
// significant elements funct
template<typename T>
struct RawElem
{
	size_t row;
	size_t column;
	T elem;
	RawElem(size_t _row, size_t _col, T _val): row(_row), column(_col), elem(_val){}
	RawElem(): row(0), column(0), elem(T()){}
};

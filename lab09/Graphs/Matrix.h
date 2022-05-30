#pragma once
#include <iostream>
#include <vector>
using std::vector;


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
	left = _left;
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
	RawElem(size_t _row, size_t _col, T _val) : row(_row), column(_col), elem(_val) {}
	RawElem() : row(0), column(0), elem(T()) {}
};



//Class SparceMatrix represetns real matrix
//where most of elems are zeros
//uses less memoy
template<typename T>
class SparceMatrix
{
private:
	MatrixNode<T>* rows;                                               // pointer to array of row elements
	MatrixNode<T>* columns;                                            // pointer to array of column elements
	size_t no_of_rows;                                                 // number of rows in matrix
	size_t no_of_cols;                                                 // number of columns in matrix
	size_t elems;                                                      // number of non-zero elems
	MatrixNode<T>* getPrevByRow(size_t row, size_t col) const;         // private method to get pev in row by indexes
	MatrixNode<T>* getPrevByCol(size_t row, size_t col) const;         // private method to get pev in col by indexes
	void clear_matrix();                                               // clears all nodes (despite in-arr holders) 
	void copy_matrix(const SparceMatrix<T>& M);                        // copies matrix (deep copy)
	void create(int rs, int cls);                                      // creates matrix based on params

public:
	SparceMatrix();
	SparceMatrix(int rows, int cols);                                  // constructor uses create() method
	SparceMatrix(const SparceMatrix<T>& M);                            // uses create() and copy_matrix() methods
	~SparceMatrix();                                                   // uses clear_matrix()

	T get(int row, int col) const;                                     // retrurns value by indexes  
	void set(int row, int col, T value);                               // sets value by indexes
	void erase_elem(int row, int col);                                 // erase certain element from matrix
	const MatrixNode<T>& operator[](int ind) const;                    // returns MatrixNode to acess by []
	void print(std::ostream& out = std::cout) const;                   // prints all matrix by operator [][]
	SparceMatrix& operator=(const SparceMatrix& M);                    // uses clear_matrix(), create() and copy_method()
	size_t filled() const { return elems; };                           // returns number of non-zero elems
};

//gets previous elem in row
//by indexes
template<typename T>
MatrixNode<T>* SparceMatrix<T>::getPrevByRow(size_t row, size_t col) const
{
	MatrixNode<T>* temp = &rows[row];  // temp == address of row-elem
	while (temp->left->col > col)      // while column of next-to-left > col
	{
		temp = temp->left;             // move left
	}
	return temp;
}

//gets previous elem in column
//by indexes
template<typename T>
MatrixNode<T>* SparceMatrix<T>::getPrevByCol(size_t row, size_t col) const
{
	MatrixNode<T>* temp = &columns[col];  // temp == address of col-elem
	while (temp->up->row > row)           // while row of next-to-up > row
	{
		temp = temp->up;                  //move up
	}
	return temp;
}

// clears all nodes 
// DOESN'T DELETE ARRAYS!!!
template<typename T>
void SparceMatrix<T>::clear_matrix()
{
	MatrixNode<T>* temp;
	MatrixNode<T>* victim;
	for (size_t i = 0; i < no_of_cols; i++)
	{
		temp = columns[i].up;
		while (temp != &columns[i])
		{
			victim = temp;
			temp = temp->up;
			delete victim;
		}
	}
	elems = 0;
}

template<typename T>
SparceMatrix<T>::SparceMatrix()
{
	create(3, 3);
}

// param constructr
template<typename T>
SparceMatrix<T>::SparceMatrix(int _rs, int _cls)
{
	create(_rs, _cls);
}

//copy constructor
template<typename T>
SparceMatrix<T>::SparceMatrix(const SparceMatrix<T>& M)
{
	create(M.no_of_rows, M.no_of_cols);    // creates arrays
	copy_matrix(M);                        // copies inside
}

//delete everything
template<typename T>
SparceMatrix<T>::~SparceMatrix()
{
	clear_matrix();             // clear non-zero elems
	delete[] columns;           // delete arr
	delete[] rows;              // "skeleton"
}

// returns value by indexes
template<typename T>
T SparceMatrix<T>::get(int row, int col) const
{
	if (row >= no_of_rows || row < 0 || col >= no_of_cols || col < 0)
	{
		throw std::invalid_argument("BAD ACCESS INDEX!\n");
	}
	MatrixNode<T>* temp = getPrevByRow(row, col); // get PREV in row
	if (temp->left->col == col)                   // if next's col == col param 
	{
		return temp->left->val;                   //return it
	}
	return T();                                   //else: it doesn't exist: T();
}

// sets elems by indexes
template<typename T>
void SparceMatrix<T>::set(int row, int col, T value)
{
	if ((row >= no_of_rows || row < 0) && (col >= no_of_cols || col < 0))
	{
		throw std::invalid_argument("BAD ACCESS INDEX!\n");
	}
	if (value != T())
	{
		MatrixNode<T>* temp = rows[row].left;           // last in row 
		while (temp->col != col && temp != &rows[row])  // while cols is != and we aren't in begin 
		{
			temp = temp->left;                          // move 
		}
		if (temp != &rows[row])                         // if col was == => val already exists 
		{
			temp->val = value;                          //changeit
			return;                                     //return
		}                                                          // else: doesn't exist: 
		MatrixNode<T>* prev_by_row = getPrevByRow(row, col);       // prev by row
		MatrixNode<T>* prev_by_col = getPrevByCol(row, col);       // prev by column
		MatrixNode<T>* to_add = new MatrixNode<T>(value, row,      // new node with val, indexes
			col, prev_by_col->up, prev_by_row->left);              // inserts inside
		prev_by_row->left = to_add;                                // prev in row points it
		prev_by_col->up = to_add;                                  // prev in col points it
		++elems;
	}
}

//clears specific element
//by indexes
template<typename T>
void SparceMatrix<T>::erase_elem(int row, int col)
{
	if (row >= no_of_rows || row < 0 || col >= no_of_cols || col < 0)
	{
		throw std::invalid_argument("BAD ACCESS INDEX!\n");
	}
	MatrixNode<T>* prev_by_row = getPrevByRow(row, col); // prev in row
	MatrixNode<T>* prev_by_col = getPrevByCol(row, col); // prev in col
	MatrixNode<T>* victim = prev_by_col->up;             // check if elem in top
	if (victim->row == row)                              // has same row
	{                                                    // yes => exists => should delete
		prev_by_col->up = victim->up;                    // pointers "jump over" victim
		prev_by_row->left = victim->left;
		--elems;                                         // decrease non-zero elems
		delete victim;                                   // delete victim 
	}                                                    //if not found => will not be deleted
}

//returns MatrixNode elem
//which also has operator[]
template<typename T>
const MatrixNode<T>& SparceMatrix<T>::operator[](int ind) const
{
	if (ind >= no_of_rows || ind < 0)
	{
		throw std::invalid_argument("BAD ACCESS INDEX!\n");
	}
	return rows[ind];
}

//print matrix
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

//creates full copy of matrix
template<typename T>
void SparceMatrix<T>::copy_matrix(const SparceMatrix<T>& M)
{
	clear_matrix();                                      // delete nodes
	delete[] rows;                                       // and "skeleton"
	delete[] columns;
	create(M.no_of_rows, M.no_of_cols);                  // create new of correct size
	for (size_t i = 0; i < M.no_of_rows; i++)            // for each row
	{
		MatrixNode<T>* temp = M.rows[i].left;            // temp = last in row
		while (temp != &M.rows[i])                       // while we are not in begin
		{
			this->set(temp->row, temp->col, temp->val);  // add copied elem
			temp = temp->left;                           // go to next node in curr marix 
		}
	}
}

//creates new matrix based on params
template<typename T>
void SparceMatrix<T>::create(int rs, int cls)
{
	elems = 0;                                // filled 0
	no_of_rows = (rs > 0) ? rs : 5;           // rows
	no_of_cols = (cls > 0) ? cls : 5;         // columns
	rows = new MatrixNode<T>[no_of_rows];     // row array
	columns = new MatrixNode<T>[no_of_cols];  // column array

	for (size_t i = 0; i < no_of_rows; i++)
	{                                         // for rows
		rows[i].left = &rows[i];              // left points at itself
	}
	for (size_t i = 0; i < no_of_cols; i++)
	{                                         // for columns
		columns[i].up = &columns[i];          // up points at itself
	}
}

//operator = for matrices
template<typename T>
SparceMatrix<T>& SparceMatrix<T>::operator=(const SparceMatrix<T>& M)
{
	clear_matrix();                      // clear this matrix
	delete[] rows;                       // delete array of rows elems
	delete[] columns;                    // delete array of cols elems
	create(M.no_of_rows, M.no_of_cols);  // create new of params
	copy_matrix(M);                      // deep copy of matrix
	return *this;
}

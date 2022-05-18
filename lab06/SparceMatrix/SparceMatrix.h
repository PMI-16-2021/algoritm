#pragma once
#include "MatrixNode.h"
#include <vector>
using std::vector;

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
	SparceMatrix(int rows, int cols);                                  // constructor uses create() method
	SparceMatrix(const SparceMatrix<T>& M);                            // uses create() and copy_matrix() methods
	~SparceMatrix();                                                   // uses clear_matrix()
	void significant_elements(vector<RawElem<T>>& vect) const;         // takes vector and returns it containing non-zero elems
	SparceMatrix addition(const SparceMatrix& other);                  // adds two matrices (returns copy)
	SparceMatrix substraction(const SparceMatrix& other);              // substracts two matrices (returns copy)
	SparceMatrix multiplication(const SparceMatrix& other);            // multiplies two matrices (returns copy)
	T get(int row, int col) const;                                     // retrurns value by indexes  
	void set(int row, int col, T value);                               // sets value by indexes
	void erase_elem(int row, int col);                                 // erase certain element from matrix
	const MatrixNode<T>& operator[](int ind) const;                    // returns MatrixNode to acess by [][]
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
		while (temp != & columns[i])
		{
			victim = temp;
			temp = temp->up;
			delete victim;
		}
	}
	elems = 0;
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

// fills vector with 
// non-zero elems and indexes
template<typename T>
void SparceMatrix<T>::significant_elements(vector<RawElem<T>>& vect) const
{
	vect.reserve(elems);                            // reserve non-zero number of elems
	for (size_t i = 0; i < no_of_rows; i++)         // for each row
	{
		MatrixNode<T>* temp = rows[i].left;         // temp = last col in each row
		while (temp != &rows[i])                    // while not begin of arr
		{
			vect.push_back(RawElem<T>(temp->row, temp->col, temp->val)); //add elem and indexes
			temp = temp->left;                      // mve to next
		}
	}
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
	return T();                             //else: it doesn't exist: T();
}

// sets elems by indexes
template<typename T>
void SparceMatrix<T>::set(int row, int col, T value)
{
	if ((row >= no_of_rows || row < 0) && (col >= no_of_cols || col < 0) || value == T())
	{
		//throw std::invalid_argument("BAD ACCESS INDEX!\n");
	}
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
		        col, prev_by_col->up, prev_by_row->left);      // inserts inside
	prev_by_row->left = to_add;                                // prev in row points it
	prev_by_col->up = to_add;                                  // prev in col points it
	++elems;
}

//clears specific element
//by indexes
template<typename T>
void SparceMatrix<T>::erase_elem(int row, int col)
{
	if (row >= no_of_rows || row < 0 || col >= no_of_cols || col < 0 )
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

//operation of adding matrices
template<typename T>
SparceMatrix<T> SparceMatrix<T>::addition(const SparceMatrix<T>& other)
{
	if (no_of_cols != other.no_of_cols || no_of_rows != other.no_of_rows)
	{
		throw std::invalid_argument("MATRICES DIMENSIONS ARE NOT EQUAL!\n");
	}
	SparceMatrix<T> return_matix(no_of_rows, no_of_cols);             //to be returned
	MatrixNode<T>* from_this;                                         // to navigate this matr
	MatrixNode<T>* from_other;                                        // to navigate other matr
	for (size_t i = 0; i < no_of_rows; i++)
	{
		from_this = rows[i].left;                                     // pointers = last in row of each
		from_other = other.rows[i].left;                              // matrix
		while (from_this != &rows[i] && from_other != &other.rows[i]) // while not end 
		{
			if (from_this->col == from_other->col)                    // if cols are equal
			{
				if (from_this->val != -from_other->val)               // if addition is not 0
				{
					return_matix.set(from_this->row, from_this->col, from_this->val + from_other->val); //set to new matrix
				}
				from_this = from_this->left;                          // move forward in this
				from_other = from_other->left;                        // move forward in second
			}
			else
			{
				if (from_this->col > from_other->col)
				{
					return_matix.set(from_this->row, from_this->col, from_this->val); //set
					from_this = from_this->left;                                      // move only in this
				}
				else                                                                  // cols are not equal
				{                                                                     // if this is lower => this is 0 
					return_matix.set(from_other->row, from_other->col, from_other->val);
					from_other = from_other->left;                                    //move forward for other
				}
			}
			if (from_this == &rows[i] && from_other != &other.rows[i])                // add values that are left
			{
				while (from_other != &other.rows[i])
				{
					return_matix.set(i, from_other->col, from_other->val);
					from_other = from_other->left;
				}
			}
			else if (from_this != &rows[i] && from_other == &other.rows[i])
			{
				while (from_this != &rows[i])
				{
					return_matix.set(i, from_this->col, from_this->val);
					from_this = from_this->left;
				}
			}
		}
	}
	return return_matix;
}

//substract two and return copy
template<typename T>
SparceMatrix<T> SparceMatrix<T>::substraction(const SparceMatrix& other)
{
	if (no_of_cols != other.no_of_cols || no_of_rows != other.no_of_rows)
	{
		throw std::invalid_argument("MATRICES DIMENSIONS ARE NOT EQUAL!\n");
	}
	SparceMatrix<T> return_matix(no_of_rows, no_of_cols);     // to be returned
	MatrixNode<T>* from_this;                                 // to navigate this matrix
	MatrixNode<T>* from_other;                                // to navigate other matr
	for (size_t i = 0; i < no_of_rows; i++)
	{
		from_this = rows[i].left;                             // pointers = last in row of each
		from_other = other.rows[i].left;                      // matrix
		while (from_this != &rows[i] && from_other != &other.rows[i]) //while not end of both
		{
			if (from_this->col == from_other->col)            // if cols are equal
			{
				if (from_this->val != from_other->val)        // if this val - other val != 0
				{
					return_matix.set(from_this->row, from_this->col, from_this->val - from_other->val); //set difference
				}
				from_this = from_this->left;                  // move forward
				from_other = from_other->left;                // for both
			}
			else                                              // cols are not equal
			{
				if (from_this->col > from_other->col)         // if this is begger => substract zero => just val
				{
					return_matix.set(from_this->row, from_this->col, from_this->val); // set 
					from_this = from_this->left;              // move this forward
				}
				else                                          // other is bigger => 0 - other val = -other val
				{
					return_matix.set(from_other->row, from_other->col, -from_other->val);
					from_other = from_other->left;            // move other forward
				}
			}
		}
		if (from_this == &rows[i] && from_other != &other.rows[i])    // add values that are left
		{
			while (from_other != &other.rows[i])
			{
				return_matix.set(i, from_other->col, -from_other->val); // with minus!
				from_other = from_other->left;
			}
		}
		else if (from_this != &rows[i] && from_other == &other.rows[i])
		{
			while (from_this != &rows[i])
			{
				return_matix.set(i, from_this->col, from_this->val);
				from_this = from_this->left;
			}
		}
	}
	return return_matix;
}

// multiplicate two matrices
// using operator
template<typename T>
SparceMatrix<T> SparceMatrix<T>::multiplication(const SparceMatrix& other)
{
	if (no_of_cols != other.no_of_rows)
	{
		throw std::invalid_argument("MATRICES DIMENSIONS NOT SUITABLE FOR MULTIPLICATION!\n");
	}
	SparceMatrix<T> return_item(no_of_rows, other.no_of_cols);  // create new
	T temp = T();                                               // temp to hold sum 
	for (size_t i = 0; i < no_of_rows; i++)
	{
		for (size_t j = 0; j < other.no_of_cols; j++)
		{
			temp = T();                                        // temp = T()
			for (size_t k = 0; k < no_of_cols; k++)
			{
				temp += this->operator[](i)[k] * other[k][j];  // add product on each k
			}
			return_item.set(i, j, temp);                        // set               
		}
	}
	return return_item;
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

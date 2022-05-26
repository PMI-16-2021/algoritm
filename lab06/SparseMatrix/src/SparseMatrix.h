#pragma once

#include <vector>
#include <iostream>
#include "InvalidDimensionsException.h"
#include "InvalidCoordinatesException.h"
//this matrix is built on CSR format
//here we use row_ptr to save memory
template<typename T>
class SparseMatrix {
private:
    int m, n; // m - rows, n - columns
    //rows and columns are indexed from 1
    std::vector<T> *values;
    std::vector<int> *rows, *columns;

    // helping methods and validators
    void construct(int m, int n);

    void destruct();

    void deepCopy(const SparseMatrix<T> &m);

    void validateCoordinates(int row, int column) const;

    void insert(int index, int row, int column, T value);

    void remove(int index, int row);

public:
    // constructor with one parameter (creates square matrix with size n*n)
    SparseMatrix(int n);

    // constructor with two parameters (creates matrix with size rows * columns)
    SparseMatrix(int rows, int columns);

    // copy constructor
    SparseMatrix(const SparseMatrix<T> &m);

    //destructor
    ~SparseMatrix();

    // getters
    int getRowCount() const;

    int getColumnCount() const;

    // method that returns element by row and column number
    T get(int row, int column) const;

    // method that returns significant elements of matrix
    std::vector<T> significantElements() const;

    SparseMatrix &set(T value, int row, int column);

    // operations with matrices
    SparseMatrix<T> multiply(const SparseMatrix<T> &m) const;

    SparseMatrix<T> addition(const SparseMatrix<T> &m) const;

    SparseMatrix<T> subtract(const SparseMatrix<T> &m) const;

    template<typename X>
    friend std::ostream &operator<<(std::ostream &os, const SparseMatrix<X> &matrix);
};

//constructor of square matrix n*n
template<typename T>
SparseMatrix<T>::SparseMatrix(int n) {
    this->construct(n, n);
}

//constructor of matrix with size m*n
template<typename T>
SparseMatrix<T>::SparseMatrix(int rows, int columns) {
    this->construct(rows, columns);
}

//copy constructor
template<typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T> &matrix) {
    this->deepCopy(matrix);
}

//method to make copying of elements "deep"
template<typename T>
void SparseMatrix<T>::deepCopy(const SparseMatrix<T> &matrix) {
    this->m = matrix.m;
    this->n = matrix.n;
    this->rows = new std::vector<int>(*(matrix.rows));

    if (matrix.values != nullptr) {
        this->columns = new std::vector<int>(*(matrix.columns));
        this->values = new std::vector<T>(*(matrix.values));
    }
}

//deep destruction and cleaning
template<typename T>
void SparseMatrix<T>::destruct() {
    if (this->values != nullptr) {
        delete this->values;
        delete this->columns;
    }
    delete this->rows;
}

//destructor
template<typename T>
SparseMatrix<T>::~SparseMatrix() {
    this->destruct();
}

//construction of matrix
template<typename T>
void SparseMatrix<T>::construct(int rows, int columns) {
    //in case of invalid arguments throws exception
    if (rows < 1 || columns < 1) {
        throw InvalidDimensionsException("Matrix dimensions cannot be zero or negative.");
    }

    this->m = rows;
    this->n = columns;

    this->values = nullptr;
    this->columns = nullptr;
    this->rows = new std::vector<int>(rows + 1, 1);
}

//method that returns amount of rows
template<typename T>
int SparseMatrix<T>::getRowCount() const {
    return this->m;
}

//method that returns amount of columns
template<typename T>
int SparseMatrix<T>::getColumnCount() const {
    return this->n;
}

//method that returns value by index of the row and column
template<typename T>
T SparseMatrix<T>::get(int row, int column) const {
    this->validateCoordinates(row, column);
    int currColumn;
    for (int position = (*(this->rows))[row - 1] - 1; position < (*(this->rows))[row] - 1; ++position) {
        currColumn = (*(this->columns))[position];

        if (currColumn == column) {
            return (*(this->values))[position];

        } else if (currColumn > column) {
            break;
        }
    }
    return T();
}

//method that sets value into the position
template<typename T>
SparseMatrix<T> &SparseMatrix<T>::set(T value, int row, int column) {
    this->validateCoordinates(row, column);

    int position = (*(this->rows))[row - 1] - 1;
    int currentColumn = 0;

    for (; position < (*(this->rows))[row] - 1; position++) {
        currentColumn = (*(this->columns))[position];

        if (currentColumn >= column) {
            break;
        }
    }

    if (currentColumn != column) {
        //we use here operator == instead of !=, because operator == is usually overloaded in user classes
        if (!(value == T())) {
            this->insert(position, row, column, value);
        }

    } else if (value == T()) {
        this->remove(position, row);

    } else {
        (*(this->values))[position] = value;
    }

    return *this;
}

//method that multiplies values of two matrix
template<typename T>
SparseMatrix<T> SparseMatrix<T>::multiply(const SparseMatrix<T> &m) const {
    //in case if multiplying isn't possible throws exceptions
    if (this->n != m.m) {
        throw InvalidDimensionsException(
                "Cannot multiply: Left matrix column count and right matrix row count don't match.");
    }
    SparseMatrix<T> result(this->m, m.n);
    T a;
    for (int i = 1; i <= this->m; i++) {
        for (int j = 1; j <= m.n; j++) {
            a = T();

            for (int k = 1; k <= this->n; k++) {
                a = a + this->get(i, k) * m.get(k, j);
            }

            result.set(a, i, j);
        }
    }
    return result;
}


template<typename T>
SparseMatrix<T> SparseMatrix<T>::addition(const SparseMatrix<T> &m) const {
    if (this->m != m.m || this->n != m.n) {
        throw InvalidDimensionsException("Cannot add: matrices dimensions don't match.");
    }
    SparseMatrix<T> result(this->m, this->n);
    for (int i = 1; i <= this->m; i++) {
        for (int j = 1; j <= this->n; j++) {
            result.set(this->get(i, j) + m.get(i, j), i, j);
        }
    }
    return result;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::subtract(const SparseMatrix<T> &m) const {
    //in case if subtraction isn't possible throws exceptions
    if (this->m != m.m || this->n != m.n) {
        throw InvalidDimensionsException("Cannot subtract: matrices dimensions don't match.");
    }
    SparseMatrix<T> result(this->m, this->n);
    for (int i = 1; i <= this->m; i++) {
        for (int j = 1; j <= this->n; j++) {
            result.set(this->get(i, j) - m.get(i, j), i, j);
        }
    }
    return result;
}

//method that validates coordinates
//in case if coordinates aren't correct - throws exception
template<typename T>
void SparseMatrix<T>::validateCoordinates(int row, int column) const {
    if (row < 1 || column < 1 || row > this->m || column > this->n) {
        throw InvalidCoordinatesException("Coordinates out of range.");
    }
}

//helping method to insert elements
template<typename T>
void SparseMatrix<T>::insert(int index, int row, int column, T value) {
    if (this->values == nullptr) {
        this->values = new std::vector<T>(1, value);
        this->columns = new std::vector<int>(1, column);

    } else {
        this->values->insert(this->values->begin() + index, value);
        this->columns->insert(this->columns->begin() + index, column);
    }

    for (int i = row; i <= this->m; i++) {
        (*(this->rows))[i] += 1;
    }
}

//method that removes element from the matrix
template<typename T>
void SparseMatrix<T>::remove(int index, int row) {
    this->values->erase(this->values->begin() + index);
    this->columns->erase(this->columns->begin() + index);

    for (int i = row; i <= this->m; i++) {
        (*(this->rows))[i] -= 1;
    }
}

//overloading operator "<<" to print content of matrix into console
template<typename T>
std::ostream &operator<<(std::ostream &os, const SparseMatrix<T> &matrix) {
    for (int i = 1; i <= matrix.m; i++) {
        for (int j = 1; j <= matrix.n; j++) {
            if (j != 1) {
                os << " ";
            }
            os << matrix.get(i, j);
        }

        if (i < matrix.m) {
            os << std::endl;
        }
    }
    return os;
}

// method that returns significant elements of matrix
template<typename T>
std::vector<T> SparseMatrix<T>::significantElements() const {
    std::vector<T> vectorOfSignificantElements;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (get(i, j) != 0) {
                vectorOfSignificantElements.push_back(get(i, j));
            }
        }
    }
    return vectorOfSignificantElements;
}



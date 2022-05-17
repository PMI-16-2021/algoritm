#pragma once
#include <iostream>

template<typename T>
struct MatrixNode {
    T value;
    size_t column;
    size_t row;
    MatrixNode* left = nullptr;
    MatrixNode* up = nullptr;
    MatrixNode(const T& _value, size_t _column, size_t _row, MatrixNode<T>* _left, MatrixNode<T>* _up);
    ~MatrixNode();
};

template<typename T>
MatrixNode<T>::MatrixNode(const T &_value, size_t _column, size_t _row, MatrixNode<T>* _left, MatrixNode<T>* _up) {
    value = _value;
    column = _column;
    row = _row;
    left = _left;
    up = _up;
}

template<typename T>
MatrixNode<T>::~MatrixNode() {
    left = nullptr;
    up = nullptr;
    value = T(0);
}

template<typename T>
class SparseMatrix {
private:
        MatrixNode<T>* columns_;
        MatrixNode<T>* rows_;
        size_t num_of_els;  // amount of elements
        size_t num_of_rows;  // size of rows_ arr
        size_t num_of_cols;  // size of columns_ arr

public:
        SparseMatrix();
        SparseMatrix(size_t _rows, size_t _cols);
        SparseMatrix(const SparseMatrix<T>& another);
        ~SparseMatrix();
        T Get(int _row, int _col) const;
        void Set(int _row, int _col, T _elem);
        std::pair<T, int>* SignificantElements(const T** matrix) const;  // forms sparse matrix
        SparseMatrix<T> Addition(SparseMatrix<T>& another) const;
        SparseMatrix<T> Subtraction(SparseMatrix<T>& another) const;
};
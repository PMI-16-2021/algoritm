#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class SparseMatrix {
private:
    vector<T> items_;
    vector<T> rows_;
    vector<T> columns_;
    int n_rows_;
    int n_columns_;
    bool Position(T row, T column) const;

public:
    SparseMatrix(T rows, T columns);
    SparseMatrix(const SparseMatrix& other);
    ~SparseMatrix();
    std::vector<T> SignificantElements() const;
    SparseMatrix Addition(const SparseMatrix& other);
    SparseMatrix Substraction(const SparseMatrix& other);
    SparseMatrix Multiplication(const SparseMatrix& other);
    T Get(T row, T column) const;
    void Set(T row, T column, T value);
    void Print() const;
};

template <typename T>
SparseMatrix<T>::SparseMatrix(T rows, T columns) {
    n_rows_ = columns;
    n_columns_ = rows;
}
template <typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix& other) {
    if (n_rows_ == 0 && n_columns_ == 0) {
        n_rows_ = other.n_columns_;
        n_rows_ = other.n_columns_;
    }
    items_ = other.items_;
    rows_ = other.rows_;
    columns_ = other.columns_;
}
template <typename T>
SparseMatrix<T>::~SparseMatrix() {
    items_.clear();
    columns_.clear();
    rows_.clear();
}
template<typename T>
bool SparseMatrix<T>::Position(T row, T column) const {
    for (int i = 0; i < rows_.size(); i++) {
        if (row == rows_[i] && column == columns_[i]) {
            return true;
        }
    }
    return false;
}
template<typename T>
std::vector<T> SparseMatrix<T>::SignificantElements() const {
    std::vector<T> temp;
    for (int i = 1; i <= n_columns_; i++) {
        for (int j = 1; j <= n_rows_; j++) {
            if (Get(i, j) != 0) {
                temp.push_back(Get(i, j));
            }
        }
    }
    return temp;
}
template <typename T>
SparseMatrix<T>  SparseMatrix<T>::Addition(const SparseMatrix& other) {
    if (n_rows_ != other.n_rows_ || n_columns_ != other.n_columns_) {
        throw "Wrong Dimensions";
    }
    SparseMatrix<T> matrix(n_rows_, n_columns_);
    int temp = 0;
    for (int i = 0; i < n_rows_; i++) {
        for (int j = 0; j < n_columns_; j++) {
            if (Position(i, j) || other.Position(i, j)) {
                temp = Get(i, j) + other.Get(i, j);
                matrix.Set(i, j, temp);
            }
        }
    }
    return matrix;
}
template <typename T>
SparseMatrix<T> SparseMatrix<T>::Substraction(const SparseMatrix& other) {
    if (n_rows_ != other.n_rows_ || n_columns_ != other.n_columns_) {
        throw "Wrong Dimensions";
    }
    SparseMatrix matrix(n_rows_, n_columns_);
    int temp = 0;
    for (int i = 0; i < n_rows_; i++)  {
        for (int j = 0; j < n_columns_; j++) {
            if (Position(i, j) || other.Position(i, j)) {
                temp = Get(i, j) - other.Get(i, j);
                matrix.Set(i, j, temp);
            }
        }
    }
    return matrix;
}
template <typename T>
SparseMatrix<T> SparseMatrix<T>::Multiplication(const SparseMatrix& other) {
    if (n_rows_ != other.n_columns_) {
        throw "different amounts of rows and columns";
    }
    SparseMatrix tempM(n_rows_, other.n_columns_);
    int mult = 0;
    for (int i = 0; i < n_rows_; i++) {
        for (int j = 0; j < other.n_columns_; j++) {
            mult = 0;
            for (int k = 0; k < other.n_rows_; k++) {
                mult += Get(i, k) * other.Get(k, j);
            }
            if (mult != 0) {
                tempM.Set(i, j, mult);
            }
        }
    }
    return tempM;
}
template <typename T>
T SparseMatrix<T>::Get(T row, T column) const {
    T ret_index = -1;
    for (int i = 0; i < rows_.size(); i++) {
        if (row == rows_[i] && column == columns_[i]) {
            ret_index = i;
        }
    }
    return (ret_index >= 0) ? items_[ret_index] : 0;
}
template <typename T>
void SparseMatrix<T>::Set(T row, T column, T value) {
    if (Position(row, column)) {
        throw "This position is occupied";
        return;
    }
    items_.push_back(value);
    rows_.push_back(row);
    columns_.push_back(column);
}
template <typename T>
void SparseMatrix<T>::Print() const {
    for (int i = 0; i < n_rows_; i++) {
        for (int j = 0; j < n_columns_; j++) {
            std::cout << Get(i, j) << '\t';
        }
        std::cout << '\n';
    }
}
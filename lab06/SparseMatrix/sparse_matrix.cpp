#include "sparse_matrix.h"

SparseMatrix::SparseMatrix(size_t rows, size_t columns) {
    num_of_cols_ = columns;
    num_of_rows_ = rows;
}

SparseMatrix::SparseMatrix(const SparseMatrix& other) {
    if(num_of_rows_ == 0 && num_of_cols_ == 0) {
        num_of_cols_ = other.num_of_cols_;
        num_of_rows_ = other.num_of_rows_;
    }
    values_ = other.values_;
    rows_ = other.rows_;
    columns_ = other.columns_;
}

SparseMatrix::~SparseMatrix() {
    values_.clear();
    columns_.clear();
    rows_.clear();
}

int SparseMatrix::Get(int row, int col) const {
   // TODO check validity of coordinates
    int ret_index = -1;
    for(int i = 0; i < rows_.size(); i++){
        if(row == rows_[i] && col == columns_[i]){
            ret_index=i;
        }
    }
    return (ret_index>= 0) ? values_[ret_index] : 0;   // row and col are zero element coordinates return 0
}

void SparseMatrix::Set(int row, int col, int value) {
    if(IsAt(row, col)) {
        std::cout << "element at position " << row << " row, " << col << " column " << "already exists\n";
        return;
    }
    values_.push_back(value);
    rows_.push_back(row);
    columns_.push_back(col);
}

void SparseMatrix::SignificantElements(int** matrix) {
    for(int i = 0; i < num_of_rows_; i++) {
        for(int j = 0; j < num_of_cols_; j++) {
            if(matrix[i][j] != 0) {
                values_.push_back(matrix[i][j]);
                rows_.push_back(i);
                columns_.push_back(j);
            }
        }
    }
}

SparseMatrix SparseMatrix::Addition(const SparseMatrix& other) {
    if(num_of_rows_ != other.num_of_rows_ || num_of_cols_ != other.num_of_cols_) {
        throw "Dimensions of matrices don't match";
    }
    SparseMatrix ret_mat(num_of_rows_,num_of_cols_);
    int sum = 0;
    for(int i = 0; i < num_of_rows_; i++) {
        for (int j = 0; j < num_of_cols_; j++) {
            if(IsAt(i,j) || other.IsAt(i,j)) {  // val + val || val + 0
                sum = Get(i,j) + other.Get(i,j);
                ret_mat.Set(i,j,sum);
            }
        }
    }
    return ret_mat;
}

SparseMatrix SparseMatrix::Substraction(const SparseMatrix& other) {
    if(num_of_rows_ != other.num_of_rows_ || num_of_cols_ != other.num_of_cols_) {
        throw "Dimensions of matrices don't match";
    }
    SparseMatrix ret_mat(num_of_rows_,num_of_cols_);
    int diff = 0;
    for(int i = 0; i < num_of_rows_; i++) {
        for (int j = 0; j < num_of_cols_; j++) {
            if(IsAt(i,j) || other.IsAt(i,j)) {  // val + val || val + 0
                diff = Get(i,j) - other.Get(i,j);
                ret_mat.Set(i,j,diff);
            }
        }
    }
    return ret_mat;
}

SparseMatrix SparseMatrix::Multiplication(const SparseMatrix& other) {
    if(num_of_rows_ != other.num_of_cols_) {
        throw "amount of rows in A != amount of columns in B";
    }
    SparseMatrix ret_mat(num_of_rows_, other.num_of_cols_);
    int mult = 0;
    for(int i = 0; i < num_of_rows_; i++) {
        for(int j = 0; j < other.num_of_cols_; j++) {
            mult = 0;
            for(int k = 0; k < other.num_of_rows_; k++) {
                mult += Get(i,k) * other.Get(k,j);
            }
            if(mult != 0) {
                ret_mat.Set(i,j, mult);
            }
        }

    }
    return ret_mat;
}

void SparseMatrix::Print() const {
    for(int i = 0; i < num_of_rows_; i++) {
        for(int j = 0; j < num_of_cols_; j++) {
            std::cout << Get(i,j) << '\t';
        }
        std::cout << '\n';
    }
}

bool SparseMatrix::IsAt(int row, int col) const {  // checks if at (row,col) is not zero
    for(int i = 0; i < rows_.size(); i++){
        if(row == rows_[i] && col == columns_[i]){
            return true;
        }
    }
    return false;
}

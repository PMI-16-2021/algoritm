#include <iostream>
#include <vector>

class SparseMatrix
{
private:
    std::vector<int> values_;
    std::vector<int> rows_;
    std::vector<int> columns_;
    size_t num_of_rows_;
    size_t num_of_cols_;
    bool IsAt(int row, int col) const;
public:
    SparseMatrix(size_t rows, size_t columns);
    SparseMatrix(const SparseMatrix& other);
    ~SparseMatrix();
    int Get(int row, int col) const; 
    void Set(int row, int col, int value);
    void SignificantElements(int** matrix);
    SparseMatrix Add(const SparseMatrix& other);
    SparseMatrix Sub(const SparseMatrix& other);
    SparseMatrix Mult(const SparseMatrix& other);
    void Print() const; 
};
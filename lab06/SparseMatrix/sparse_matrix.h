#include <iostream>
#include <vector>
using std::vector;

class SparseMatrix {
private:
    vector<int> values_;
    vector<int> rows_;
    vector<int> columns_;
    size_t num_of_rows_;
    size_t num_of_cols_;
    bool IsAt(int row, int col) const; // checks wether at pos is any element
public:
    SparseMatrix(size_t rows, size_t columns);
    SparseMatrix(const SparseMatrix& other);
    ~SparseMatrix();
    int Get(int row, int col) const;   // done
    void Set(int row, int col, int value);  // done
    void SignificantElements(int** matrix); // done
    SparseMatrix Addition(const SparseMatrix& other);
    SparseMatrix Substraction(const SparseMatrix& other);
    SparseMatrix Multiplication(const SparseMatrix& other);
    void Print() const; // done
};
#include <iostream>
#include <vector>
#include "SparseMatrix.h"

int main() {
  /*  SparseMatrix<double> matrix(5);
    matrix.set(3.0, 1, 2);
    matrix.set(5.0, 2, 5);
    matrix.set(9.0, 4, 1);

    std::cout << matrix;*/

    SparseMatrix<int> matrix3(3, 3);
    SparseMatrix<int> matrix1(3, 3);
    matrix1.set(10, 2, 2);
    matrix1.set(5, 2, 1);
    matrix1.set(10, 1, 2);
    matrix3.set(8, 2, 2);
    matrix3.set(5, 2, 1);
    matrix3.set(11, 1, 2);
    SparseMatrix<int> matrix2 = matrix3.add(matrix1);
    std::cout << matrix2;

    return 0;
}

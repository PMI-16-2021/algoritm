#include <iostream>
#include <vector>
#include "SparseMatrix.h"

int main() {
    SparseMatrix<double> matrix1(5);
    matrix1.set(3.0, 1, 2);
    matrix1.set(5.0, 2, 5);
    matrix1.set(9.0, 4, 1);
    matrix1.set(12.0, 5, 5);

    SparseMatrix<double> matrix2(5);
    matrix2.set(3.0, 1, 2);
    matrix2.set(5.0, 2, 5);
    matrix2.set(-9.0, 4, 1);
    matrix2.set(12.0, 3, 5);
    matrix2.set(-5.0, 5, 3);
    matrix2.set(18.9, 1, 5);

    std::vector<double> significantElementsVector = matrix1.significantElements();

    SparseMatrix<double> multiplicationOfMatrices = matrix1.multiply(matrix2);
    SparseMatrix<double> additionOfMatrices = matrix1.addition(matrix2);
    SparseMatrix<double> subtractionOfMatrices = matrix1.subtract(matrix2);

    std::cout <<  "\nMATRIX 1\n" << matrix1 << "\nMATRIX 2\n" << matrix2;




    return 0;
}

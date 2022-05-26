#include <iostream>
#include <vector>
#include "SparseMatrix.h"

int main() {
	SparseMatrix<int> matrix(3, 3);
	matrix.set(2, 2, 5);
	matrix.set(2, 1, 10);
	matrix.set(1, 2, 7);
	matrix.set(1, 1, 8);
	matrix.print_matrix();
}
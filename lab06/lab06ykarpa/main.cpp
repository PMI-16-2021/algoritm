#include "sparseMatrix.h"
#include <iostream>
using namespace std;

int main() {
    int rows_num = 10;
    int cols_num = 10;
    int** matrix = createMatrix(rows_num, cols_num);
    struct RowList* start = NULL;

    createRowList(&start, rows_num, cols_num, matrix);
    addValueNode(5, 7, 7, &start);

    ValueList* k = new ValueList();
    k = findValueNode(7, 6, &start);

    cout << k->value_ << "\n";
    printMatrix(start);
    cout << "\n";

    deleteValueNode(7, 7, &start);
    printMatrix(start);

    system("pause");
    return 0;
}
#pragma once
#include <iostream>

struct RowList {
    int row_number_;
    struct RowList* link_down_;
    struct ValueList* link_right_;
};

struct ValueList {
    int column_index_;
    int value_;
    struct ValueList* next_;
};

void addValueNode(int data, int col, int row_num, RowList** matrix);
ValueList* findValueNode(int row, int col, RowList** start);
int deleteValueNode(int col_num, int row_num, RowList** start);
void createRowList(struct RowList** start, int rows_num, int cols_num, int** sparse_Matrix);
int** createMatrix(int rows_num, int cols_num);
void printMatrix(struct RowList* start);
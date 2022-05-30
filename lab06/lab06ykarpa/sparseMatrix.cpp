#include "sparseMatrix.h"
using namespace std;

void addValueNode(int data, int col, int row_num, RowList** matrix) {
    struct ValueList* new_node, * h;
    struct RowList* help;
    new_node = new ValueList();
    new_node->column_index_ = col;
    new_node->value_ = data;
    new_node->next_ = NULL;
    help = *matrix;
    h = new ValueList();
    while (help->link_down_ != nullptr && help->row_number_ != row_num) {
        help = help->link_down_;
    }
    if (help->link_right_ != NULL && new_node->column_index_ > help->link_right_->column_index_) {
        h = help->link_right_;
        while (h->next_ != nullptr && h->next_->column_index_ < col) {
            h = h->next_;
        }
        new_node->next_ = h->next_;
        h->next_ = new_node;
    }
    else {
        new_node->next_ = help->link_right_;
        help->link_right_ = new_node;
    }
}

ValueList* findValueNode(int row, int col, RowList** start) {
    struct ValueList* to_return;
    to_return = new ValueList();
    struct  RowList* help_row;
    help_row = new RowList();
    help_row = *start;
    while (help_row->row_number_ != row) {
        help_row = help_row->link_down_;
    }
    if (help_row->link_right_ != NULL) {
        to_return = help_row->link_right_;
    }
    while (to_return->next_ != NULL && to_return->column_index_ < col) {
        to_return = to_return->next_;
    }
    return to_return;
}

int deleteValueNode(int col_num, int row_num, RowList** start) {
    struct RowList* help_row = new RowList();
    struct ValueList* h, * to_delete;
    help_row = *start;
    while (help_row->row_number_ != row_num) {
        help_row = help_row->link_down_;
    }
    if (help_row->link_right_ != NULL) {
        bool was_ = false;
        h = help_row->link_right_;
        while (h->next_ != nullptr) {
            if (h->column_index_ > col_num && !was_) {
                return -1;
            }
            else if (h->column_index_ == col_num) {
                was_ = true;
            }
            h = h->next_;
        }
        to_delete = findValueNode(row_num, col_num, start);
        while (h->next_ != nullptr && h->next_->column_index_ < to_delete->column_index_) {
            h = h->next_;
        }
        h->next_ = to_delete->next_;
        return 1;
    }
    else {
        return -1;
    }
}

void createRowList(struct RowList** start, int rows_num, int cols_num, int** sparse_Matrix) {
    for (int i = 0; i < rows_num; i++) {
        struct RowList* row_1, * row_2;
        row_1 = new RowList();
        row_1->row_number_ = i + 1;
        row_1->link_down_ = NULL;
        row_1->link_right_ = NULL;
        if (i == 0) {
            *start = row_1;
        }
        else {
            row_2 = *start;
            while (row_2->link_down_ != NULL) {
                row_2 = row_2->link_down_;
            }
            row_2->link_down_ = row_1;
        }
        for (size_t j = 0; j < cols_num; j++) {
            if (sparse_Matrix[i][j] != 0) {
                addValueNode(sparse_Matrix[i][j], j, i, &row_1);
            }
        }
    }
}

int** createMatrix(int rows_num, int cols_num) {
    int** sparse_matrix = new int* [rows_num];
    for (size_t i = 0; i < rows_num; i++) {
        sparse_matrix[i] = new int[cols_num];
        for (size_t j = 0; j < cols_num; j++) {
            if (i == j) {
                sparse_matrix[i][j] = 2 * (i + 1);
            }
            else {
                sparse_matrix[i][j] = 0;
            }
        }
    }
    return sparse_matrix;
}

void printMatrix(struct RowList* start) {
    struct RowList* row_node;
    struct ValueList* value_node;
    row_node = start;
    while (row_node != NULL) {
        if (row_node->link_right_ != NULL) {
            cout << "row = " << row_node->row_number_ << "\n";
            value_node = row_node->link_right_;
            while (value_node != NULL) {
                cout << "column = " << value_node->column_index_ << " value = " << value_node->value_ << "\n";
                value_node = value_node->next_;
            }
        }
        row_node = row_node->link_down_;
    }
}
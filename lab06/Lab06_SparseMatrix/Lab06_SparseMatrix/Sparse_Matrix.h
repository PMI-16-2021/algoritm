#include <iostream>
#include <vector>
using namespace std;
class SparseMatrix
{
private:
    vector<int> rows;
    vector<int> columns;  
    vector<int> values;
    size_t rows_number;
    size_t cols_number;
    bool Is_At(int row, int col) const
    {  
        for (size_t i = 0; i < rows.size(); i++)
        {
            if (col == columns[i] && row == rows[i])
                return true;
        }
        return false;
    }
public:
    ~SparseMatrix()
    {
        values.clear();
        columns.clear();
        rows.clear();
    }
    SparseMatrix(const SparseMatrix& other) 
    {
        if (rows_number == 0 && cols_number == 0)
        {
            cols_number = other.cols_number;
            rows_number = other.rows_number;
        }
        values = other.values;
        rows = other.rows;
        columns = other.columns;
    }
    SparseMatrix(size_t rows, size_t columns)
    {
        cols_number = columns;
        rows_number = rows;
    }
    SparseMatrix(){}
    void SignificantElements(int** matrix)
    {
        for (int i = 0; i < rows_number; i++)
        {
            for (int j = 0; j < cols_number; j++)
            {
                if (matrix[i][j] != 0) 
                {
                    values.push_back(matrix[i][j]);
                    rows.push_back(i);
                    columns.push_back(j);
                }
            }
        }
    }
    void Set_Value(int row, int col, int value)
    {
        if (Is_At(row, col))
        {
            cout << "Element at position: " << row << " row and " << col << " column " << "already exists" << endl;
            return;
        }
        values.push_back(value);
        rows.push_back(row);
        columns.push_back(col);
    }
    int Get_Value(int row, int col) const 
    {
        if (row > rows.size() || col < 0 || col > columns.size() || row < 0) 
        {
            throw "Bad index";
        }
        int index = -1;
        for (int i = 0; i < rows.size(); i++) 
            if (col == columns[i] &&  row == rows[i])     
                index = i;
        if (index >= 0)
            return values[index];
        else
            return 0;
    }
    void Print() const 
    {
        for (int i = 0; i < rows_number; i++)
        {
            for (int j = 0; j < cols_number; j++)
            {
                cout << Get_Value(i, j) << '\t';
            }
            cout << endl;
        }
        cout << endl;
    }
    SparseMatrix operator+(const SparseMatrix& SM) const //Addition(const SparseMatrix& SM)
    {
        if (rows_number != SM.rows_number || cols_number != SM.cols_number)
        {
            throw "Dimensions of matrices don't match";
        }
        SparseMatrix matr(rows_number, cols_number);
        int sum = 0;
        for (int i = 0; i < rows_number; i++)
        {
            for (int j = 0; j < cols_number; j++)
            {
                if (Is_At(i, j) || SM.Is_At(i, j))
                {  
                    sum = Get_Value(i, j) + SM.Get_Value(i, j);
                    matr.Set_Value(i, j, sum);
                }
            }
        }
        return matr;
    } 
    SparseMatrix operator*(const SparseMatrix& SM) const //Multiplication(const SparseMatrix& SM)
    {
        if (SM.cols_number != rows_number)
        {
            throw "amount of rows in A != amount of columns in B";
        }
        SparseMatrix matr(rows_number, SM.cols_number);
        int mult = 0;
        for (int i = 0; i < rows_number; i++)
        {
            for (int j = 0; j < SM.cols_number; j++)
            {
                mult = 0;
                for (int k = 0; k < SM.rows_number; k++)
                    mult += Get_Value(i, k) * SM.Get_Value(k, j);
                if (mult != 0) 
                    matr.Set_Value(i, j, mult);
            }
        }
        return matr;
    }
    SparseMatrix operator-(const SparseMatrix& SM) const //Substraction(const SparseMatrix& SM)
    {
        if (cols_number != SM.cols_number || rows_number != SM.rows_number)
        {
            throw "Dimensions are different";
        }
        SparseMatrix matr(rows_number, cols_number);
        int diff = 0;
        for (int i = 0; i < rows_number; i++)
        {
            for (int j = 0; j < cols_number; j++)
            {
                if (Is_At(i, j) || SM.Is_At(i, j))
                {  
                    diff = Get_Value(i, j) - SM.Get_Value(i, j);
                    matr.Set_Value(i, j, diff);
                }
            }
        }
        return matr;
    }
};
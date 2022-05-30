#include <iostream>
#include <vector>
using std::vector;
#pragma once

//class DimensionException
//{
//private:
//    int n_row;
//    int m_col;
//public:
//    DimensionException(int row, int col) { n_row=row; m_col=col;}
//    void print() const { std::cout << "ERROR!\n Dimensions [ " << n_row << ", " << m_col << "]  of matrices don't match ";}
//
//};

template <typename T>
class SparseMatrix {
private:
    vector<T> items;
    vector<T> rows;// vector(array) of rows
    vector<T> columns;// vector(array) of columns
    int n;//count of rows
    int m;//count pof cols
    bool position(T row, T col) const;// helping method

public:
    SparseMatrix(T rows, T columns); // constructor with two parameters
    SparseMatrix(const SparseMatrix& SM);    // copy constructor
    ~SparseMatrix(); //destructor
    T getM(T row, T col) const;// method that returns element by row and column number
    void setM(T row, T col, T value); // add element
    std::vector<T> significantElements() const;// method that returns significant elements of matrix
    SparseMatrix add(const SparseMatrix& other); // add two matrix
    SparseMatrix substraction(const SparseMatrix& other);//sustract two matrix
    SparseMatrix multiplication(const SparseMatrix& other);// * two matrix
    void printM() const;
};

template <typename T>
SparseMatrix<T>::SparseMatrix(T rows, T columns)
{
    n = columns;
    m = rows;
}
template <typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix& SM)
{
    if(n == 0 && m == 0)
    {
        n = SM.m;
        n = SM.m;
    }
    items= SM.items;
    rows = SM.rows;
    columns = SM.columns;
}

template <typename T>
SparseMatrix<T>::~SparseMatrix()
{
    items.clear();
    columns.clear();
    rows.clear();
}

template <typename T>
T SparseMatrix<T>::getM(T row, T col) const
{
    T ret_index = -1;
    for(int i = 0; i < rows.size(); i++)
    {
        if(row == rows[i] && col == columns[i])
        {
            ret_index=i;
        }
    }
    return (ret_index>= 0) ? items[ret_index] : 0;
}
template <typename T>
void SparseMatrix<T>::setM(T row, T col, T value)
{
    if(position(row, col)) {
        std::cout << "element at position " << row << " row, " << col << " column " << "already exists\n";
        return;
    }
    items.push_back(value);
    rows.push_back(row);
    columns.push_back(col);
}
template<typename T>
bool SparseMatrix<T>::position(T row, T col) const
{
    for (int i = 0; i < rows.size(); i++)
    {
        if (row == rows[i] && col == columns[i])
        {
            return true;
        }
    }
    return false;
}
template<typename T>
std::vector<T> SparseMatrix<T>::significantElements() const
{
    std::vector<T> temp;//vectorOfSignificantElements
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (getM(i, j) != 0)
            {
                temp.push_back(getM(i, j));
            }
        }
    }
    return temp;
}
template <typename T>
SparseMatrix<T>  SparseMatrix<T>::add(const SparseMatrix& other)
{
    if(n != other.n || m != other.m)
    {
        throw "ERROR!\n Dimensions of matrix aren`t correct";
    }
    SparseMatrix<T> tempM(n,m);// return matrix
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(position(i,j) || other.position(i,j))
            {
                sum = getM(i,j) + other.getM(i,j);
                tempM.setM(i,j,sum);
            }
        }
    }
    return tempM;
}
template <typename T>
SparseMatrix<T> SparseMatrix<T>:: substraction(const SparseMatrix& other)
{
    if(n != other.n || m != other.m)
    {
        throw "ERROR!\n Dimensions of matrix aren`t correct";
    }
    SparseMatrix tempM( n,m);// return Matrix
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(position(i,j) || other.position(i,j))
            {
                temp = getM(i,j) - other.getM(i,j);
                tempM.setM(i,j,temp);
            }
        }
    }
    return tempM;
}
template <typename T>
SparseMatrix<T> SparseMatrix<T>:: multiplication(const SparseMatrix& other)
{
    if(n != other.m)
    {
        throw "amount of rows in A aren`t similar amount of columns in B";
    }
    SparseMatrix tempM(n, other.m);// return matrix
    int mult = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < other.m; j++)
        {
            mult = 0;
            for(int k = 0; k < other.n; k++)
            {
                mult += getM(i,k) * other.getM(k,j);
            }
            if(mult != 0)
            {
                tempM.setM(i,j, mult);
            }
        }
    }
    return tempM;
}
template <typename T>
void SparseMatrix<T>::printM() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << getM(i, j) << '\t';
        }
        std::cout << '\n';
    }
}




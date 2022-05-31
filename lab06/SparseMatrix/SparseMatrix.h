#pragma once
#include <vector>
#include <iostream>

template<typename T>
class SparseMatrix
{
private:
    int m, n;
    std::vector<T>* values;
    std::vector<int>* rows, * cols;
    void create(int m, int n);
    void destruct(void);
    void copy(const SparseMatrix<T>& m);
    void validateCoordinates(int row, int col) const;
    void insert(int index, int row, int col, T val);
    void remove(int index, int row);

public:
    SparseMatrix(int n); 
    SparseMatrix(int rows, int columns); 
    SparseMatrix(const SparseMatrix<T>& m);
    SparseMatrix<T>& operator=(const SparseMatrix<T>& m);
    ~SparseMatrix(void);

    std::vector<T> significantElements() const;
    int getRowCount(void) const;
    int getColumnCount(void) const;
    T get(int row, int col) const;
    SparseMatrix& set(T val, int row, int col);

    std::vector<T> multiply(const std::vector<T>& x) const;
    std::vector<T> operator*(const std::vector<T>& x) const;
    SparseMatrix<T> multiply(const SparseMatrix<T>& m) const;
    SparseMatrix<T> operator*(const SparseMatrix<T>& m) const;
    SparseMatrix<T> add(const SparseMatrix<T>& m) const;
    SparseMatrix<T> operator+(const SparseMatrix<T>& m) const;
    SparseMatrix<T> subtract(const SparseMatrix<T>& m) const;
    SparseMatrix<T> operator-(const SparseMatrix<T>& m) const;

    template<typename X>
    friend bool operator==(const SparseMatrix<X>& a, const SparseMatrix<X>& b);

    template<typename X>
    friend bool operator!=(const SparseMatrix<X>& a, const SparseMatrix<X>& b);

    template<typename X>
    friend std::ostream& operator<<(std::ostream& os, const SparseMatrix<X>& matrix);

};

template<typename T>
SparseMatrix<T>::SparseMatrix(int n)
{
    this->create(n, n);
}


template<typename T>
SparseMatrix<T>::SparseMatrix(int rows, int columns) 
{
    this->create(rows, columns);
}


template<typename T>
SparseMatrix<T>::SparseMatrix(const SparseMatrix<T>& matrix)
{
    this->copy(matrix);
}


template<typename T>
SparseMatrix<T>& SparseMatrix<T>::operator=(const SparseMatrix<T>& matrix) 
{
    if (&matrix != this) 
    {
        this->destruct();
        this->copy(matrix);
    }

    return *this;
}


template<typename T>
void SparseMatrix<T>::copy(const SparseMatrix<T>& matrix)
{
    this->m = matrix.m;
    this->n = matrix.n;
    this->rows = new std::vector<int>(*(matrix.rows));

    if (matrix.values != nullptr)
    {
        this->cols = new std::vector<int>(*(matrix.cols));
        this->values = new std::vector<T>(*(matrix.values));
    }
}


template<typename T>
SparseMatrix<T>::~SparseMatrix(void)
{
    this->destruct();
}


template<typename T>
void SparseMatrix<T>::create(int rows, int columns)
{
    if (rows < 1 || columns < 1)
    {
        throw std::exception("Matrix dimensions cannot be zero or negative.");
    }

    this->m = rows;
    this->n = columns;

    this->values = nullptr;
    this->cols = nullptr;
    this->rows = new std::vector<int>(rows + 1, 1);
}


template<typename T>
void SparseMatrix<T>::destruct(void) 
{
    if (this->values != nullptr)
    {
        delete this->values;
        delete this->cols;
    }

    delete this->rows;
}

template<typename T>
int SparseMatrix<T>::getRowCount(void) const 
{
    return this->m;
}


template<typename T>
int SparseMatrix<T>::getColumnCount(void) const 
{
    return this->n;
}

template<typename T>
T SparseMatrix<T>::get(int row, int col) const
{
    this->validateCoordinates(row, col);
    int currCol;
    for (int pos = (*(this->rows))[row - 1] - 1; pos < (*(this->rows))[row] - 1; ++pos)
    {
        currCol = (*(this->cols))[pos];
        if (currCol == col)
        {
            return (*(this->values))[pos];
        }
        else if (currCol > col)
        {
            break;
        }
    }

    return T();
}

template<typename T>
SparseMatrix<T>& SparseMatrix<T>::set(T val, int row, int col)
{
    this->validateCoordinates(row, col);

    int pos = (*(this->rows))[row - 1] - 1;
    int currCol = 0;

    for (; pos < (*(this->rows))[row] - 1; pos++)
    {
        currCol = (*(this->cols))[pos];

        if (currCol >= col)
        {
            break;
        }
    }

    if (currCol != col)
    {
        if (!(val == T()))
        {
            this->insert(pos, row, col, val);
        }
    }
    else if (val == T())
    {
        this->remove(pos, row);
    }
    else 
    {
        (*(this->values))[pos] = val;
    }

    return *this;
}

template<typename T>
std::vector<T> SparseMatrix<T>::multiply(const std::vector<T>& x) const 
{
    if (this->n != (int)x.size()) 
    {
        throw std::exception("Cannot multiply: Matrix column count and vector size don't match.");
    }

    std::vector<T> result(this->m, T());
    if (this->values != nullptr)
    { 
        for (int i = 0; i < this->m; i++)
        {
            T sum = T();
            for (int j = (*(this->rows))[i]; j < (*(this->rows))[i + 1]; j++)
            {
                sum = sum + (*(this->values))[j - 1] * x[(*(this->cols))[j - 1] - 1];
            }
            result[i] = sum;
        }
    }

    return result;
}


template<typename T>
std::vector<T> SparseMatrix<T>::operator*(const std::vector<T>& x) const
{
    return this->multiply(x);
}


template<typename T>
SparseMatrix<T> SparseMatrix<T>::multiply(const SparseMatrix<T>& m) const
{
    if (this->n != m.m) 
    {
       throw std::exception("Cannot multiply: Left matrix column count and right matrix row count don't match.");
    }
    SparseMatrix<T> result(this->m, m.n);
    T a;
    for (int i = 1; i <= this->m; i++)
    {
        for (int j = 1; j <= m.n; j++) 
        {
            a = T();
            for (int k = 1; k <= this->n; k++) 
            {
                a = a + this->get(i, k) * m.get(k, j);
            }
            result.set(a, i, j);
        }
    }

    return result;
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::operator*(const SparseMatrix<T>& m) const
{
    return this->multiply(m);
}

template<typename T>
SparseMatrix<T> SparseMatrix<T>::add(const SparseMatrix<T>& m) const 
{
    if (this->m != m.m || this->n != m.n)
    {
       throw std::exception("Cannot add: matrices dimensions don't match.");
    }
    SparseMatrix<T> result(this->m, this->n);
    for (int i = 1; i <= this->m; i++)
    {
        for (int j = 1; j <= this->n; j++) 
        {
            result.set(this->get(i, j) + m.get(i, j), i, j);
        }
    }

    return result;
}


template<typename T>
SparseMatrix<T> SparseMatrix<T>::operator+(const SparseMatrix<T>& m) const
{
    return this->add(m);
}


template<typename T>
SparseMatrix<T> SparseMatrix<T>::subtract(const SparseMatrix<T>& m) const
{
    if (this->m != m.m || this->n != m.n) 
    {
       throw std::exception("Cannot subtract: matrices dimensions don't match.");
    }

    SparseMatrix<T> result(this->m, this->n);
    for (int i = 1; i <= this->m; i++) 
    {
        for (int j = 1; j <= this->n; j++) 
        {
            result.set(this->get(i, j) - m.get(i, j), i, j);
        }
    }

    return result;
}


template<typename T>
SparseMatrix<T> SparseMatrix<T>::operator-(const SparseMatrix<T>& m) const
{
    return this->subtract(m);
}



template<typename T>
void SparseMatrix<T>::validateCoordinates(int row, int col) const
{
    if (row < 1 || col < 1 || row > this->m || col > this->n)
    {
         throw std::exception("Bad coordinates");
    }
}


template<typename T>
void SparseMatrix<T>::insert(int index, int row, int col, T val)
{
    if (this->values == nullptr)
    {
        this->values = new std::vector<T>(1, val);
        this->cols = new std::vector<int>(1, col);

    }

    else
    {
        this->values->insert(this->values->begin() + index, val);
        this->cols->insert(this->cols->begin() + index, col);
    }

    for (int i = row; i <= this->m; i++) 
    {
        (*(this->rows))[i] += 1;
    }
}


template<typename T>
void SparseMatrix<T>::remove(int index, int row)
{
    this->values->erase(this->values->begin() + index);
    this->cols->erase(this->cols->begin() + index);
    for (int i = row; i <= this->m; i++)
    {
        (*(this->rows))[i] -= 1;
    }
}

template<typename T>
bool operator==(const SparseMatrix<T>& a, const SparseMatrix<T>& b)
{
    return ((a.values == nullptr && b.values == nullptr)
        || (a.values != nullptr && b.values != nullptr && *(a.values) == *(b.values)))
        && ((a.cols == nullptr && b.cols == nullptr)
            || (a.cols != nullptr && b.cols != nullptr && *(a.cols) == *(b.cols)))
        && *(a.rows) == *(b.rows);
}


template<typename T>
bool operator!=(const SparseMatrix<T>& a, const SparseMatrix<T>& b) 
{
    return !(a == b);
}


template<typename T>
std::ostream& operator<<(std::ostream& os, const SparseMatrix<T>& matrix)
{
    for (int i = 1; i <= matrix.m; i++)
    {
        for (int j = 1; j <= matrix.n; j++)
        {
            if (j != 1)
            {
                os << " ";
            }
            os << matrix.get(i, j);
        }

        if (i < matrix.m) 
        {
            os << std::endl;
        }
    }

    return os;
}

template<typename T>
std::vector<T> SparseMatrix<T>::significantElements() const 
{
    std::vector<T> myVector;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (get(i, j) != 0)
            {
                myVector.push_back(get(i, j));
            }
        }
    }

    return myVector;
}
#include "tests.h"
using namespace std;

void SetTest()
{
    SparseMatrix s_matrix(3, 3);
    s_matrix.Set(0, 2, 6);
    s_matrix.Set(1, 0, 3);
    s_matrix.Set(2, 1, 9);
    if (s_matrix.Get(0, 2) == 6)
    {
        cout << "Set test passed\n";
    }
    else
    {
        cout << "Set test failed\n";
    }
}

void AddTest()
{
    SparseMatrix A(3, 3);
    A.Set(0, 2, 6);
    A.Set(1, 0, 9);
    A.Set(2, 1, 4);
    SparseMatrix B(3, 3);
    B.Set(2, 0, 5);
    B.Set(0, 2, 8);
    B.Set(1, 1, 7);
    SparseMatrix m_matrix = A.Add(B);
    if (m_matrix.Get(1, 0) == 9 && m_matrix.Get(0, 2) == 14 && m_matrix.Get(2, 0) == 5)
    {
        cout << "Add test passed\n";
    }
    else
    {
        cout << "Add test failed\n";
    }
}

void SubTest()
{
    SparseMatrix A(3, 3);
    A.Set(0, 2, 6);
    A.Set(1, 0, 9);     
    A.Set(2, 1, 4);   
    SparseMatrix B(3, 3);
    B.Set(2, 0, 5);
    B.Set(0, 2, 8);
    B.Set(1, 1, 7);
    SparseMatrix m_matrix = A.Sub(B);
    if (m_matrix.Get(1, 0) == 9 && m_matrix.Get(1, 1) == -7 && m_matrix.Get(2, 1) == 4)
    {
        cout << "Sub test passed\n";
    }
    else
    {
        cout << "Sub test failed\n";
    }
}

void MultTest()
{
    SparseMatrix A(3, 4);
    A.Set(0, 2, 6);
    A.Set(1, 0, 9); 
    A.Set(2, 3, 4); 
    SparseMatrix B(4, 3);
    B.Set(3, 0, 5); 
    B.Set(0, 2, 8); 
    B.Set(2, 1, 7);                   
    SparseMatrix m_matrix(3, 3);
    m_matrix = A.Mult(B);
    if (m_matrix.Get(0, 1) == 42 && m_matrix.Get(1, 2) == 72 && m_matrix.Get(2, 0) == 20)
    {
        cout << "Mult test passed\n";
    }
    else
    {
        cout << "Mult test failed\n";
    }
}
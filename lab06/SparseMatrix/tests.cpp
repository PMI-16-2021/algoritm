#include "tests.h"

void SetTest() {
    SparseMatrix s_matrix(3,3);
    s_matrix.Set(0,2,6);
    s_matrix.Set(1,0,3);
    s_matrix.Set(2,1,9);
    if(s_matrix.Get(0,2) == 6) {
        std::cout << "SetTest passed\n";
    }
    else {
        std::cerr << "SetTest failed\n";
    }
}

void GetTest() {
    SparseMatrix s_matrix(3,3);
    s_matrix.Set(0,2,6);
    s_matrix.Set(1,0,3);
    s_matrix.Set(2,1,9);
    if(s_matrix.Get(1,1) == 0) {
        std::cout << "GetTest passed\n";
    }
    else {
        std::cerr << "GetTest failed\n";
    }
}

void SubstTest() {
    SparseMatrix A(3,3);
    A.Set(0,2,6);     // 0 0 6
    A.Set(1,0,9);     // 9 0 0
    A.Set(2,1, 4);    // 0 4 0
    SparseMatrix B(3,3);
    B.Set(2,0,5);  // 0 0 8
    B.Set(0,2,8);  // 0 7 0
    B.Set(1,1, 7); // 5 0 0
    SparseMatrix m_matrix = A.Substraction(B);
    if(m_matrix.Get(1,0) == 9 && m_matrix.Get(1,1) == -7 && m_matrix.Get(2,1) == 4) {
        std::cout << "Substraction Test passed\n";
    }
    else {
        std::cerr << "Substraction Test failed\n";
    }
}

void AddTest() {
    SparseMatrix A(3,3);
    A.Set(0,2,6);
    A.Set(1,0,9);
    A.Set(2,1, 4);
    SparseMatrix B(3,3);
    B.Set(2,0,5);
    B.Set(0,2,8);
    B.Set(1,1, 7);
    SparseMatrix m_matrix = A.Addition(B);
    if(m_matrix.Get(1,0) == 9 && m_matrix.Get(0,2) == 14 && m_matrix.Get(2,0) == 5) {
        std::cout << "Addition Test passed\n";
    }
    else {
        std::cerr << "Addition Test failed\n";
    }
}


void MultTest() {
    SparseMatrix A(3,4);
    A.Set(0,2,6);   // 0 0 6 0
    A.Set(1,0,9);   // 9 0 0 0
    A.Set(2,3, 4);  // 0 0 0 4
    SparseMatrix B(4,3);
    B.Set(3,0,5);  // 0   0   8
    B.Set(0,2,8);  // 0   0   0
    B.Set(2,1, 7); // 0   7   0
                                   // 5   0   0
    SparseMatrix m_matrix(3,3);
    m_matrix = A.Multiplication(B);
    if(m_matrix.Get(0,1) == 42 && m_matrix.Get(1,2) == 72 && m_matrix.Get(2,0) == 20) {
        std::cout << "Multiplication Test passed\n";
    }
    else {
        std::cerr << "Multiplication Test failed\n";
    }
}


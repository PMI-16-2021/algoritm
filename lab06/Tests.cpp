//
// Created by Sofia Demchuk on 30.05.2022.
//

#include "Tests.h"


bool TestOnSet()
{
    SparseMatrix<int> SM(3,3);
    SM.setM(0,1,5); // 0 5 0
    SM.setM(2,2,3); // 3 2 0
    SM.setM(1,0,3); // 7 0 3
    SM.setM(1,1,2);
    SM.setM(2,0,7);
    assert(SM.getM(0,1)==5);
    return true;
}
bool TestOnAdd()
{
    SparseMatrix<int> SM(2,2);
    SM.setM(0,0,5);// 5 0
    SM.setM(1,0,3);// 3 2
    SM.setM(1,1,2);
    SparseMatrix<int>SM2(2,2);
    SM2.setM(0,0,4);// 4 0
    SM2.setM(1,0,2);// 2 1
    SM2.setM(1,1,1);
    SparseMatrix<int>SM3 = SM.add(SM2);
    assert(SM3.getM(0,0)==9);
    assert(SM3.getM(1,0)==5);
    return true;


}
bool TestOnSub()
{
    SparseMatrix<double> SM(2,2);
    SM.setM(0,0,5); // 5 0
    SM.setM(1,0,3); // 3 2
    SM.setM(1,1,2);
    SparseMatrix<double>SM2(2,2);
    SM2.setM(0,0,4);// 4 0
    SM2.setM(1,0,2);// 2 1
    SM2.setM(1,1,1);
    SparseMatrix<double>SM3 = SM.substraction(SM2);
    assert(SM3.getM(0,0)==(4/3));
    return true;
}
bool TestOnMult()
{
    SparseMatrix<int> SM(2,2);
    SM.setM(0,0,5);// 5 0
    SM.setM(1,0,3);// 3 2
    SM.setM(1,1,2);
    SparseMatrix<int>SM2(2,2);
    SM2.setM(0,0,4);// 4 0
    SM2.setM(1,0,2);// 2 1
    SM2.setM(1,1,1);
    SparseMatrix<int>SM3 = SM.multiplication(SM2);
    assert(SM3.getM(0,0)==20);
    assert(SM3.getM(1,1)==2);
    return true;
}

void Test1()
{
    assert(TestOnSet()==true);
    cout<< "Test on method set() is PASSED\n ";
}
void Test2()
{
    assert(TestOnAdd()==true);
    cout<< "Test on method add() is PASSED\n ";
}
void Test3()
{
    assert(TestOnSub()==true);
    cout<< "Test on method substraction() is PASSED\n ";
}
void Test4()
{
    assert(TestOnMult()==true);
    cout<< "Test on method multiplication() is PASSED\n ";
}
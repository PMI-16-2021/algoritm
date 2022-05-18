#include "pch.h"
#include "CppUnitTest.h"
#include "..\\SparseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SparseMatrixTest
{
    TEST_CLASS(SparseMatrixTest)
    {
    public:

        TEST_METHOD(TestOperator)
        {
            SparseMatrix<int> matrix(2, 2);
            matrix.set(8, 1, 2);
            matrix.set(4, 1, 1);
            SparseMatrix<int> matrix1(2, 2);
            matrix1.set(5, 1, 2);
            matrix1.set(5, 1, 1);
            matrix = matrix1;
            Assert::AreEqual(matrix.get(1, 1), 5);
            Assert::AreEqual(matrix.get(1, 2), 5);
          
        }

        TEST_METHOD(TestSetElement)
        {
            SparseMatrix<double> matrix(3, 3);
            matrix.set(10.5,2,2);
            Assert::AreEqual(matrix.get(2,2), 10.5);
        }

        TEST_METHOD(TestGetElement)
        {
            SparseMatrix<double> matrix(3, 3);
            matrix.set(10.5, 2, 2);
            matrix.set(5.5, 2, 1);
            matrix.set(10.8, 1, 2);
            Assert::AreEqual(matrix.get(2, 1), 5.5);
        }

        TEST_METHOD(TestMultiply)
        {
            SparseMatrix<int> matrix3(3, 3);
            SparseMatrix<int> matrix1(3, 3);
            matrix1.set(10, 2, 2);
            matrix1.set(5, 2, 1);
            matrix1.set(10, 1, 2);
            matrix3.set(8, 2, 2);
            matrix3.set(5, 2, 1);
            matrix3.set(11, 1, 2);
            SparseMatrix<int> matrix2 = matrix3.multiply(matrix1);
            Assert::AreEqual(matrix2.get(1, 2), 110);
        }

        TEST_METHOD(TestAdd)
        {
            SparseMatrix<int> matrix3(3, 3);
            SparseMatrix<int> matrix1(3, 3);
            matrix1.set(10, 2, 2);
            matrix1.set(5, 2, 1);
            matrix1.set(10, 1, 2);
            matrix3.set(8, 2, 2);
            matrix3.set(5, 2, 1);
            matrix3.set(11, 1, 2);
            SparseMatrix<int> matrix2 = matrix3.add(matrix1);
            Assert::AreEqual(matrix2.get(1, 2), 21);
            Assert::AreEqual(matrix2.get(2, 1), 10);
            Assert::AreEqual(matrix2.get(2, 2), 18);
        }

        TEST_METHOD(TestSub)
        {
            SparseMatrix<int> matrix3(3, 3);
            SparseMatrix<int> matrix1(3, 3);
            matrix1.set(10, 2, 2);
            matrix1.set(5, 2, 1);
            matrix1.set(10, 1, 2);
            matrix3.set(8, 2, 2);
            matrix3.set(5, 2, 1);
            matrix3.set(11, 1, 2);
            SparseMatrix<int> matrix2 = matrix3.subtract(matrix1);
            Assert::AreEqual(matrix2.get(1, 2), 1);
            Assert::AreEqual(matrix2.get(2, 1), 0);
            Assert::AreEqual(matrix2.get(2, 2), -2);
        }
    };
}
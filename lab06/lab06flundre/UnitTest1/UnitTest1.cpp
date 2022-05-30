#include "pch.h"
#include "CppUnitTest.h"
#include "..\\SparseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		
        TEST_METHOD(TestSetElement)
        {
            SparseMatrix<int> matrix(3, 3);
            matrix.set(2, 2, 10);
            Assert::AreEqual(matrix.get(2, 2), 10);
        }

        TEST_METHOD(TestGetElement)
        {
            SparseMatrix<int> matrix(3, 3);
            matrix.set(2, 2, 10);
            Assert::AreEqual(matrix.get(2, 2), 10);
        }

        TEST_METHOD(TestMultiplication)
        {
            SparseMatrix<int> matrix3(3, 3);
            SparseMatrix<int> matrix1(3, 3);
            matrix1.set(2, 2, 10);
            matrix1.set(1, 2, 5);
            matrix1.set(2, 1, 10);
            matrix3.set(2, 2, 8);
            matrix3.set(1, 2, 5);
            matrix3.set(2, 1, 11);
            SparseMatrix<int> matrix2 = matrix3.multiplication(matrix1);
            Assert::AreEqual(matrix2.get(1, 2), 50);
        }

        TEST_METHOD(TestAddition)
        {
            SparseMatrix<int> matrix3(3, 3);
            SparseMatrix<int> matrix1(3, 3);
            matrix1.set(2, 2, 10);
            matrix1.set(1, 2, 5);
            matrix1.set(2, 1, 10);
            matrix3.set(2, 2, 8);
            matrix3.set(1, 2, 5);
            matrix3.set(2, 1, 11);
            SparseMatrix<int> matrix2 = matrix3.addition(matrix1);
            Assert::AreEqual(matrix2.get(1, 2), 10);
            Assert::AreEqual(matrix2.get(2, 1), 21);
            Assert::AreEqual(matrix2.get(2, 2), 18);
        }

        TEST_METHOD(TestSubtraction)
        {
            SparseMatrix<int> matrix3(3, 3);
            SparseMatrix<int> matrix1(3, 3);
            matrix1.set(2, 2, 10);
            matrix1.set(1, 2, 5);
            matrix1.set(2, 1, 10);
            matrix3.set(2, 2, 8);
            matrix3.set(1, 2, 5);
            matrix3.set(2, 1, 11);
            SparseMatrix<int> matrix2 = matrix3.subtraction(matrix1);
            Assert::AreEqual(matrix2.get(1, 2), 0);
            Assert::AreEqual(matrix2.get(2, 1), 1);
            Assert::AreEqual(matrix2.get(2, 2), -2);
        }
		
	};
}

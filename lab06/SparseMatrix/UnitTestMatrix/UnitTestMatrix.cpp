#include "pch.h"
#include "CppUnitTest.h"
#include "../SparseMatrix/SparseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix
{
	TEST_CLASS(UnitTestMatrix)
	{
	public:
		
		TEST_METHOD(TestSet) {
			SparseMatrix<int> matrix(3, 3);
			matrix.set(2, 2, 4);
			Assert::AreEqual(matrix.get(2, 2), 4);
		}
		TEST_METHOD(TestAddition) {
			SparseMatrix<double> matrix1(2, 2);
			matrix1.set(1, 1, 3.2);
			matrix1.set(1, 2, 2.5);
			matrix1.set(2, 1, 4.3);
			matrix1.set(2, 2, 7.1);

			SparseMatrix<double> matrix2(2, 2);
			matrix2.set(1, 1, 3.8);
			matrix2.set(1, 2, 1.5);
			matrix2.set(2, 1, -0.3);
			matrix2.set(2, 2, 4.9);
			matrix1.addition(matrix2);
			Assert::AreEqual(matrix1.get(1, 1), 7.0);
			Assert::AreEqual(matrix1.get(1, 2), 4.0);
			Assert::AreEqual(matrix1.get(2, 1), 4.0);
			Assert::AreEqual(matrix1.get(2, 2), 12.0);
		}
		TEST_METHOD(TestMultiplication) {
			SparseMatrix<int> matrix1(2, 2);
			matrix1.set(1, 1, 4);
			matrix1.set(1, 2, 2);
			matrix1.set(2, 1, 9);
			matrix1.set(2, 2, 0);

			SparseMatrix<int> matrix2(2, 2);
			matrix2.set(1, 1, 3);
			matrix2.set(1, 2, 1);
			matrix2.set(2, 1, -3);
			matrix2.set(2, 2, 4);
			matrix1.multiplication(matrix2);
			Assert::AreEqual(matrix1.get(1, 1), 6);
			Assert::AreEqual(matrix1.get(1, 2), 12);
			Assert::AreEqual(matrix1.get(2, 1), 27);
			Assert::AreEqual(matrix1.get(2, 2), 9);
		}
		TEST_METHOD(TestSubstraction) {
			SparseMatrix<int> matrix1(2, 2);
			matrix1.set(1, 1, 4);
			matrix1.set(1, 2, 2);
			matrix1.set(2, 1, 9);
			matrix1.set(2, 2, 0);

			SparseMatrix<int> matrix2(2, 2);
			matrix2.set(1, 1, 3);
			matrix2.set(1, 2, 1);
			matrix2.set(2, 1, -3);
			matrix2.set(2, 2, 4);
			matrix1.subtraction(matrix2);
			Assert::AreEqual(matrix1.get(1, 1), 1);
			Assert::AreEqual(matrix1.get(1, 2), 1);
			Assert::AreEqual(matrix1.get(2, 1), 12);
			Assert::AreEqual(matrix1.get(2, 2), -4);
		}
	};
}

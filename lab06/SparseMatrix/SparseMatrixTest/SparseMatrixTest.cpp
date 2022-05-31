#include "pch.h"
#include "CppUnitTest.h"
#include"..\sparse_matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SparseMatrixTest
{
	TEST_CLASS(SparseMatrixTest)
	{
	public:
		
		TEST_METHOD(Set_GetTest) {
			SparseMatrix<int> M(3, 3);
			M.Set(0, 0, 1);
			Assert::AreEqual(M.Get(0, 0), 1);
		}
		TEST_METHOD(TestAddition) {
			SparseMatrix<int> M1(3, 3);
			M1.Set(0, 0, 4);
			M1.Set(1, 1, 3);
			M1.Set(2, 2, 2);
			M1.Set(0, 2, 1);
			SparseMatrix<int> M2(3, 3);
			M2.Set(0, 0, 4);
			M2.Set(1, 1, 3);
			M2.Set(2, 2, 2);
			M2.Set(0, 2, 1);
			SparseMatrix<int> M = M1.Addition(M2);
			Assert::AreEqual(M.Get(0, 0), 8);
			Assert::AreEqual(M.Get(1, 0), 6);
			Assert::AreEqual(M.Get(2, 2), 4);
			Assert::AreEqual(M.Get(0, 2), 2);
		}
		TEST_METHOD(TestMultiplication) {
			SparseMatrix<int> M1(2, 2);
			M1.Set(0, 0, 4);
			M1.Set(0, 1, 3);
			M1.Set(1, 0, 2);
			M1.Set(1, 1, 1);
			SparseMatrix<int> M2(2, 2);
			M2.Set(0, 0, 1);
			M2.Set(0, 1, 2);
			M2.Set(1, 0, 3);
			M2.Set(1, 1, 4);
			SparseMatrix<int> M = M1.Multiplication(M2);
			Assert::AreEqual(M.Get(0, 0), 8);
			Assert::AreEqual(M.Get(0, 1), 5);
			Assert::AreEqual(M.Get(1, 0), 20);
			Assert::AreEqual(M.Get(1, 1), 13);
		}
		TEST_METHOD(TestSubstraction) {
			SparseMatrix<int> M1(3, 3);
			M1.Set(0, 0, 4);
			M1.Set(1, 1, 3);
			M1.Set(2, 2, 2);
			M1.Set(0, 2, 1);
			SparseMatrix<int> M2(3, 3);
			M2.Set(0, 0, 1);
			M2.Set(1, 1, 2);
			M2.Set(2, 2, 3);
			M2.Set(0, 2, 4);
			SparseMatrix<int> M = M1.Substraction(M2);
			Assert::AreEqual(M.Get(0, 0), 3);
			Assert::AreEqual(M.Get(1, 0), 1);
			Assert::AreEqual(M.Get(2, 2), -2);
			Assert::AreEqual(M.Get(0, 2), -3);
		}
	};
}

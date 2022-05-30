#include "pch.h"
#include "CppUnitTest.h"
#include "..//SparseMatrix/SparseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix
{
	TEST_CLASS(UnitTestMatrix)
	{
	public:
		
		TEST_METHOD(TestMethodGet)
		{
			SparseMatrix<int> A(2, 2);
			Assert::AreEqual(0, A.get(0, 1));
			A.set(0, 1, 5);
			A.set(1, 0, 9);
			Assert::AreEqual(9, A.get(1, 0));
		}
		TEST_METHOD(TestMethodSet)
		{
			SparseMatrix<int> B(2, 2);
			Assert::AreEqual(0, B.size());
			B.set(0, 1, 5);
			B.set(1, 0, 9);
			Assert::AreEqual(2, B.size());
			Assert::AreEqual(5, B.get(0, 1));
			Assert::AreEqual(9, B.get(1, 0));
		}
		TEST_METHOD(TestMethodAddition)
		{
			SparseMatrix<int> D(2, 2);
			D.set(0, 1, 5);
			D.set(1, 1, 7);
			SparseMatrix<int> C(2, 2);
			C.set(0, 1, 2);
			C.set(1, 0, 9);
			SparseMatrix<int> AD(2, 2);
			AD = D.addition(C);
			Assert::AreEqual(0, AD.get(0, 0));
			Assert::AreEqual(7, AD.get(0, 1));
			Assert::AreEqual(9, AD.get(1, 0));
			Assert::AreEqual(7, AD.get(1, 1));
		}
		TEST_METHOD(TestMethodSubtraction)
		{
			SparseMatrix<int> P(2, 2);
			P.set(0, 1, 5);
			P.set(1, 1, 7);
			SparseMatrix<int> M(2, 2);
			M.set(0, 1, 2);
			M.set(1, 0, 9);
			SparseMatrix<int> SB(2, 2);
			SB = P.subtraction(M);
			Assert::AreEqual(0, SB.get(0, 0));
			Assert::AreEqual(3, SB.get(0, 1));
			Assert::AreEqual(-9, SB.get(1, 0));
			Assert::AreEqual(7, SB.get(1, 1));
		}
		TEST_METHOD(TestMethodMultiplication)
		{
			SparseMatrix<int> L(2, 2);
			L.set(1, 1, 7);
			SparseMatrix<int> K(2, 2);
			K.set(0, 1, 2);
			K.set(1, 0, 9);
			SparseMatrix<int> ML(2, 2);
			ML = L.multiplication(K);
			Assert::AreEqual(0, ML.get(0, 0));
			Assert::AreEqual(0, ML.get(0, 1));
			Assert::AreEqual(63, ML.get(1, 0));
			Assert::AreEqual(0, ML.get(1, 1));
		}
		TEST_METHOD(TestMethodSize)
		{
			SparseMatrix<int> Q(2, 2);
			Assert::AreEqual(0, Q.size());
			Q.set(1, 0, 8);
			Q.set(1, 1, 9);
			Assert::AreEqual(2, Q.size());
		}
	};
}

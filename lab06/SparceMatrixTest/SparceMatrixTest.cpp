#include "pch.h"
#include "CppUnitTest.h"
#include "../SparceMatrix/SparceMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SparceMatrixTest
{
	TEST_CLASS(SparceMatrixTest)
	{
	public:
		
		TEST_METHOD(set_Test)
		{
			SparceMatrix<int> matr(5, 5);
			Assert::AreEqual(matr.filled(), (size_t)0);
			matr.set(3, 3, 10);
			Assert::AreEqual(matr[3][3], 10);
			Assert::AreEqual(matr.filled(), (size_t)1);
			matr.set(2, 3, 5);
			Assert::AreEqual(matr[2][3], 5);
			Assert::AreEqual(matr.filled(), (size_t)2);
			matr.set(3, 3, 6);
			Assert::AreEqual(matr[3][3], 6);
			Assert::AreEqual(matr.filled(), (size_t)2);
			matr.erase_elem(3, 3);
			Assert::AreEqual(matr.filled(), (size_t)1);
		}

		TEST_METHOD(get_Test)
		{
			SparceMatrix<int> matr(5, 5);
			Assert::AreEqual(matr.filled(), (size_t)0);
			matr.set(3, 2, 7);
			Assert::AreEqual(matr.filled(), (size_t)1);
			matr.set(3, 3, 10);
			Assert::AreEqual(matr.filled(), (size_t)2);
			Assert::AreEqual(matr.get(3, 3), 10);
			Assert::AreEqual(matr.get(3, 2), 7);
			Assert::AreEqual(matr.get(3, 3), matr[3][3]);
			Assert::AreEqual(matr.get(3, 2), matr[3][2]);
		}

		TEST_METHOD(erase_element_Test)
		{
			SparceMatrix<int> matr(5, 5);
			Assert::AreEqual(matr.filled(), (size_t)0);
			matr.set(3, 2, 7);
			Assert::AreEqual(matr.filled(), (size_t)1);
			Assert::AreEqual(matr.get(3, 2), 7);
			matr.erase_elem(3, 2);
			Assert::AreEqual(matr.get(3, 2), 0);
			Assert::AreEqual(matr.filled(), (size_t)0);
			matr.set(3, 3, 10);
			Assert::AreEqual(matr.filled(), (size_t)1);
			Assert::AreEqual(matr.get(3, 3), 10);
			matr.erase_elem(3, 3);
			Assert::AreEqual(matr.get(3, 3), 0);
			Assert::AreEqual(matr.filled(), (size_t)0);
		}

		TEST_METHOD(addition_Test)
		{
			SparceMatrix<int> matr(3, 3);
			matr.set(2, 2, 5);       // 8 0 0
			matr.set(2, 1, 10);      // 0 0 7
			matr.set(1, 2, 7);       // 0 10 5
			matr.set(0, 0, 8);  
			SparceMatrix<int> other(3, 3);
			other.set(0, 0, 5);      // 5 0 7 
			other.set(1, 2, 5);      // 0 0 5
			other.set(0, 2, 7);      // 1 3 4
			other.set(2, 0, 1);
			other.set(2, 1, 3);
			other.set(2, 2, 4);
			SparceMatrix<int> result = matr.addition(other);
			Assert::AreEqual(result.get(0, 0), 13);
			Assert::AreEqual(result.get(0, 1), 0);
			Assert::AreEqual(result.get(0, 2), 7);
			Assert::AreEqual(result.get(1, 0), 0);
			Assert::AreEqual(result.get(1, 1), 0);
			Assert::AreEqual(result.get(1, 2), 12);
			Assert::AreEqual(result.get(2, 0), 1);
			Assert::AreEqual(result.get(2, 1), 13);
			Assert::AreEqual(result.get(2, 2), 9);
		}

		TEST_METHOD(substraction_Test)
		{
			SparceMatrix<int> matr(3, 3);
			matr.set(2, 2, 5);       // 8 0 0
			matr.set(2, 1, 10);      // 0 0 7
			matr.set(1, 2, 7);       // 0 10 5
			matr.set(0, 0, 8);
			
			SparceMatrix<int> other(3, 3);
			other.set(0, 0, 5);      // 5 0 7 
			other.set(1, 2, 5);      // 0 0 5
			other.set(0, 2, 7);      // 1 3 4
			other.set(2, 0, 1);
			other.set(2, 1, 3);
			other.set(2, 2, 4);
			
			SparceMatrix<int> result = matr.substraction(other);
			Assert::AreEqual(result.get(0, 0), 3);
			Assert::AreEqual(result.get(0, 1), 0);
			Assert::AreEqual(result.get(0, 2), -7);
			Assert::AreEqual(result.get(1, 0), 0);
			Assert::AreEqual(result.get(1, 1), 0);
			Assert::AreEqual(result.get(1, 2), 2);
			Assert::AreEqual(result.get(2, 0), -1);
			Assert::AreEqual(result.get(2, 1), 7);
			Assert::AreEqual(result.get(2, 2), 1);
		}

		TEST_METHOD(multiplication_Test)
		{
			SparceMatrix<int> matr(3, 3);
			matr.set(2, 2, 5);       // 8 0 0
			matr.set(2, 1, 10);      // 0 0 7
			matr.set(1, 2, 7);       // 0 10 5
			matr.set(0, 0, 8);

			SparceMatrix<int> other(3, 3);
			other.set(0, 0, 5);      // 5 0 7 
			other.set(1, 2, 5);      // 0 0 5
			other.set(0, 2, 7);      // 1 3 4
			other.set(2, 0, 1);
			other.set(2, 1, 3);
			other.set(2, 2, 4);

			SparceMatrix<int> result = matr.multiplication(other);
			Assert::AreEqual(result.get(0, 0), 40);
			Assert::AreEqual(result.get(0, 1), 0);
			Assert::AreEqual(result.get(0, 2), 56);
			Assert::AreEqual(result.get(1, 0), 7);    // 40 0 56 
			Assert::AreEqual(result.get(1, 1), 21);   // 7 21 28
			Assert::AreEqual(result.get(1, 2), 28);   // 5 15 70
			Assert::AreEqual(result.get(2, 0), 5);
			Assert::AreEqual(result.get(2, 1), 15);
			Assert::AreEqual(result.get(2, 2), 70);
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project6/matrix.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest
{
	TEST_CLASS(MatrixUnitTest)
	{
	public:
		
		TEST_METHOD(SetTest)
		{
			SparseMatrix SM(4, 4);
			Assert::IsTrue(SM.isEmpty());
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(SM.get(i, j), 0);
				}
			}
			SM.set(1, 2, 3);
			SM.set(2, 3, 4);
			Assert::IsFalse(SM.isEmpty());
			Assert::AreEqual(SM.get(1, 2), 3);
			Assert::AreEqual(SM.get(2, 3), 4);
			SM.set(2, 3, 5);
			Assert::AreEqual(SM.get(2, 3), 5);
		}
		
		TEST_METHOD(GetTest)
		{
			SparseMatrix SM(3, 3);
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					Assert::AreEqual(SM.get(i, j), 0);
				}
			}
			Assert::IsTrue(SM.isEmpty());
			SM.set(0, 1, 2);
			SM.set(1, 2, 3);
			Assert::AreEqual(SM.get(0, 1), 2);
			Assert::AreEqual(SM.get(1, 2), 3);
			Assert::IsFalse(SM.isEmpty());
		}

		TEST_METHOD(IsEmptyTest) {
			SparseMatrix SM(4, 4);
			Assert::IsTrue(SM.isEmpty());
			SM.set(1, 1, 1);
			Assert::IsFalse(SM.isEmpty());
		}

		TEST_METHOD(SignificantElementsTest)
		{
			SparseMatrix SM(3, 3);
			SM.set(1, 0, 1);
			SM.set(1, 1, 2);
			SM.set(1, 2, 3);
			std::vector<int> v;
			SM.significantElements(v);
			std::vector<int> result = { 1, 2, 3};
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(v[i], result[i]);
			}
		}
		
		TEST_METHOD(AdditionTest)
		{
			SparseMatrix SM1(4, 4);
			SM1.set(1, 0, 1);
			SM1.set(0, 1, 2);
			SM1.set(1, 2, 3);
			SM1.set(2, 1, 4);
			SparseMatrix SM2(4, 4);
			SM2.set(0, 3, 4);
			SM2.set(1, 2, 3);
			SM2.set(2, 1, 2);
			SM2.set(3, 0, 1);

			SparseMatrix SM3;
			SM3 = SM1.addition(SM2);

			int result[4][4] = { {0, 2, 0, 4}, {1, 0, 6, 0}, {0, 6, 0, 0}, {1, 0, 0, 0} };
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(SM3.get(i, j), result[i][j]);
				}
			}
		}

		TEST_METHOD(SubtractionTest) {
			SparseMatrix SM1(4, 4);
			SM1.set(1, 0, 1);
			SM1.set(0, 1, 2);
			SM1.set(1, 2, 3);
			SM1.set(2, 1, 4);
			SparseMatrix SM2(4, 4);
			SM2.set(0, 3, 4);
			SM2.set(1, 2, 3);
			SM2.set(2, 1, 2);
			SM2.set(3, 0, 1);

			SparseMatrix SM3;
			SM3 = SM1.subtraction(SM2);
			int result[4][4] = { {0, 2, 0, -4}, {1, 0, 0, 0}, {0, 2, 0, 0}, {-1, 0, 0, 0} };
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(SM3.get(i, j), result[i][j]);
				}
			}
		}

		TEST_METHOD(MultiplicationTest) {
			SparseMatrix SM1(4, 4);
			SM1.set(1, 0, 1);
			SM1.set(0, 1, 2);
			SM1.set(1, 2, 3);
			SM1.set(2, 1, 4);
			SparseMatrix SM2(4, 4);
			SM2.set(0, 3, 4);
			SM2.set(1, 2, 3);
			SM2.set(2, 1, 2);
			SM2.set(3, 0, 1);

			SparseMatrix SM3;
			SM3 = SM1.multiplication(SM2);
			int result[4][4] = { {0, 0, 6, 0},{0, 6, 0, 4},{0, 0, 12, 0}, {0, 0, 0, 0} };
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(SM3.get(i, j), result[i][j]);
				}
			}
		}
	};
}

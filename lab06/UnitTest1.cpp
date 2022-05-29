#include "pch.h"
#include "CppUnitTest.h"
#include "../sparsematrix/sparseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(GetTest) {
			SparseMatrix S(3, 3);
			Assert::AreEqual(S.get(2, 2), 0);
			Assert::AreEqual(S.get(1, 2), 0);
			Assert::IsTrue(S.isEmpty());
			S.set(2, 2, 14);
			S.set(1, 2, 3);
			Assert::AreEqual(S.get(2, 2), 14);
			Assert::AreEqual(S.get(1, 2), 3);
			Assert::IsFalse(S.isEmpty());
		}
		TEST_METHOD(SetTest)
		{
			SparseMatrix S(3, 4);
			Assert::AreEqual(S.get(2, 2), 0);
			Assert::AreEqual(S.get(1, 3), 0);
			Assert::IsTrue(S.isEmpty());
			S.set(2, 3, 4);
			Assert::AreEqual(S.get(2, 3), 4);
			Assert::AreEqual(S.size(), 1);
			Assert::IsFalse(S.isEmpty());
			S.set(2, 3, 14);
			Assert::AreEqual(S.size(), 1);
			Assert::AreEqual(S.get(2, 3), 14);
			Assert::IsFalse(S.isEmpty());
			S.set(2, 2, 3);
			Assert::AreEqual(S.size(), 2);
			Assert::AreEqual(S.get(2, 2), 3);
			Assert::IsFalse(S.isEmpty());
		}
		TEST_METHOD(SignificantElementsTest) {
			SparseMatrix S(3, 3);
			S.set(1, 1, 4);
			S.set(1, 2, 3);
			S.set(2, 2, 14);
			std::vector<int> vec;
			S.significantElements(vec);
			std::vector<int> result = { 4, 3, 14 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(vec[i], result[i]);
			}
		}
		TEST_METHOD(AdditionTest) {
			SparseMatrix S1(2, 3);
			S1.set(0, 1, 5);
			S1.set(1, 1, 9);
			S1.set(1, 2, 14);
			SparseMatrix S2(2, 3);
			S2.set(0, 2, 1);
			S2.set(1, 0, 2);
			S2.set(1, 2, 7);
			SparseMatrix S3;
			S3 = S1.addition(S2);
			int result[2][3] = { {0, 5, 1}, {2, 9, 21} };
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					Assert::AreEqual(S3.get(i, j), result[i][j]);
				}
			}
		}
		TEST_METHOD(SubtractionTest) {
			SparseMatrix S1(2, 3);
			S1.set(0, 1, 5);
			S1.set(1, 1, 9);
			S1.set(1, 2, 14);
			SparseMatrix S2(2, 3);
			S2.set(0, 2, 1);
			S2.set(1, 0, 2);
			S2.set(1, 2, 7);
			SparseMatrix S3;
			S3 = S1.subtraction(S2);
			int result[2][3] = { {0, 5, -1}, {-2, 9, 7} };
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					Assert::AreEqual(S3.get(i, j), result[i][j]);
				}
			}
		}
		TEST_METHOD(MultiplicationTest) {
			SparseMatrix S1(2, 3);
			S1.set(0, 1, 5);
			S1.set(1, 1, 9);
			S1.set(1, 2, 14);
			SparseMatrix S2(3, 3);
			S2.set(0, 2, 1);
			S2.set(1, 0, 2);
			S2.set(1, 2, 7);
			S2.set(2, 1, 5);
			S2.set(2, 2, 3);
			SparseMatrix S3;
			S3 = S1.multiplication(S2);
			int result[2][3] = { {0, 0, 35}, {18, 70, 105}};
			for (int i = 0; i < 2; ++i) {
				for (int j = 0; j < 3; ++j) {
					Assert::AreEqual(S3.get(i, j), result[i][j]);
				}
			}
		}
		TEST_METHOD(SizeTest) {
			SparseMatrix S(3, 3);
			Assert::AreEqual(S.size(), 0);
			S.set(0, 2, 4);
			S.set(1, 2, 3);
			S.set(2, 0, 7);
			S.set(2, 2, 14);
			Assert::AreEqual(S.size(), 4);
		}
		TEST_METHOD(IsEmptyTest) {
			SparseMatrix S(3, 3);
			Assert::IsTrue(S.isEmpty());
			S.set(2, 2, 14);
			Assert::IsFalse(S.isEmpty());
		}
	};
}

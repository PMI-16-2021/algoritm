#include "pch.h"
#include "CppUnitTest.h"
#include "..//SparseMatrix/matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SparseMatrixTest {

	TEST_CLASS(SparseMatrixTest) {

	public:
		TEST_METHOD(SetTest) {
			SparseMatrix<int> S1(5, 5);
			Assert::AreEqual(S1.Get(3, 2), 0);
			S1.Set(3, 2, 5);
			Assert::AreEqual(S1.Get(3, 2), 5);
			Assert::AreEqual(S1.GetElementsCount(), 1);
			Assert::IsFalse(S1.IsEmpty());
			S1.Set(3, 2, 10);
			Assert::AreEqual(S1.GetElementsCount(), 1);
			Assert::AreEqual(S1.Get(3, 2), 10);
		}
		TEST_METHOD(GetTest) {
			SparseMatrix<int> S1(5, 5);
			Assert::AreEqual(S1.Get(3, 2), 0);
			S1.Set(3, 2, 5);
			Assert::AreEqual(S1.Get(3, 2), 5);
		}
		TEST_METHOD(EraceTest) {
			SparseMatrix<int> S1(5, 5);
			S1.Set(3, 2, 5);
			Assert::AreEqual(S1.Get(3, 2), 5);
			S1.Erace(3, 2);
			Assert::AreEqual(S1.Get(3, 2), 0);
			Assert::AreEqual(S1.GetElementsCount(), 0);
		}
		TEST_METHOD(IsEmptyTest) {
			SparseMatrix<int> S1(5, 5);
			Assert::IsTrue(S1.IsEmpty());
			S1.Set(3, 2, 5);
			Assert::IsFalse(S1.IsEmpty());
		}
		TEST_METHOD(GetElementsCountTest) {
			SparseMatrix<int> S1(5, 5);
			Assert::AreEqual(S1.GetElementsCount(), 0);
			S1.Set(3, 2, 5);
			S1.Set(2, 1, 10);
			S1.Set(0, 3, 1);
			Assert::AreEqual(S1.GetElementsCount(), 3);
		}
		TEST_METHOD(AdditionTest) {
			SparseMatrix<int> S1(3, 4);
			S1.Set(2, 3, 5);
			S1.Set(1, 2, 7);
			S1.Set(0, 1, 9);
			SparseMatrix<int> S2(3, 4);
			S2.Set(1, 0, 4);
			S2.Set(2, 1, 3);
			S2.Set(0, 3, 9);
			SparseMatrix<int> S3;
			S3 = S1.Addition(S2);
			int result[3][4] = { {0, 9, 0, 9}, {4, 0, 7, 0}, {0, 3, 0, 5} };
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(S3.Get(i, j), result[i][j]);
				}
			}
		}
		TEST_METHOD(SubtractionTest) {
			SparseMatrix<int> S1(3, 4);
			S1.Set(2, 3, 5);
			S1.Set(1, 2, 7);
			S1.Set(0, 1, 9);
			SparseMatrix<int> S2(3, 4);
			S2.Set(1, 0, 4);
			S2.Set(2, 1, 3);
			S2.Set(0, 3, 9);
			SparseMatrix<int> S3;
			S3 = S1.Subtraction(S2);
			int result[3][4] = { {0, 9, 0, -9}, {-4, 0, 7, 0}, {0, -3, 0, 5} };
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(S3.Get(i, j), result[i][j]);
				}
			}
		}
		TEST_METHOD(MultiplicationTest) {
			SparseMatrix<int> S1(4, 4);
			S1.Set(1, 3, 5);
			S1.Set(3, 2, 7);
			S1.Set(0, 1, 9);
			SparseMatrix<int> S2(4, 4);
			S2.Set(1, 2, 4);
			S2.Set(3, 3, 3);
			S2.Set(2, 2, 9);
			SparseMatrix<int> S3;
			S3 = S1.Multiplication(S2);
			int result[4][4] = { {0, 0, 36, 0}, {0, 0, 0, 15}, {0, 0, 0, 0}, {0, 0, 63, 0} };
			for (int i = 0; i < 4; ++i) {
				for (int j = 0; j < 4; ++j) {
					Assert::AreEqual(S3.Get(i, j), result[i][j]);
				}
			}
		}
		TEST_METHOD(SignificantTest) {
			SparseMatrix<int> S1(3, 4);
			S1.Set(2, 3, 5);
			S1.Set(1, 2, 7);
			S1.Set(0, 1, 9);
			std::vector<int> output;
			S1.SignificantElements(output);
			std::vector<int> result = { 9, 7, 5 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(output[i], result[i]);
			}
		}
	};
}

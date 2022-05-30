#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр6/sparseMatrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(UnitTest) {
	public:
		TEST_METHOD(addValueNodeTest) {
			int rows_num = 100;
			int cols_num = 100;
			int** matrix = createMatrix(rows_num, cols_num);
			struct RowList* start = NULL;
			createRowList(&start, rows_num, cols_num, matrix);
			addValueNode(5, 7, 7, &start);
			addValueNode(6, 8, 7, &start);
			auto k = findValueNode(7, 7, &start);
			auto m = findValueNode(8, 7, &start);
			Assert::AreEqual(k->value_, 5);
			Assert::AreNotEqual(m->value_, 5);
		}
		TEST_METHOD(createMatrixTest)	{
			int rows_num = 10;
			int cols_num = 10;
			int** matrix = createMatrix(rows_num, cols_num);
			Assert::AreEqual(matrix[5][5], 12);
			Assert::AreEqual(matrix[6][6], 14);
			Assert::AreEqual(matrix[6][7], 0);
			Assert::AreEqual(matrix[6][8], 0);
		}
		TEST_METHOD(findValueNodeTest) {
			int rows_num = 100;
			int cols_num = 100;
			int** matrix = createMatrix(rows_num, cols_num);
			struct RowList* start = NULL;
			createRowList(&start, rows_num, cols_num, matrix);
			ValueList* k = new ValueList();
			k = findValueNode(6, 6, &start);
			Assert::AreEqual(k->value_, 12);
		}
		TEST_METHOD(deleteValueNodeTest) {
			int rows_num = 100;
			int cols_num = 100;
			int** matrix = createMatrix(rows_num, cols_num);
			struct RowList* start = NULL;
			createRowList(&start, rows_num, cols_num, matrix);
			Assert::AreEqual(deleteValueNode(8, 7, &start), 1);
			Assert::AreNotEqual(deleteValueNode(7, 7, &start), -1);
		}
	};
}
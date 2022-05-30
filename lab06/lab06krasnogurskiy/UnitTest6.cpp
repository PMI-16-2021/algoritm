#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab06/matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest6
{
	TEST_CLASS(UnitTest6)
	{
	public:

		TEST_METHOD(TestCtor)
		{
			SparseMatrix m;
			Assert::IsTrue(m.get_row_size() == 100 && m.get_col_size() == 100);

			SparseMatrix m1(20);
			Assert::IsTrue(m1.get_row_size() == 20 && m1.get_col_size() == 100);

			SparseMatrix m2(20, 25);
			Assert::IsTrue(m2.get_row_size() == 20 && m2.get_col_size() == 25);
		}

		TEST_METHOD(TestSetGetValue)
		{
			SparseMatrix m(10, 10);

			m.set_value(0, 9, 1);
			m.set_value(3, 3, 2);
			m.set_value(9, 0, 3);

			Assert::AreEqual(1, m.get_value(0, 9));
			Assert::AreEqual(2, m.get_value(3, 3));
			Assert::AreEqual(3, m.get_value(9, 0));
			Assert::AreNotEqual(4, m.get_value(9, 0));
			Assert::AreNotEqual(0, m.get_value(0, 9));

			Assert::AreEqual(0, m.get_value(0, 0));
			Assert::AreEqual(0, m.get_value(8, 0));
			Assert::AreEqual(0, m.get_value(3, 2));
			Assert::AreEqual(0, m.get_value(4, 4));

			m.set_value(0, 9, 0);
			m.set_value(3, 3, 0);
			m.set_value(9, 0, 0);

			m.set_value(4, 4, 51);

			m.get_value(0, 9);
			m.get_value(3, 3);

			Assert::AreEqual(0, m.get_value(0, 9));
			Assert::AreEqual(0, m.get_value(3, 3));
			Assert::AreEqual(0, m.get_value(9, 0));

			Assert::AreNotEqual(0, m.get_value(4, 4));

			try
			{
				m.set_value(5, 10, 1);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(e.what(), "set_value(): out of range");
			}
			try
			{
				m.set_value(4, 12, 1);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(e.what(), "set_value(): out of range");
			}

			try
			{
				m.get_value(10, 2);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(e.what(), "get_value(): out of range");
			}
			try
			{
				m.get_value(15, 21);
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(e.what(), "get_value(): out of range");
			}

		}
		TEST_METHOD(TestOperatorPlus)
		{
			SparseMatrix m(10, 10);
			SparseMatrix m1(10, 10);

			m.set_value(3, 7, 10);
			m.set_value(8, 2, 10);

			m1.set_value(3, 7, 11);
			m1.set_value(9, 4, 11);

			m + m1;

			Assert::AreEqual(10, m.get_value(8, 2));
			Assert::AreEqual(21, m.get_value(3, 7));
			Assert::AreEqual(11, m.get_value(9, 4));

			Assert::AreEqual(11, m1.get_value(3, 7));
			Assert::AreEqual(11, m1.get_value(9, 4));

			SparseMatrix m2(12, 12);
			try
			{
				m + m2;
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(e.what(), "adding two matrixs of different sizes");
			}
		}

		TEST_METHOD(TestOperatorMultiplyByMatrix)
		{
			SparseMatrix m(3, 5);
			SparseMatrix m1(5, 6);

			m.set_value(2, 2, 5); //0	0	0	0	0
			m.set_value(2, 3, 5); //0	0  /5	0	0
			m.set_value(1, 2, 5); //0	0 //5 //5	0

			m1.set_value(2, 2, 5);//0	0	0	0	0	0
			m1.set_value(3, 2, 5);//0	0	0	0	0	0
			m1.set_value(2, 1, 5);//0  /5 //5	0	0	0
								  //0	0 //5	0	0	0
								  //0	0	0	0	0	0

			m* m1; //0		0	0	0	0	0
					//0	   /25 /25	0	0	0
					//0	  //25//50	0	0	0
			Assert::IsTrue(m.get_row_size() == 3 && m.get_col_size() == 6);

			Assert::AreEqual(25, m.get_value(1, 1));
			Assert::AreEqual(25, m.get_value(1, 2));
			Assert::AreEqual(25, m.get_value(2, 1));
			Assert::AreEqual(50, m.get_value(2, 2));

			SparseMatrix m2(12, 12);
			try
			{
				m* m2;
			}
			catch (const std::exception& e)
			{
				Assert::AreEqual(e.what(), "operator*(): leff matrix column-size is not equal right matrix row-size");
			}
		}

		TEST_METHOD(TestOperatorMultiplyByParameter)
		{
			SparseMatrix m1(5, 6);

			m1.set_value(2, 2, 5);//0	0	0	0	0	0
			m1.set_value(3, 2, 5);//0	0	0	0	0	0
			m1.set_value(2, 1, 5);//0  /5 //5	0	0	0
								  //0	0 //5	0	0	0
								  //0	0	0	0	0	0
			m1 * 2;
			Assert::AreEqual(10, m1.get_value(2, 1));
			Assert::AreEqual(10, m1.get_value(2, 2));
			Assert::AreEqual(10, m1.get_value(3, 2));
		}

		TEST_METHOD(TestAssignOperator)
		{
			SparseMatrix m1(5, 6);
			m1.set_value(2, 2, 5);//0	0	0	0	0	0
			m1.set_value(3, 2, 5);//0	0	0	0	0	0
			m1.set_value(2, 1, 5);//0  /5 //5	0	0	0
								  //0	0 //5	0	0	0
								  //0	0	0	0	0	0

			SparseMatrix m2(1, 1);
			m2 = m1;

			Assert::AreEqual((size_t)5, m2.get_row_size());
			Assert::AreEqual((size_t)6, m2.get_col_size());


			Assert::AreEqual(5, m2.get_value(2, 1));
			Assert::AreEqual(5, m2.get_value(2, 2));
			Assert::AreEqual(5, m2.get_value(3, 2));

			Assert::AreEqual(5, m1.get_value(2, 1));
			Assert::AreEqual(5, m1.get_value(2, 2));
			Assert::AreEqual(5, m1.get_value(3, 2));

			SparseMatrix m1_copy(1, 1);
			m1_copy = m1;

			m2 = m1_copy * 2;

			Assert::AreEqual(10, m2.get_value(2, 1));
			Assert::AreEqual(10, m2.get_value(2, 2));
			Assert::AreEqual(10, m2.get_value(3, 2));

			Assert::AreEqual(5, m1.get_value(2, 1));
			Assert::AreEqual(5, m1.get_value(2, 2));
			Assert::AreEqual(5, m1.get_value(3, 2));
		}
	};
}

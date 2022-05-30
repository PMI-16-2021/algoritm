#include "pch.h"
#include "CppUnitTest.h"
#include"../Lab06_SparseMatrix/Sparse_Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixTest
{
	TEST_CLASS(MatrixTest)
	{
	public:
		TEST_METHOD(Test___Get_Value___Set_Value)
		{
			SparseMatrix b(3, 3);
			b.Set_Value(1, 2, 1);
			b.Set_Value(1, 3, 1);
			b.Set_Value(2, 1, 9);
			Assert::AreEqual(b.Get_Value(1, 2), 1);
			Assert::AreEqual(b.Get_Value(1, 3), 1);
			Assert::AreEqual(b.Get_Value(2, 1), 9);
		}
		TEST_METHOD(Sub_Test)
		{
			SparseMatrix A(3, 3);
			A.Set_Value(0, 1, 5);     // 0 5 0
			A.Set_Value(1, 2, 9);     // 0 0 9
			A.Set_Value(2, 0, 4);    // 4 0 0
			SparseMatrix B(3, 3);
			B.Set_Value(0, 0, 5);  // 5 0 0
			B.Set_Value(1, 1, 8);  // 0 8 0
			B.Set_Value(2, 2, 7); // 0 0 7
			SparseMatrix R = A - B;
			Assert::IsTrue(R.Get_Value(0, 0) == -5);
			Assert::IsTrue(R.Get_Value(0, 1) == 5);
			Assert::IsTrue(R.Get_Value(1, 1) == -8);
			Assert::IsTrue(R.Get_Value(2, 0) == 4);
		}
		TEST_METHOD(Test_Add)
		{
			SparseMatrix A(3, 3);
			A.Set_Value(0, 1, 5);     // 0 5 0
			A.Set_Value(1, 2, 9);     // 0 0 9
			A.Set_Value(2, 0, 4);    // 4 0 0
			SparseMatrix B(3, 3);
			B.Set_Value(0, 0, 5);  // 5 0 0
			B.Set_Value(1, 1, 8);  // 0 8 0
			B.Set_Value(2, 2, 7); // 0 0 7
			SparseMatrix R = A + B;
			Assert::IsTrue(R.Get_Value(0, 0) == 5);
			Assert::IsTrue(R.Get_Value(0, 1) == 5);
			Assert::IsTrue(R.Get_Value(1, 1) == 8);
			Assert::IsTrue(R.Get_Value(2, 0) == 4);
		}
		TEST_METHOD(Test_Multiplication)
		{
			SparseMatrix A(3, 3);
			A.Set_Value(0, 1, 5);     // 0 5 0
			A.Set_Value(1, 2, 9);     // 0 0 9
			A.Set_Value(2, 0, 4);    // 4 0 0
			SparseMatrix B(3, 3);
			B.Set_Value(0, 0, 5);  // 5 0 0
			B.Set_Value(1, 1, 8);  // 0 8 0
			B.Set_Value(2, 2, 7); // 0 0 7
			SparseMatrix R = A * B;
			Assert::IsTrue(R.Get_Value(1, 2) == 63);
			Assert::IsTrue(R.Get_Value(0, 1) == 40);
			Assert::IsTrue(R.Get_Value(2, 0) == 20);
			Assert::IsTrue(R.Get_Value(0, 0) == 0);
		}
	};
}

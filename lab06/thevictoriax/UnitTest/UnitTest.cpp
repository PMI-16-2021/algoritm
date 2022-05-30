#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab06/matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Set)
		{
			
			Matrix M(3, 3);
			M.setVal(2, 2, 4);
			Assert::AreEqual(M.getVal(2, 2), 4.0);
			
		}
		TEST_METHOD(Add)
		{
			Matrix M(2, 2);
			M.setVal(1, 1, 4);
			M.setVal(1, 2, 1);
			M.setVal(2, 1, 2);
			M.setVal(2, 2, 6);
			Matrix M2(2, 2);
			M2.setVal(1, 1, 9);
			M2.setVal(1, 2, 5);
			M2.setVal(2, 1, 1);
			M2.setVal(2, 2, 7);
			M.add(M2);
			Assert::AreEqual(M.getVal(1, 1), 13.0);
			Assert::AreEqual(M.getVal(1, 2), 6.0);
			Assert::AreEqual(M.getVal(2, 1), 3.0);
			Assert::AreEqual(M.getVal(2, 2), 13.0);
		}
		TEST_METHOD(Multiply)
		{
			Matrix M(2, 2);
			
			M.setVal(1, 1, 4);
			M.setVal(1, 2, 2);
			M.setVal(2, 1, 9);
			M.setVal(2, 2, 0);

			Matrix M2(2, 2);
			M2.setVal(1, 1, 3);
			M2.setVal(1, 2, 1);
			M2.setVal(2, 1, -3);
			M2.setVal(2, 2, 4);
			M.multiply(M2);

			Assert::AreEqual(M.getVal(1, 1), 6.0);
			Assert::AreEqual(M.getVal(1, 2), 12.0);
			Assert::AreEqual(M.getVal(2, 1), 27.0);
			Assert::AreEqual(M.getVal(2, 2), 9.0);
		}
		TEST_METHOD(Substraction)
		{
			Matrix M(2, 2);
			M.setVal(1, 1, 4);
			M.setVal(1, 2, 2);
			M.setVal(2, 1, 9);
			M.setVal(2, 2, 0);

			Matrix M2(2, 2);
			M2.setVal(1, 1, 3);
			M2.setVal(1, 2, 1);
			M2.setVal(2, 1, -3);
			M2.setVal(2, 2, 4);
			M.subtraction(M2);
			Assert::AreEqual(M.getVal(1, 1), 1.0);
			Assert::AreEqual(M.getVal(1, 2), 1.0);
			Assert::AreEqual(M.getVal(2, 1), 12.0);
			Assert::AreEqual(M.getVal(2, 2), -4.0);
		}
	};
}

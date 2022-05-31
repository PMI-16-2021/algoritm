#include "pch.h"
#include "CppUnitTest.h"
#include "../розріджена матрриця/matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestmatrix
{
	TEST_CLASS(UnitTestmatrix)
	{
	public:
		
		TEST_METHOD(set_get)
		{
			SpaceMatrix<int> s(5, 5);
			Assert::AreEqual(s.get(3, 3), 0);
			s.set(2, 2, 9);
			Assert::AreEqual(s.get(2, 2), 9);
		}
		TEST_METHOD(significant)
		{
			SpaceMatrix<int> s(5, 5);
			s.set(1, 4, 2);
			s.set(3, 2, 6);
			s.set(4, 3, 2);
			std::vector<int> out;
			s.significantElements(out);
			std::vector<int> res = { 2,6,2 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(out[i], res[i]);
			}
		}
		TEST_METHOD(addition)
		{
			SpaceMatrix<int> s(5,5);
			s.set(1, 1, 2);
			s.set(1, 2, 6);
			s.set(2, 1, 2);
			SpaceMatrix<int> s1(5,5);
			s1.set(1, 1, 3);
			s1.set(1, 2, 7);
			s1.set(2, 1, 3);
			s1.set(4, 3, 8);
			s.addition(s1);
			Assert::AreEqual(s.get(1, 1), 5);
			Assert::AreEqual(s.get(1, 2), 13);
			Assert::AreEqual(s.get(2, 1), 5);
			Assert::AreEqual(s.get(4, 3), 8);
		}
		TEST_METHOD(substraction)
		{
			SpaceMatrix<int> s(5, 5);
			s.set(1, 1, 2);
			s.set(1, 2, 6);
			s.set(2, 1, 2);
			SpaceMatrix<int> s1(5, 5);
			s1.set(1, 1, 3);
			s1.set(1, 2, 7);
			s1.set(2, 1, 3);
			s1.set(4, 3, 8);
			s.subtraction(s1);
			Assert::AreEqual(s.get(1, 1), -1);
			Assert::AreEqual(s.get(1, 2), -1);
			Assert::AreEqual(s.get(2, 1), -1);
			Assert::AreEqual(s.get(4, 3), -8);
		}
		TEST_METHOD(multiplication)
		{
			SpaceMatrix<int> s(5, 5);
			s.set(1, 1, 2);
			s.set(1, 2, 6);
			s.set(2, 1, 2);
			SpaceMatrix<int> s1(5, 5);
			s1.set(1, 1, 3);
			s1.set(1, 2, 7);
			s1.set(2, 1, 3);
			s1.set(4, 3, 8);
			s.multiplication(s1);
			Assert::AreEqual(s.get(1, 1), 3);
			Assert::AreEqual(s.get(1, 2), 7);
			Assert::AreEqual(s.get(2, 1), 3);
			Assert::AreEqual(s.get(4, 3), 8);
		}
	};
}

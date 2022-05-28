#include "pch.h"
#include "CppUnitTest.h"
#include "..//MySet/MySet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSet
{
	TEST_CLASS(UnitTestSet)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			MySet<int> A;
			A.add(5);
			A.add(1);
			Assert::IsTrue(A.in(1));
			Assert::IsTrue(A.in(5));
		}
		TEST_METHOD(TestRemove)
		{
			MySet<int> B;
			B.add(23);
			B.add(67);
			Assert::AreEqual(2, B.len());
			B.remove(67);
			Assert::IsFalse(B.in(67));
		}
		TEST_METHOD(TestLength)
		{
			MySet<int> C;
			Assert::AreEqual(0, C.len());
			C.add(6);
			C.add(8);
			Assert::AreEqual(2, C.len());
		}
		TEST_METHOD(TestIn)
		{
			MySet<int> D;
			D.add(34);
			D.add(98);
			Assert::IsTrue(D.in(98));
			Assert::IsFalse(D.in(4));
		}
		TEST_METHOD(TestUnion)
		{
			MySet<int> A;
			A.add(5);
			A.add(1);
			A.add(2);
			MySet<int> B;
			B.add(10);
			B.add(5);
			MySet<int> U;
			U = A.Union(B);
			int res[4] = { 5, 1, 2, 10 };
			for (int i = 0; i < 4; ++i) {
				Assert::AreEqual(U[i], res[i]);
			}
		}
		TEST_METHOD(TestIntersection)
		{
			MySet<int> A;
			A.add(5);
			A.add(1);
			A.add(2);
			MySet<int> B;
			B.add(10);
			B.add(5);
			MySet<int> I;
			I = A.Intersection(B);
			int res[1] = { 5 };
			for (int i = 0; i < 1; ++i) {
				Assert::AreEqual(I[i], res[i]);
			}
		}
		TEST_METHOD(TestDifference)
		{
			MySet<int> A;
			A.add(5);
			A.add(1);
			A.add(2);
			MySet<int> B;
			B.add(10);
			B.add(5);
			MySet<int> D;
			D = A.Difference(B);
			int res[2] = { 1, 2};
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(D[i], res[i]);
			}
		}
		TEST_METHOD(TestSymmetric_Difference)
		{
			MySet<int> A;
			A.add(5);
			A.add(1);
			A.add(2);
			MySet<int> B;
			B.add(10);
			B.add(5);
			MySet<int> S;
			S = A.Symmetric_difference(B);
			int res[2] = { 1, 2 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(S[i], res[i]);
			}
		}
	};
}

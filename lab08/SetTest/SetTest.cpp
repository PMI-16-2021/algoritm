#include "pch.h"
#include "CppUnitTest.h"
#include "../Set/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetTest
{
	TEST_CLASS(SetTest)
	{
	public:
		
		TEST_METHOD(add_Test)
		{
			Set<int> A;
			Assert::AreEqual(0, (int)A.len());
			Assert::IsFalse(A.in(3));
			A.add(3);
			Assert::IsTrue(A.in(3));
			Assert::AreEqual(1, (int)A.len());
		}

		TEST_METHOD(remove_Test)
		{
			Set<int> A;
			Assert::AreEqual(0, (int)A.len());
			Assert::IsFalse(A.in(3));
			A.add(3);
			Assert::IsTrue(A.in(3));
			A.add(5);
			A.add(6);
			Assert::IsTrue(A.in(5));
			Assert::IsTrue(A.in(6));
			Assert::IsFalse(A.in(8));
			A.remove(5);
			A.remove(3);
			Assert::IsFalse(A.in(5));
			Assert::IsFalse(A.in(3));
			Assert::IsTrue(A.in(6));
			A.remove(6);
			Assert::IsFalse(A.in(6));
			A.remove(8);
			Assert::IsFalse(A.in(8));
		}

		TEST_METHOD(in_Test)
		{
			Set<int> A;
			Assert::IsFalse(A.in(5));
			A.add(5);
			Assert::IsTrue(A.in(5));
			A.remove(5);
			Assert::IsFalse(A.in(5));
			A.add(3); 
			A.add(4);
			Assert::IsTrue(A.in(4));
			Assert::IsTrue(A.in(3));
		}

		TEST_METHOD(len_Test)
		{
			Set<int> A;
			Assert::AreEqual(0, (int)A.len());
			A.add(3);
			Assert::AreEqual(1, (int)A.len());
			A.add(3);
			Assert::AreEqual(1, (int)A.len());
			A.add(4);
			Assert::AreEqual(2, (int)A.len());
			A.remove(3);
			Assert::AreEqual(1, (int)A.len());
			A.remove(3);
			Assert::AreEqual(1, (int)A.len());
			A.remove(4);
			Assert::AreEqual(0, (int)A.len());
			A.remove(4);
			Assert::AreEqual(0, (int)A.len());

		}

		TEST_METHOD(Uniion_Test)
		{
			Set<int> A, B, C;
			A.add(5);
			A.add(5);  //5, 7, 8
			A.add(7);
			A.add(8);

			B.add(5);
			B.add(4);  //5, 4, 7
			B.add(7);

			C = A.Union(B);
			Assert::IsTrue(C.in(5));
			Assert::IsTrue(C.in(7));
			Assert::IsTrue(C.in(8));
			Assert::IsTrue(C.in(4));
			Assert::IsFalse(C.in(2));

			Set<int> D, E, F;
			D.add(5); E.add(5); //D: 5, 7, 10
			D.add(7); E.add(7); //E: 5, 7, 10
			D.add(10); D.add(10);

			F = D.Union(E);
			Assert::IsTrue(F.in(5));
			Assert::IsTrue(F.in(10)); //F: 5, 7, 10
			Assert::IsTrue(F.in(7));
		}

		TEST_METHOD(intersecton_Test)
		{
			Set<int> A, B, C;
			A.add(5);
			A.add(5);  //5, 7, 8
			A.add(7);
			A.add(8);

			B.add(5);
			B.add(4);  //5, 4, 7
			B.add(7);

			C = A.insersection(B);  //5, 7
			Assert::IsTrue(C.in(5));
			Assert::IsTrue(C.in(7));
			Assert::IsFalse(C.in(8));
			Assert::IsFalse(C.in(4));
			Assert::IsFalse(C.in(10));
		}

		TEST_METHOD(difference_Test)
		{
			Set<int> A, B, C;
			A.add(5);
			A.add(7);
			A.add(8);  //5, 7, 8, 12
			A.add(12);

			B.add(12);
			B.add(2);
			B.add(0); //0, 2, 8, 12
			B.add(8);

			C = A.difference(B); //5, 7
			Assert::IsTrue(C.in(7));
			Assert::IsTrue(C.in(5));
			Assert::IsFalse(C.in(8));
			Assert::IsFalse(C.in(12));
			Assert::IsFalse(C.in(0));
			Assert::IsFalse(C.in(2));
		}

		TEST_METHOD(symmetric_difference_Test)
		{
			Set<int> A, B, C;
			A.add(5);
			A.add(7);
			A.add(8);  //5, 7, 8, 12
			A.add(12);

			B.add(12);
			B.add(2);
			B.add(0); //0, 2, 8, 12
			B.add(8);

			C = A.symmetric_difference(B); //0, 2, 5, 7, 
			Assert::IsTrue(C.in(7));
			Assert::IsTrue(C.in(5));
			Assert::IsTrue(C.in(0));
			Assert::IsTrue(C.in(2));
			Assert::IsFalse(C.in(8));
			Assert::IsFalse(C.in(12));
		}
	};
}

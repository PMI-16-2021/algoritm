#include "pch.h"
#include "CppUnitTest.h"
#include "..\\set\set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(InTest) {
			Set<int> S1;
			S1.add(4);
			Assert::IsFalse(S1.in(3));
			Assert::IsTrue(S1.in(4));
		}
		TEST_METHOD(AddTest) {
			Set<int> S1;
			Assert::IsFalse(S1.in(2));
			S1.add(4);
			Assert::IsTrue(S1.in(4));
			S1.add(4);
			Assert::AreEqual(S1.len(), 1);
			S1.add(3);
			Assert::AreEqual(S1.len(), 2);
		}
		TEST_METHOD(RemoveTest) {
			Set<int> S1;
			S1.add(4);
			S1.add(3);
			Assert::AreEqual(S1.len(), 2);
			S1.remove(4);
			Assert::IsFalse(S1.in(4));
			Assert::IsTrue(S1.in(3));
			Assert::AreEqual(S1.len(), 1);
		}
		TEST_METHOD(LenTest) {
			Set<int> S1;
			Assert::AreEqual(S1.len(), 0);
			S1.add(4);
			S1.add(3);
			Assert::AreEqual(S1.len(), 2);
			S1.add(7);
			S1.add(9);
			Assert::AreEqual(S1.len(), 4);
		}
		TEST_METHOD(UnionTest) {
			Set<int> S1;
			S1.add(4);
			S1.add(3);
			S1.add(9);
			Set<int> S2;
			S2.add(3);
			S2.add(8);
			S2.add(1);
			S2.add(4);
			Set<int> S3;
			S3 = S1.unionSet(S2);
			int result[5] = { 4, 3, 9, 8, 1 };
			for (int i = 0; i < 4; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
		TEST_METHOD(IntersectionTest) {
			Set<int> S1;
			S1.add(4);
			S1.add(3);
			S1.add(9);
			Set<int> S2;
			S2.add(3);
			S2.add(8);
			S2.add(1);
			S2.add(4);
			Set<int> S3;
			S3 = S1.intersectionSet(S2);
			int result[2] = { 4, 3 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
		TEST_METHOD(DifferenceTest) {
			Set<int> S1;
			S1.add(4);
			S1.add(3);
			S1.add(9);
			S1.add(2);
			Set<int> S2;
			S2.add(3);
			S2.add(8);
			S2.add(1);
			S2.add(4);
			Set<int> S3;
			S3 = S1.differenceSet(S2);
			int result[2] = { 9, 2 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
		TEST_METHOD(SymmetricDifferenceTest) {
			Set<int> S1;
			S1.add(4);
			S1.add(3);
			S1.add(9);
			Set<int> S2;
			S2.add(3);
			S2.add(8);
			S2.add(1);
			S2.add(4);
			Set<int> S3;
			S3 = S1.symmetricDifferenceSet(S2);
			int result[3] = { 9, 8, 1 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
	};
}
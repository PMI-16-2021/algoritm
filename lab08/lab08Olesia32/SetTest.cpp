#include "pch.h"
#include "CppUnitTest.h"
#include "..//MySet/my_set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetTest {
	TEST_CLASS(SetTest) {

	public:
		TEST_METHOD(AddTest) {
			MySet<int> S1;
			Assert::IsFalse(S1.In(2));
			S1.Add(2);
			Assert::IsTrue(S1.In(2));
			S1.Add(2);
			Assert::AreEqual(S1.Len(), 1);
		}
		TEST_METHOD(RemoveTest) {
			MySet<int> S1;
			S1.Add(3);
			S1.Add(2);
			S1.Remove(3);
			Assert::IsFalse(S1.In(3));
			Assert::AreEqual(1, S1.Len());
		}
		TEST_METHOD(LenTest) {
			MySet<int> S1;
			Assert::AreEqual(0, S1.Len());
			S1.Add(2);
			S1.Add(9);
			S1.Add(4);
			Assert::AreEqual(3, S1.Len());
		}
		TEST_METHOD(InTest) {
			MySet<int> S1;
			S1.Add(2);
			Assert::IsTrue(S1.In(2));
			Assert::IsFalse(S1.In(3));
		}
		TEST_METHOD(UnionTest) {
			MySet<int> S1;
			S1.Add(2);
			S1.Add(9);
			S1.Add(4);
			MySet<int> S2;
			S2.Add(3);
			S2.Add(5);
			S2.Add(2);
			MySet<int> S;
			S = S1.Union(S2);
			int result[5] = { 2, 9, 4, 3, 5 };
			for (int i = 0; i < 5; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
		TEST_METHOD(IntersectionTest) {
			MySet<int> S1;
			S1.Add(5);
			S1.Add(9);
			S1.Add(2);
			MySet<int> S2;
			S2.Add(3);
			S2.Add(5);
			S2.Add(2);
			MySet<int> S;
			S = S1.Intersection(S2);
			int result[2] = { 5, 2 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
		TEST_METHOD(DifferenceTest) {
			MySet<int> S1;
			S1.Add(5);
			S1.Add(9);
			S1.Add(2);
			S1.Add(10);
			S1.Add(1);
			MySet<int> S2;
			S2.Add(3);
			S2.Add(5);
			S2.Add(2);
			MySet<int> S;
			S = S1.Difference(S2);
			int result[3] = { 9, 10, 1 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
		TEST_METHOD(SymmetricDifferenceTest) {
			MySet<int> S1;
			S1.Add(5);
			S1.Add(9);
			S1.Add(2);
			S1.Add(10);
			S1.Add(1);
			MySet<int> S2;
			S2.Add(3);
			S2.Add(5);
			S2.Add(2);
			MySet<int> S;
			S = S1.SymmetricDifference(S2);
			int result[4] = { 9, 10, 1, 3 };
			for (int i = 0; i < 4; ++i) {
				Assert::AreEqual(S[i], result[i]);
			}
		}
	};
}

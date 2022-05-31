#include "pch.h"
#include "CppUnitTest.h"
#include"..\my_set.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetTest
{
	TEST_CLASS(SetTest)
	{
	public:
		TEST_METHOD(LenTest) {
			MySet<int> S;
			Assert::AreEqual(0, S.Len());
			S.Add(1);
			S.Add(2);
			Assert::AreEqual(2, S.Len());
		}
		TEST_METHOD(Add_InTest) {
			MySet<int> S;
			Assert::AreEqual(0, S.Len());
			S.Add(5);
			Assert::AreEqual(1, S.Len());
			Assert::IsTrue(S.In(5));
			S.Add(10);
			Assert::IsTrue(S.In(10));
			Assert::AreEqual(S.Len(), 2);
		}
		TEST_METHOD(RemoveTest) {
			MySet<int> S;
			S.Add(1);
			Assert::IsTrue(S.In(1));
			Assert::AreEqual(1, S.Len());
			S.Remove(1);
			Assert::IsFalse(S.In(1));
			Assert::AreEqual(0, S.Len());
		}
		TEST_METHOD(UnionTest) {
			MySet<int> S;
			S.Add(1);
			S.Add(5);
			MySet<int> other;
			other.Add(2);
			other.Add(5);
			MySet<int> Set;
			Set = S.Union(other);
			int result[3] = { 1, 5, 2 };
			for (int i = 0; i < 3; ++i) {
				Assert::AreEqual(Set[i], result[i]);
			}
		}
		TEST_METHOD(IntersectionTest) {
			MySet<int> S;
			S.Add(1);
			S.Add(3);
			MySet<int> other;
			other.Add(2);
			other.Add(4);
			other.Add(3);
			MySet<int> Set;
			Set = S.Intersection(other);
			int result = 3;
			Assert::AreEqual(Set[0], result);
			
		}
		TEST_METHOD(DifferenceTest) {
			MySet<int> S;
			S.Add(1);
			S.Add(3);
			S.Add(5);
			MySet<int> other;
			other.Add(1);
			other.Add(3);
			MySet<int> Set;
			Set = S.Difference(other);
			int result = 5;
			Assert::AreEqual(Set[0], result);
		}
		TEST_METHOD(SymmetricDifferenceTest) {
			MySet<int> S;
			S.Add(1);
			S.Add(3);
			S.Add(5);
			S.Add(7);
			S.Add(9);
			MySet<int> other;
			other.Add(2);
			other.Add(3);
			other.Add(4);
			MySet<int> Set;
			Set = S.SymmetricDifference(other);
			int result[6] = { 1, 5, 7, 9, 2, 4 };
			for (int i = 0; i < 6; ++i) {
				Assert::AreEqual(Set[i], result[i]);
			}
		}
	};
}

#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetSTLTests
{
	TEST_CLASS(SetSTLTests)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			int set1[] = { 5,8,2,1 };
			for (size_t i = 0; i < set.length(); ++i)
			{
				Assert::AreEqual(set[i], set1[i]);
			}
		}

		TEST_METHOD(TestRemove)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			set.remove(8);
			Assert::AreEqual(set.length(), 3);
		}

		TEST_METHOD(TestLength)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			set.remove(8);
			set.remove(2);
			set.remove(1);
			set.remove(5);
			Assert::AreEqual(set.length(), 0);
		}

		TEST_METHOD(TestContains)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			set.remove(8);
			Assert::IsFalse(set.contains(8));
		}

		TEST_METHOD(TestUnionSet)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			MySet<int> set1;
			set1.add(15);
			set1.add(13);
			set1.add(0);
			set1.add(11);
			MySet<int> set2 = set1.unionSet(set);
			Assert::IsTrue(set2.contains(8));
			Assert::IsTrue(set2.contains(15));
		}

		TEST_METHOD(TestIntersection)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			MySet<int> set1;
			set1.add(15);
			set1.add(5);
			set1.add(8);
			set1.add(11);
			MySet<int> set2 = set1.intersection(set);
			Assert::IsTrue(set2.contains(5));
			Assert::IsTrue(set2.contains(8));
		}

		TEST_METHOD(TestDifference)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			MySet<int> set1;
			set1.add(15);
			set1.add(5);
			set1.add(8);
			set1.add(11);
			MySet<int> set2 = set1.difference(set);
			Assert::IsTrue(set2.contains(15));
			Assert::IsTrue(set2.contains(11));
		}

		TEST_METHOD(TestSymmetricDifference)
		{
			MySet<int> set;
			set.add(5);
			set.add(8);
			set.add(2);
			set.add(1);
			MySet<int> set1;
			set1.add(15);
			set1.add(5);
			set1.add(8);
			set1.add(11);
			MySet<int> set2 = set1.symmetricDifference(set);
			Assert::IsTrue(set2.contains(15));
			Assert::IsTrue(set2.contains(11));
			Assert::IsTrue(set2.contains(2));
			Assert::IsTrue(set2.contains(1));
		}
	};
}

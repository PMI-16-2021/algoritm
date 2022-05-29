#include "pch.h"
#include "CppUnitTest.h"
#include "../MySet/MySet.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnittestSet
{
	TEST_CLASS(UnittestSet)
	{
	public:
		
		TEST_METHOD(TestIn){
			MySet<int> myset;
			Assert::IsFalse(myset.in(1));
			myset.add(1);
			Assert::IsTrue(myset.in(1));
		}
		TEST_METHOD(TestAdd) {
			MySet<int> myset;
			myset.add(1);
			Assert::IsTrue(myset.in(1));
			myset.add(2);
			myset.add(3);
			Assert::AreEqual(3, myset.len());
		}
		TEST_METHOD(TestLen) {
			MySet<int> myset;
			myset.add(1);
			myset.add(2);
			myset.add(3);
			Assert::AreEqual(3, myset.len());
		}
		TEST_METHOD(TestRemove) {
			MySet<int> myset;
			myset.add(1);
			myset.add(2);
			myset.add(3);
			Assert::AreEqual(3, myset.len());
			myset.remove(2);
			Assert::AreEqual(2, myset.len());
		}
		TEST_METHOD(TestUnion) {
			MySet<int> myset1;
			myset1.add(1);
			myset1.add(2);
			myset1.add(3);

			MySet<int> myset2;
			myset2.add(7);
			myset2.add(4);
			myset2.add(6);

			MySet<int> myset3;
			myset3.add(1);
			myset3.add(2);
			myset3.add(3);
			myset3.add(7);
			myset3.add(4);
			myset3.add(6);

			MySet<int> unionS = myset1.unionSet(myset2);
			Assert::AreEqual(6, unionS.len());
			for (int i = 0; i < unionS.len(); ++i) {
				Assert::AreEqual(myset3[i], unionS[i]);
			}
		}
		TEST_METHOD(TestUnion2) {
			MySet<int> myset1;
			myset1.add(1);
			myset1.add(2);
			myset1.add(3);

			MySet<int> myset2;
			myset2.add(1);
			myset2.add(4);
			myset2.add(3);

			MySet<int> myset3;
			myset3.add(1);
			myset3.add(2);
			myset3.add(3);
			myset3.add(4);

			MySet<int> unionS = myset1.unionSet(myset2);
			Assert::AreEqual(4, unionS.len());
			for (int i = 0; i < unionS.len(); ++i) {
				Assert::AreEqual(myset3[i], unionS[i]);
			}
		}
		TEST_METHOD(TestDifference) {
			MySet<int> myset1;
			myset1.add(1);
			myset1.add(2);
			myset1.add(3);

			MySet<int> myset2;
			myset2.add(1);
			myset2.add(4);
			myset2.add(3);

			MySet<int> myset3;
			myset3.add(2);

			MySet<int> dif = myset1.differenceSet(myset2);
			Assert::AreEqual(1, dif.len());
			for (int i = 0; i < dif.len(); ++i) {
				Assert::AreEqual(myset3[i], dif[i]);
			}
		}
		TEST_METHOD(TestIntersection) {
			MySet<int> myset1;
			myset1.add(1);
			myset1.add(2);
			myset1.add(3);

			MySet<int> myset2;
			myset2.add(1);
			myset2.add(4);
			myset2.add(3);

			MySet<int> myset3;
			myset3.add(1);
			myset3.add(3);

			MySet<int> inter = myset1.intersectionSet(myset2);
			Assert::AreEqual(2, inter.len());
			for (int i = 0; i < inter.len(); ++i) {
				Assert::AreEqual(myset3[i], inter[i]);
			}
		}
		TEST_METHOD(TestSymmetric) {
			MySet<int> myset1;
			myset1.add(1);
			myset1.add(2);
			myset1.add(3);

			MySet<int> myset2;
			myset2.add(7);
			myset2.add(1);
			myset2.add(6);

			MySet<int> myset3;
			myset3.add(2);
			myset3.add(3);
			myset3.add(7);
			myset3.add(6);

			MySet<int> symmetric = myset1.symmetricDifferenceSet(myset2);
			Assert::AreEqual(4, symmetric.len());
			for (int i = 0; i < symmetric.len(); ++i) {
				Assert::AreEqual(myset3[i], symmetric[i]);
			}
		}
	};
}

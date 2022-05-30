#include "pch.h"
#include "CppUnitTest.h"
#include"../Lab08_Set/Set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestSet
{
	TEST_CLASS(UnitTestSet)
	{
	public:
		
		TEST_METHOD(Test_In)
		{
			Set S;
			S.Add(5);
			Assert::IsTrue(S.In(5));
			S.Remove(5);
			Assert::IsFalse(S.In(5));
		}
		TEST_METHOD(TestAdd)
		{
			Set S;
			Assert::IsFalse(S.In(1));
			S.Add(1);
			Assert::IsTrue(S.In(1));
			Assert::IsFalse(S.In(2));
			S.Add(2);
			Assert::IsTrue(S.In(1));
			Assert::IsTrue(S.In(2));
			Assert::AreEqual(2, S.Len());
			Assert::IsFalse(S.In(3));
			S.Add(3);
			Assert::IsTrue(S.In(1)); 
			Assert::IsTrue(S.In(2)); 
			Assert::IsTrue(S.In(3));
			Assert::AreEqual(3, S.Len());
		}
		TEST_METHOD(TestLen) 
		{
			
		}
		TEST_METHOD(TestRemove)
		{
			Set S;
			S.Add(4);
			Assert::IsTrue(S.In(4));
			S.Remove(4);
			Assert::IsFalse(S.In(4));
		}
		TEST_METHOD(Test_DifferenceSet)
		{
			Set S1;
			S1.Add(1);
			S1.Add(2);
			S1.Add(3);

			Set S2;
			S2.Add(1);
			S2.Add(4);
			S2.Add(3);

			Set S3;
			S3.Add(2);

			Set dif = S1.DifferenceSet(S2);
			Assert::AreEqual(1, dif.Len());
			for (int i = 0; i < dif.Len(); ++i)
				Assert::AreEqual(S3[i], dif[i]);

		}
		TEST_METHOD(Test_Union_Set)
		{
			Set S1;
			S1.Add(1);
			S1.Add(2);
			S1.Add(3);

			Set S2;
			S2.Add(4);
			S2.Add(5);
			S2.Add(6);

			Set US = S1.UnionSet(S2);
			Assert::AreEqual(6, US.Len());
		}
		TEST_METHOD(Test_Intersection)
		{
			Set S1;
			S1.Add(1);
			S1.Add(2);
			S1.Add(3);

			Set S2;
			S2.Add(1);
			S2.Add(4);
			S2.Add(5);

			Set S3;
			S3.Add(1);
			Set IntSet = S1.IntersectionSet(S2);
			Assert::AreEqual(S3.Len(), IntSet.Len());
			
		}
		TEST_METHOD(Test_Symmetric)
		{
			Set S1;
			S1.Add(1);
			S1.Add(2);
			S1.Add(3);

			Set S2;
			S2.Add(7);
			S2.Add(1);
			S2.Add(6);

			Set S3;
			S3.Add(2);
			S3.Add(3);
			S3.Add(7);
			S3.Add(6);

			Set SymSet = S1.SymmetricDifferenceSet(S2);
			Assert::AreEqual(4, SymSet.Len());
			for (int i = 0; i < SymSet.Len(); ++i)
				Assert::AreEqual(S3[i], SymSet[i]);
		}
	};
}

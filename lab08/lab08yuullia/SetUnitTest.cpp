#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project8/set.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SetUnitTest
{
	TEST_CLASS(SetUnitTest)
	{
	public:
		
		TEST_METHOD(AddTest)
		{
			Set S1;
			Assert::AreEqual(S1.len(), 0);
			S1.add(1);
			Assert::IsTrue(S1.in(1));
			Assert::AreEqual(S1.len(), 1);
			S1.add(1);
			Assert::AreEqual(S1.len(), 1);
			S1.add(2);
			Assert::IsTrue(S1.in(1));
			Assert::IsTrue(S1.in(2));
			Assert::AreEqual(S1.len(), 2);
		}
		
		TEST_METHOD(removeTest)
		{
			Set S1;
			S1.add(1);
			S1.add(2);
			Assert::IsTrue(S1.in(1));
			Assert::IsTrue(S1.in(2));
			Assert::AreEqual(S1.len(), 2);
			S1.remove(2);
			Assert::IsFalse(S1.in(2));
			Assert::IsTrue(S1.in(1));
			Assert::AreEqual(S1.len(), 1);
			S1.remove(1);
			Assert::IsFalse(S1.in(1));
			Assert::AreEqual(S1.len(), 0);
		}
		
		TEST_METHOD(inTest)
		{
			Set S1;
			S1.add(1);
			Assert::IsTrue(S1.in(1));
			Assert::IsFalse(S1.in(0));
		}
		
		TEST_METHOD(lenTest)
		{
			Set S1;
			Assert::AreEqual(S1.len(), 0);
			S1.add(1);
			S1.add(2);
			Assert::AreEqual(S1.len(), 2);
			S1.add(2);
			S1.add(3);
			Assert::AreEqual(S1.len(), 3);
		}
		
		TEST_METHOD(unionSTest)
		{
			Set S1;
			S1.add(1);
			S1.add(2);
			S1.add(3);
			Set S2;
			S2.add(3);
			S2.add(4);
			S2.add(5);
			Set S3 = S1.unionS(S2);
			int result[] = { 1, 2, 3, 4, 5 };
			for (int i = 0; i < 5; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
		
		TEST_METHOD(intersectionSTest)
		{
			Set S1;
			S1.add(1);
			S1.add(2);
			S1.add(3);
			Set S2;
			S2.add(3);
			S2.add(4);
			S2.add(5);
			Set S3 = S1.intersectionS(S2);
			int result[] = { 3 };
			for (int i = 0; i < 1; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
		
		TEST_METHOD(differenceSTest)
		{
			Set S1;
			S1.add(1);
			S1.add(2);
			S1.add(3);
			Set S2;
			S2.add(3);
			S2.add(4);
			S2.add(5);
			Set S3 = S1.differenceS(S2);
			int result[] = { 1, 2 };
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
		
		TEST_METHOD(symmetricDifferenceSTest)
		{
			Set S1;
			S1.add(1);
			S1.add(2);
			S1.add(3);
			Set S2;
			S2.add(3);
			S2.add(4);
			S2.add(5);
			Set S3 = S1.symmetricDifferenceS(S2);
			int result[] = { 1, 2, 4, 5 };
			for (int i = 0; i < 4; ++i) {
				Assert::AreEqual(S3[i], result[i]);
			}
		}
	};
}

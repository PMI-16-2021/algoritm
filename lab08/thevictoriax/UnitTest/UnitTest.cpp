#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab08/set.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Add)
		{
			Set S;
			S.add(3);
			Assert::IsTrue(S.in(3));
			S.add(7);
			Assert::IsTrue(S.in(7));
			S.add(1);
			Assert::IsTrue(S.in(1));
			Assert::AreEqual(S.len(), 3);
		}
		TEST_METHOD(Remove)
		{
			Set S;
			S.add(1);
			S.add(2);
			S.add(3);
			S.remove(1);
			Assert::AreEqual(S.len(), 2);
		}
		TEST_METHOD(Len)
		{
			Set S;
			S.add(5);
			Assert::AreEqual(S.len(), 1);
		}
		TEST_METHOD(In)
		{
			Set S;
			Assert::IsFalse(S.in(3));
			S.add(1);
			Assert::IsTrue(S.in(1));
		}
		TEST_METHOD(Union)
		{
			Set S;
			S.add('1');
			S.add('3');
			S.add('7');
			Set S2;
			S2.add('5');
			S2.add('4');
			S2.add('7');
			Set S3;
			S3 = S.unionSet(S2);
			
			char res[5] = { '1', '3', '7', '5', '4' };
			for (int i = 0; i < S3.len(); ++i)
			{
				Assert::AreEqual(S3[i], res[i]);
			}
		}
		TEST_METHOD(Intersection)
		{
			Set S;
			S.add('1');
			S.add('3');
			S.add('7');
			Set S2;
			S2.add('2');
			S2.add('1');
			S2.add('7');
			Set S3;
			S3 = S.intersection(S2);
			char res[2] = { '1', '7' };
			for (int i = 0; i < 2; ++i)
			{
				Assert::IsTrue(S3[i]==res[i]);
			}
		}
		TEST_METHOD(Difference)
		{
			Set S;
			S.add('1');
			S.add('3');
			S.add('7');
			Set S2;
			S2.add('2');
			S2.add('1');
			S2.add('7');
			Set S3;
			S3 = S.difference(S2);
			char res[1] = { '3' };
			for (int i = 0; i < 1; ++i)
			{
				Assert::AreEqual(S3[i], res[i]);
			}
		}
		TEST_METHOD(SymmetricDifference)
		{
			Set S;
			S.add('5');
			S.add('9');
			S.add('2');
			S.add('10');
			S.add('1');
			Set S2;
			S2.add('3');
			S2.add('5');
			S2.add('2');
			Set S3;
			S3 = S.symmetric_difference(S2);
			char res[4] = { '9', '10', '1', '3'};
			for (int i = 0; i < 2; ++i)
			{
				Assert::AreEqual(S3[i], res[i]);
			}
		}
	};
}
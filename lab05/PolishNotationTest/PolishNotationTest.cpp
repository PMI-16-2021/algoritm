#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/polishRecord.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolishNotationTest
{
	TEST_CLASS(PolishNotationTest)
	{
	public:
		
		TEST_METHOD(GetPriority_Test)
		{
			Assert::AreEqual((int)GetPriority("+"), 1);
			Assert::AreEqual((int)GetPriority("-"), 1); //size_t to int conversion
			Assert::AreEqual((int)GetPriority("("), 0);
			Assert::AreEqual((int)GetPriority("*"), 2);
			Assert::AreEqual((int)GetPriority("/"), 2);
			Assert::AreEqual((int)GetPriority("^"), 3);
			Assert::AreEqual((int)GetPriority(" "), -1);
		}

		TEST_METHOD(IsOperation_Test)
		{
			Assert::IsTrue(IsOperation("+"));
			Assert::IsTrue(IsOperation("-"));
			Assert::IsTrue(IsOperation("*"));
			Assert::IsTrue(IsOperation("/"));
			Assert::IsTrue(IsOperation("^"));
			Assert::IsFalse(IsOperation("_"));
		}

		TEST_METHOD(BalanceStr_Test)
		{
			Assert::IsTrue(BalanceStr(" (faf0)a"));
			Assert::IsTrue(BalanceStr(" ( 0 (faf ) (fa)afaf)"));
			Assert::IsFalse(BalanceStr(")hafhukf( faf"));
			Assert::IsFalse(BalanceStr("(hafhukf( )fafa )fafa ) faf"));
		}

		TEST_METHOD(PolishRecord_Test)
		{
			string check = "5_7_+_-0.5_*_";
			Assert::AreEqual(PolishRecord("( 5 + 7 ) * -0.5"), check);

			check = "-5.5_2_4_^_3.5_+_1.0_4.2_-_*_-_";
			Assert::AreEqual(PolishRecord("-5.5 - ( 2 ^ 4 + 3.5 ) * ( 1.0 - 4.2 )"), check);
			try
			{
				PolishRecord("");
				Assert::Fail;
			}
			catch (const BadBracketBalance& A )
			{
				A.report();
			}
		}

		TEST_METHOD(Calculate_Test)
		{
			double expected = 67.9;
			Assert::AreEqual(Calculate(PolishRecord("5.5 - ( 2 ^ 4 + 3.5 ) * ( 1.0 - 4.2 )")), expected);
			expected = 49;
			Assert::AreEqual(Calculate(PolishRecord("( 3.5 * -2 ) ^ 2")), expected);
		}
	};
}

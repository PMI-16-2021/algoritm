#include "pch.h"
#include "CppUnitTest.h"
#include "..\\lab10\tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(Height)
		{
			Tree T;
			Assert::IsFalse(T.find(1));
			T.insert(7);
			T.insert(10);
			Assert::IsTrue(T.find(7));
			Assert::IsTrue(T.find(10));
		}
		TEST_METHOD(Insert)
		{
			Tree T;
			Assert::AreEqual(-1, T.height());
			T.insert(3);
			Assert::AreEqual(0, T.height());
			T.insert(7);
			T.insert(1);
			Assert::AreEqual(1, T.height());
		}
		TEST_METHOD(Remove)
		{
			Tree T;
			Assert::IsFalse(T.find(1));
			T.insert(1);
			T.insert(3);
			T.insert(7);
			T.remove(3);
			Assert::IsFalse(T.find(3));
			T.remove(7);
			Assert::IsFalse(T.find(7));
		}
		TEST_METHOD(Find)
		{
			Tree T;
			T.insert(1);
			T.insert(3);
			T.insert(7);
			Assert::IsTrue(T.find(7));
			Assert::IsTrue(T.find(1));
			Assert::IsTrue(T.find(3));
			T.remove(1);
			Assert::IsFalse(T.find(1));
		}
	};
}

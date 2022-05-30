#include "pch.h"
#include "CppUnitTest.h"
#include "..\\tree\tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(InsertTest)
		{
			Tree<int> T;
			Assert::AreEqual(-1, T.getHeight());
			T.insert(4);
			Assert::AreEqual(0, T.getHeight());
			T.insert(14);
			T.insert(13);
			Assert::AreEqual(1, T.getHeight());
		}
		TEST_METHOD(TestMethodRemove)
		{
			Tree<int> T;
			T.insert(4);
			T.insert(14);
			T.insert(13);
			T.insert(3);
			Assert::AreEqual(2, T.getHeight());
			T.remove(3);
			T.remove(13);
			Assert::AreEqual(1, T.getHeight());
		}
		TEST_METHOD(TestMethodHeight)
		{
			Tree<int> T;
			Assert::AreEqual(-1, T.getHeight());
			T.insert(4);
			T.insert(14);
			T.insert(13);
			T.insert(3);
			T.insert(1);
			T.insert(7);
			T.insert(2);
			T.insert(8);
			Assert::AreEqual(3, T.getHeight());
		}
	};
}

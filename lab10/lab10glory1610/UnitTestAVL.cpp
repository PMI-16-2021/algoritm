#include "pch.h"
#include "CppUnitTest.h"
#include "..//AVLtree/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAVL
{
	TEST_CLASS(UnitTestAVL)
	{
	public:
		
		TEST_METHOD(TestMethodInsert)
		{
			AVL a;
			Assert::AreEqual(-1, a.height());
			a.insert(5);
			Assert::AreEqual(0, a.height());
			a.insert(12);
			a.insert(10);
			Assert::AreEqual(1, a.height());
		}
		TEST_METHOD(TestMethodRemove)
		{
			AVL l;
			l.insert(5);
			l.insert(10);
			l.insert(20);
			l.insert(34);
			l.insert(2);
			Assert::AreEqual(2, l.height());
			l.remove(5);
			l.remove(20);
			Assert::AreEqual(1, l.height());
		}
		TEST_METHOD(TestMethodHeight)
		{
			AVL v;
			Assert::AreEqual(-1, v.height());
			v.insert(45);
			v.insert(3);
			v.insert(67);
			v.insert(100);
			v.insert(2);
			Assert::AreEqual(2, v.height());
		}
	};
}

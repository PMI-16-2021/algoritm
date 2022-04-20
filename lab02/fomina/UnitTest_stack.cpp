#include "pch.h"
#include "CppUnitTest.h"
#include "../cтеки/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
Stack s(); 


namespace UnitTeststack
{
	TEST_CLASS(UnitTeststack)
	{
	public:
		
		TEST_METHOD(empty)
		{
			Stack s;
			s.push(7);
			s.push(2);
			s.push(5);
			s.push(4);
			Stack s1;
			Assert::IsTrue(s1.isEmpty());
			Assert::IsFalse(s.isEmpty());
		}
		TEST_METHOD(full)
		{
			Stack s;
			s.push(7);
			s.push(2);
			s.push(5);
			s.push(4);
			s.push(6);
			Stack s1;
			Assert::IsFalse(s1.isFull());
			Assert::IsTrue(s.isFull());


		}
		TEST_METHOD(push)
		{
			Stack s1;
			s1.push(7);
			s1.push(2);
			Assert::AreEqual(7, s1.sTop());
			Assert::AreEqual(2, s1.sLast());
		}
		TEST_METHOD(pop)
		{
			Stack s1;
			s1.push(7);
			s1.push(2);
			s1.push(5);
			s1.push(4);
			s1.pop();
			Assert::AreEqual(5, s1.sLast());
			s1.pop();
			Assert::AreEqual(2, s1.sLast());
		}
		TEST_METHOD(size)
		{
			Stack s1;
			s1.push(7);
			s1.push(2);
			s1.push(5);
			s1.push(4);
			Assert::AreEqual(4, s1.size());
			Stack s;
			Assert::AreEqual(0, s.size());
		}
		TEST_METHOD(swap)
		{
			Stack s1;
			s1.push(7);
			s1.push(2);
			s1.push(5);
			s1.push(4);
			Assert::AreEqual(4,s1.sLast());
			Stack s;
			s.push(1); 
			s.push(2);
			s.push(3);
			s1.swap(&s);
			Assert::AreEqual(3, s1.sLast());
		}
		TEST_METHOD(emplase)
		{
			Stack s1;
			s1.push(7);
			s1.push(2);
			s1.push(5);
			s1.push(4);
			s1.emplace(3, 1);
			Assert::AreEqual(3, s1.sTop());
			s1.pop();
			s1.emplace(12, 5);
			Assert::AreEqual(12, s1.sLast());
			s1.pop();
			s1.emplace(9, 3);
			s1.pop();
			s1.pop();
			Assert::AreEqual(9, s1.sLast());
		}
		TEST_METHOD(emptyy)
		{
			Stack s1;
			s1.push(7);
			s1.push(2);
			s1.push(5);
			s1.push(4);
			s1.empty();
			Assert::IsTrue(s1.isEmpty());
		}

	};
}

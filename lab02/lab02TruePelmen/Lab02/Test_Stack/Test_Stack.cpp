#include "pch.h"
#include "CppUnitTest.h"
#include"../Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestStack
{
	TEST_CLASS(TestStack)
	{
	public:
		
		TEST_METHOD(push_test)
		{
			Stack a;
			a.push(5);
			Assert::AreEqual(a.showtop(), 5);
		}
		TEST_METHOD(showtop_test)
		{
			Stack a;
			a.push(5);
			int b = a.showtop();
			Assert::AreEqual(b, 5);
		}
		TEST_METHOD(empty_test)
		{
			Stack a;
			int b = a.empty();
			Assert::AreEqual(b, 1);
		}
		TEST_METHOD(full_test)
		{
			Stack a;
			int b = a.full();
			a.push(5);
			a.push(3);
			a.push(6);
			a.push(8);
			a.push(1);
			a.push(5);
			a.push(8);
			a.push(9);
			a.push(3);
			a.push(2);
			Assert::AreEqual(b, 1);
		}
		TEST_METHOD(size_test)
		{
			Stack a;
			int b = a.size();
			Assert::AreEqual(b, 0);
			a.push(6);
			a.push(8);
			b = a.size();
			Assert::AreEqual(b, 2);
			a.push(1);
			a.push(5);
			a.push(8);
			a.push(9);
			b = a.size();
			Assert::AreEqual(b, 6);
		}
		TEST_METHOD(swap_test)
		{
			Stack a;
			a.push(5);
			a.push(3);
			a.push(6);
			a.push(8);
			a.push(1);
			a.push(5);
			a.push(8);
			a.push(9);
			a.push(3);
			a.push(2);
			int arr[Size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
			a.swap(arr);
			int b = a.showtop();
			Assert::AreEqual(b, 10);
		}
		TEST_METHOD(pop_test)
		{
			Stack a;
			a.push(3);
			a.push(5);
			int b = a.showtop();
			Assert::AreEqual(b, 5);
			a.pop();
			b = a.showtop();
			Assert::AreEqual(b, 3);
			a.pop();
			b = a.empty();
			Assert::AreEqual(b, 1);
		}
	};
}

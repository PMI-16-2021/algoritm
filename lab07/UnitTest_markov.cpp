#include "pch.h"
#include "CppUnitTest.h"
#include "..//маркова/markov.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestmarkov
{
	TEST_CLASS(UnitTestmarkov)
	{
	public:
		
		TEST_METHOD(search)
		{
			char* x = "asdf";
			Str x1(x);
			Assert::AreEqual(x1.search("s"), 1, L"1");
		}
		TEST_METHOD(searchPointer)
		{
			char* x = "asdf";
			Str x1(x);
			Assert::AreEqual(x1.search("sd"), 1, L"2");
		}
		TEST_METHOD(plus)
		{
			char* x = "asdf";
			Str x1(x);
			Str x2("asdf");
			Assert::AreEqual(x1 + x2, Str("asdfasdf"), L"3");
		}
		TEST_METHOD(in)
		{
			char* x = "asdf";
			Str x1(x);
			x1.in("g", 2);
			Assert::AreEqual(x1.search("g"), 2, L"1");
		}
		TEST_METHOD(del)
		{
			char* x = "asdf";
			Str x1(x);
			x1.del(1, 1);
			Assert::AreEqual(x1.search("s"), -1, L"1");
		}
	};
}

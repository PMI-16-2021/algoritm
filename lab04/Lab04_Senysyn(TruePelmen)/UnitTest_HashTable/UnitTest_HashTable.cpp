#include "pch.h"
#include "CppUnitTest.h"
#include"../Lab_04_HashTable/HashTable.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestHashTable
{
	TEST_CLASS(UnitTestHashTable)
	{
	public:
		
		TEST_METHOD(Test_add)
		{
			HashTable h;
			Assert::IsTrue(h.isEmpty());
			h.add("abc", 123);
			Assert::AreEqual(h.get("abc"), 123);
			Assert::IsFalse(h.isEmpty());
		}
		TEST_METHOD(Test_pop)
		{
			HashTable h;
			Assert::IsTrue(h.isEmpty());
			h.add("abc", 123);
			Assert::IsFalse(h.isEmpty());
			h.pop("abc");
			Assert::IsTrue(h.isEmpty());
		}
		TEST_METHOD(Test_get)
		{
			HashTable h;
			Assert::IsTrue(h.isEmpty());
			h.add("abc", 123);
			Assert::IsFalse(h.isEmpty());
			Assert::AreEqual(h.get("abc"), 123);
		}
		TEST_METHOD(Test_isEmpty)
		{
			HashTable h;
			Assert::IsTrue(h.isEmpty());
			h.add("abc", 123);
			Assert::IsFalse(h.isEmpty());
			h.pop("abc");
			Assert::IsTrue(h.isEmpty());
		}
		TEST_METHOD(Test_hash_function)
		{
			HashTable h;
			h.add("Abracadabra", 122);
			h.add("AZ", 321);
			Assert::AreEqual(1, h.hash_function("AZ"));
			Assert::AreEqual(0, h.hash_function("Abracadabra"));
		}
	};
}

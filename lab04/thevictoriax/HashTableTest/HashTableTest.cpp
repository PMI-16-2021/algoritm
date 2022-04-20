#include "pch.h"
#include "CppUnitTest.h"
#include "../lab04/hTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HashTableTest
{
	TEST_CLASS(HashTableTest)
	{
	public:
		
		TEST_METHOD(Add)
		{
			HashTable T;
			T.add("Sam", 7);
			T.add("Peter", 3);
			Assert::IsFalse(T.isEmpty());	
		}
		TEST_METHOD(Pop)
		{
			HashTable T;
			T.add("Sam", 7);
			T.pop("Sam");
			Assert::IsTrue(T.isEmpty());
		}
		TEST_METHOD(Get)
		{
			HashTable T;
			T.add("Sam", 7);
			Assert::AreEqual(7, T.get("Sam"));
		}
		TEST_METHOD(Hash)
		{
			HashTable T;
			T.add("Sam", 7);
			T.add("Peter", 3);
			Assert::AreEqual(1, T.hash("Sam"));
		}
	};
}

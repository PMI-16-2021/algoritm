#include "pch.h"
#include "CppUnitTest.h"
#include "../labb04/hashTable.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Add)
		{
			HashTable<int> H;
			H.add(7, "Jake");
			Assert::AreEqual(7, H.getElem("Jake"));
		}
		TEST_METHOD(IsEmpty)
		{
			HashTable<int> H;
			Assert::IsTrue(H.isEmpty());
			H.add(7, "Jake");
			Assert::IsFalse(H.isEmpty());
		}
		TEST_METHOD(Get)
		{
			HashTable<int> H;
			H.add(7, "Jake");
			Assert::AreEqual(7, H.getElem("Jake"));
		}
		TEST_METHOD(Pop)
		{
			HashTable<int> H;
			H.add(1, "Jake");
			H.pop("Jake");
			Assert::IsFalse(H.findElem("Jake"));
			Assert::IsTrue(H.isEmpty());
		}
	};
}
